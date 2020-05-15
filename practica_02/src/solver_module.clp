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
    (if (eq ?activity low) then (assert (max_days 4)))
    (if (eq ?activity medium) then (assert (max_days 5)))
    (if (eq ?activity high) then (assert (max_days 7)))

)



(defrule set_days "Sets a day for each exercice"
    (max_days ?max_days)
    =>
    (loop-for-count (?day 1 ?max_days) do
        (bind ?duration 0)
        (bind ?exercices (find-all-instances ((?exercice PersonalExercice))TRUE))
        (while (> 30 ?duration) do
            (bind ?rand (+ 1 (mod (random) (length$ ?exercices))))
            (bind ?exercice (nth$ ?rand ?exercices))
            (send ?exercice put-day ?day (send ?exercice get-day))
            (bind ?currentDuration (send ?exercice get-duration))
            (bind ?duration (+ ?duration ?currentDuration))
            (bind ?exercices (delete-member$ ?exercices ?exercice))
            (printout t "Exercices: " ?exercice crlf)
            (printout t "Duration: " ?duration crlf)
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
