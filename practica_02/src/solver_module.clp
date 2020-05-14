;;**************************
;;* SOLUTION MODULE        *
;;**************************


(defmodule solver_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (import abstract_module ?ALL)
    (export ?ALL)
)

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
    ; set initial day
    (assert (day 1))
)

(defrule )

(defrule define_days "Define days for each personal exercice"
    (user_created)
    (day 4)
    ?user <- (object (is-a Person))
    =>

    ; get exercices into different lists
    (bind ?bodybalance (find-all-instances ((?e PersonalExercice)) (eq bodybalance ?e:exercice_type)))
    (bind ?weightloss (find-all-instances ((?e PersonalExercice)) (eq weightloss ?e:exercice_type)))
    (bind ?manteinance (find-all-instances ((?e PersonalExercice)) (eq manteinance ?e:exercice_type)))
    (bind ?musclegrowth (find-all-instances ((?e PersonalExercice)) (eq musclegrowth ?e:exercice_type)))
    ; saves the instances of exercices sequentially
    (bind ?exercices (create$ ))
    ; for each exercice type, we save the lengths
    (bind ?sizes (create$ (length$ ?bodybalance)
                          (length$ ?weightloss)
                          (length$ ?manteinance)
                          (length$ ?musclegrowth)))
    ; for each exercice type we save its position
    ; this way we avoid repeating exercices as much as
    ; possible, we want them to be varied
    (bind ?iterators (create$ 0 0 0 0))
    ; add exercices to array, reversed, because they are
    ; added at the beginning
    (bind ?exercices (insert$ ?exercices 1 ?weightloss))
    (bind ?exercices (insert$ ?exercices 1 ?musclegrowth))
    (bind ?exercices (insert$ ?exercices 1 ?manteinance))
    (bind ?exercices (insert$ ?exercices 1 ?bodybalance))
    (printout t ?exercices crlf) ; DEBUG
    ; for each day we assign exercices compatible with that day
    ; each day only a specific type of exercice can be done
    (loop-for-count (?i 1 ?max_days) do
        (printout t "Current day: " ?i crlf)
        ; first we select the type of exercice
        (bind ?current_type (+ 1 (mod ?i 4)))
        ; initialize day duration
        (bind ?duration 0)
        ; while the minimum time of 30 minuts is not met, we
        ; continue to add exercices
        (while (> ?duration 30 )
            (bind ?minDuration (send ?exercice get-min_exercice_duration))
            (bind ?maxDuration (send ?exercice get-max_exercice_duration))
            (if (eq ?activity low) then (bind ?currentDuration ?minDuration))
            (if (eq ?activity medium) then (bind ?currentDuration (/ (+ ?minDuration ?maxDuration) 2)))
            (if (eq ?activity high) then (bind ?currentDuration ?maxDuration))
        )
        (printout t "Current exercices" (nth$ ?pos ?exercices) crlf)
        (send (nth$ ?pos ?exercices) put-day ?i)

    )

)

;; MOVE TO NEXT MODULE
(defrule end_solver_module
    (user_created)
    =>
    (printout t "Calculo de la solución completada" crlf)
    (focus output_module)
)
