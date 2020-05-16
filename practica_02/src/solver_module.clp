;;**************************
;;* SOLUTION MODULE        *
;;**************************


(defmodule solver_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (import abstract_module ?ALL)
    (export ?ALL)
)

;; AUXILIAR FUNCTIONS

(deffunction get_cycle_exercices (?bonus ?neutral)
    (bind ?return ?bonus)
    (if (eq 0 (length$ ?bonus)) then (bind ?return ?neutral))
    ?return
)

;; RULES

(defrule max_program_days "States the total days of the program"
    (user_created)
    ?user <- (object (is-a User))
    =>
    ; assign max days based on activity level
    ; at least 4 days of exercice since we must
    ; be sure that all objectives are met
    ; worst case, the user requests the four objectives
    (bind ?activity (send ?user get-activity))
    (if (eq ?activity low) then (assert (max_days 3)))
    (if (eq ?activity medium) then (assert (max_days 5)))
    (if (eq ?activity high) then (assert (max_days 7)))

)



(defrule set_days "Sets a day for each exercice"
    (max_days ?max_days)
    =>
    (bind ?bonus_exercices (find-all-instances ((?exercice PersonalExercice)) ?exercice:bonus))
    (printout t "Se han encontrado un total de " (length$ ?bonus_exercices) " ejercicios con recomendacion alta" crlf)
    (bind ?neutral_exercices (find-all-instances ((?exercice PersonalExercice)) (not ?exercice:bonus)))
    (printout t "Se han encontrado un total de " (length$ ?neutral_exercices) " ejercicios con recomendacion neutral" crlf)
    (loop-for-count (?day 1 ?max_days) do
        (bind ?duration 0)
        (bind ?seen (create$ ))
        (while (> 30 ?duration) do
            ; this returns the set of exercices that is not empty
            (bind ?exercices (get_cycle_exercices ?bonus_exercices ?neutral_exercices))
            ; in case both  sets are empty, fill the sets again
            (if (eq 0 (length$ ?exercices)) then
                (bind ?bonus_exercices (find-all-instances ((?exercice PersonalExercice)) ?exercice:bonus))
                (bind ?neutral_exercices (find-all-instances ((?exercice PersonalExercice)) (not ?exercice:bonus)))
                (bind ?exercices (get_cycle_exercices ?bonus_exercices ?neutral_exercices))
            )
            ; select a random exercice and set its day
            (bind ?exercice (nth$ (+ 1 (mod (random) (length$ ?exercices))) ?exercices))
            (while (member ?exercice ?seen)
                (bind ?exercices (delete-member$ ?exercices ?exercice))
                (bind ?exercice (nth$ (+ 1 (mod (random) (length$ ?exercices))) ?exercices))
            )
            (send ?exercice put-day ?day (send ?exercice get-day))
            (bind ?currentDuration (send ?exercice get-duration))
            (bind ?duration (+ ?duration ?currentDuration))
            ; delete already seen instance
            (bind ?exercices (delete-member$ ?exercices ?exercice))
            (if (neq 0 (length$ ?bonus_exercices))
                then (bind ?bonus_exercices (delete-member$ ?bonus_exercices ?exercice))
                else (bind ?neutral_exercices (delete-member$ ?neutral_exercices ?exercice))
            )
            (bind ?seen (insert$ ?seen 1 ?exercice))
        )
    )
    (assert (day (+ 1 ?max_days)))
)


;; MOVE TO NEXT MODULE
(defrule end_solver_module
    (max_days ?max)
    (day ?d)
    (test (> ?d ?max))
    =>
    (printout t "Calculo de la solución completada" crlf)
    (focus output_module)
)
