;;***************************************
;;*           ABSTRACT                  *
;;* This module creates all the abstract*
;;* attributes that can be deduced      *
;;***************************************


; AUXILIAR FUNCTIONS

(deffunction get_activity_duration (?exercice ?activity)
    (bind ?minDuration (send ?exercice get-min_exercice_duration))
    (bind ?maxDuration (send ?exercice get-max_exercice_duration))
    (if (eq ?activity low) then ?minDuration)
    (if (eq ?activity medium) then (/ (+ ?minDuration ?maxDuration) 2))
    (if (eq ?activity high) then  ?maxDuration)
)

; RULE DEFINITION

(defrule bmi_detector "This rule calcualtes if the person has a normal bmi"
    (asked_basic_questions)
    ?user <- (object (is-a Person))
    =>
    (bind ?bmi (send ?user get-bmi))
    (if (>= 24.9 ?bmi) then
        (assert (normal_bmi))
     else (
         if (>= 30 ?bmi) then (assert (overweight))
            else (assert (obese))
         )
    )

)


(defrule is_overweight "The person is overwight"
    (overwight)
    ?user <- (object (is-a Person))
    =>
    (bind ?problem (find-instance ((?p Physical)) (eq ?p:instance_name "Sobrepreso")))
    (bind ?last (+ 1 (length$ (send ?user get-problems))))
    (slot-insert$ ?user problems ?last ?problem)
)

(defrule is_obese "The person is obese"
    (obese)
    ?user <- (object (is-a Person))
    =>
    (bind ?problem (find-instance ((?p Physical)) (eq ?p:instance_name "Obesidad")))
    (bind ?last (+ 1 (length$ (send ?user get-problems))))
    (slot-insert$ ?user problems ?last ?problem)

)

(defrule balance_rule "Rule to add balance exercices"
    (balance)
    ?user <- (object (is-a Person))
    =>
    (bind ?exercices (find-all-instances ((?exercice BodyBalance))TRUE))
    (bind ?activity (send ?user get-activity))

    (progn$ (?e ?exercices); for loop
        (bind ?duration (get_activity_duration ?e ?activity))
        (make-instance (gensym*) of PersonalExercice
            (exercice_type bodybalance)
            (dificulty ?activity)
            (base_exercice ?e)
            (duration ?duration)
        )
    )
    (assert (abstracted))

)

(defrule manteinance_rule "Rule to add manteinance exercices"
    (manteinance)
    ?user <- (object (is-a Person))
    =>
    (bind ?exercices (find-all-instances ((?exercice Manteinance))TRUE))
    (bind ?activity (send ?user get-activity))

    (progn$ (?e ?exercices); for loop
        (bind ?duration (get_activity_duration ?e ?activity))
        (make-instance (gensym*) of PersonalExercice
            (exercice_type manteinance)
            (dificulty ?activity)
            (base_exercice ?e)
            (duration ?duration)
        )
    )
    (assert (abstracted))
)

(defrule musclegrowth_rule "Rule to add musclegrowth exercices"
    (musclegrowth)
    ?user <- (object (is-a Person))
    =>
    (bind ?exercices (find-all-instances ((?exercice MuscleGrowth))TRUE))
    (bind ?activity (send ?user get-activity))

    (progn$ (?e ?exercices); for loop
        (bind ?duration (get_activity_duration ?e ?activity))
        (make-instance (gensym*) of PersonalExercice
            (exercice_type musclegrowth)
            (dificulty ?activity)
            (base_exercice ?e)
            (duration ?duration)
        )
    )
    (assert (abstracted))

)

(defrule weightloss_rule "Rule to add weightloss exercices"
    (weightloss)
    ?user <- (object (is-a Person))
    =>
    (bind ?exercices (find-all-instances ((?exercice WeightLoss))TRUE))
    (bind ?activity (send ?user get-activity))

    (progn$ (?e ?exercices); for loop
        (bind ?duration (get_activity_duration ?e ?activity))
        (make-instance (gensym*) of PersonalExercice
            (exercice_type weightloss)
            (dificulty ?activity)
            (base_exercice ?e)
            (duration ?duration)
        )
    )
    (assert (abstracted))
)

;(defrule mal_esquena ""
;    (mal_esquena)
;    =>
;    (find-instances exercies que tengan probnlema espalda() )
;)


(defrule habits_point_system "Rule that calculates the activiy of a person given its habits"
    (asked_all)
    ?user <- (object (is-a Person))
    (test (neq 0 (length$ (send ?user get-habits))))
    =>
    (bind ?habits (send ?user get-habits))
    (bind ?size (length$ ?habits))
    (bind ?sum 0)
    (bind ?time 0)
    (progn$ (?h ?habits)
        (bind ?multiplication (* (send ?h get-duration) (send ?h get-frequency)))
        (if (eq low (send ?h get-activity)) then
            (bind ?sum (- ?sum ?multiplication))
        )
        (if (eq high (send ?h get-activity)) then
            (bind ?sum (+ ?sum ?multiplication))
        )
        (bind ?time (+ ?time ?multiplication))
    )
    (bind ?sum (/ ?sum ?time))
    (bind ?sum (round ?sum)) ; TODO -> round of medium has a bigger interval
    (if (eq ?sum -1) then (send ?user put-activity low))
    (if (eq ?sum 0) then (send ?user put-activity medium))
    (if (eq ?sum 1) then (send ?user put-activity high))

)
