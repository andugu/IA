;;**************************
;;* SOLUTION MODULE        *
;;**************************


(defmodule solver_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (import abstract_module ?ALL)
    (export ?ALL)
)

(defrule define_days "Define days for each personal exercice"
    (user_created)
    ?user <- (object (is-a Person))
    =>
    ; assign max days based on activity level
    (bind ?activity (send ?user get-activity))
    (if (eq ?activity low) then (bind ?max_days 3))
    (if (eq ?activity medium) then (bind ?max_days 5))
    (if (eq ?activity high) then (bind ?max_days 7))

    ; get exercices into different lists
    (bind ?bodybalance (find-all-instances ((?e PersonalExercice)) (eq bodybalance ?e:exercice_type)))
    (bind ?weightloss (find-all-instances ((?e PersonalExercice)) (eq weightloss ?e:exercice_type)))
    (bind ?manteinance (find-all-instances ((?e PersonalExercice)) (eq manteinance ?e:exercice_type)))
    (bind ?musclegrowth (find-all-instances ((?e PersonalExercice)) (eq musclegrowth ?e:exercice_type)))
    (bind ?exercices (create$ ))
    ; add exercices
    (if (neq 0 (length$ ?bodybalance)) then (bind ?exercices (insert$ ?exercices 1 ?bodybalance)))
    (if (neq 0 (length$ ?weightloss)) then (bind ?exercices (insert$ ?exercices 1 ?weightloss)))
    (if (neq 0 (length$ ?manteinance)) then (bind ?exercices (insert$ ?exercices 1 ?manteinance)))
    (if (neq 0 (length$ ?musclegrowth)) then (bind ?exercices (insert$ ?exercices 1 ?musclegrowth)))
    (printout t ?exercices crlf)
    (loop-for-count (?i 1 ?max_days) do
        (bind ?pos (+ 1 (mod ?i (length$ ?exercices))))
        (progn$ (?e (nth$ ?pos ?exercices))
            (send ?e put-day ?i)
        )

    )

)

;; MOVE TO NEXT MODULE
(defrule end_solver_module
    (user_created)
    =>
    (printout t "Calculo de la solución completada" crlf)
    (focus output_module)
)
