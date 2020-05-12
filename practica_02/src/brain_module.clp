;;**************************
;;* SOLUTION MODULE        *
;;**************************




(defrule define_days "Define days for each personal exercice"
    (abstracted)
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
    (if (neq 0 (length$ ?bodybalance)) then (insert$ ?exercices (+ 1 (length$ ?exercices)) ?bodybalance))
    (if (neq 0 (length$ ?weightloss)) then (insert$ ?exercices (+ 1 (length$ ?exercices)) ?weightloss))
    (if (neq 0 (length$ ?manteinance)) then (insert$ ?exercices (+ 1 (length$ ?exercices)) ?manteinance))
    (if (neq 0 (length$ ?musclegrowth)) then (insert$ ?exercices (+ 1 (length$ ?exercices)) ?musclegrowth))
    (printout t ?bodybalance crlf)
    (printout t ?weightloss crlf)
    (printout t ?manteinance crlf)
    (printout t ?musclegrowth crlf)
    (loop-for-count (?i 1 ?max_days) do
        (bind ?pos (+ 1 (mod ?i (length$ ?exercices))))
        (progn$ (?e (nth$ ?pos ?exercices))
            (send ?e put-day ?i)
        )

    )
    (assert (solution_calculated))

)
