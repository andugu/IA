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


(deffunction set_date (?type ?day)
    (bind ?array (find-all-instances ((?e PersonalExercice)) (eq ?type ?e:exercice_type)))
    (bind ?size (length$ ?array))
    (bind ?duration 0)
    (bind ?pos (+ 1(mod (random) ?size)))
    (while (<= ?duration 30 )
        (bind ?it (+ 1 (mod ?pos ?size)))
        (bind ?exercice (nth$ ?it ?array))
        ; calculate exercice duration based on the activity
        (bind ?currentDuration (send ?exercice get-duration))
        (bind ?duration (+ ?currentDuration ?duration))
        (send ?exercice put-day ?day)
        ; increment loop control variables
        (bind ?duration (+ ?currentDuration ?duration))
        (bind ?pos (+ 1(mod (random) ?size)))
    )
)

;; RULES

(defrule max_program_days "States the total days of the program"
    (user_created)
    ?user <- (object (is-a Person))
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
    (bind ?exercices (find-all-instances ((?exercice PersonalExercice))TRUE))
    (loop-for-count (?day 1 ?max_days) do
        (bind ?duration 0)
        (while (> 30 ?duration) do
            (bind ?rand (+ 1 (mod (random) (length$ ?exercices))))
            (bind ?exercice (nth$ ?rand ?exercices))
            (send ?exercice put-day ?day)
            (bind ?currentDuration (send ?exercice get-duration))
            (bind ?duration (+ ?duration ?currentDuration))
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
