;;***************************************
;;*           ABSTRACT                  *
;;* This module creates all the abstract*
;;* attributes that can be deduced      *
;;***************************************


(defmodule abstract_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (export ?ALL)
)

; AUXILIAR FUNCTIONS

(deffunction get_activity_duration (?exercice ?activity)
    (bind ?minDuration (send ?exercice get-min_exercice_duration))
    (bind ?maxDuration (send ?exercice get-max_exercice_duration))
    (bind ?d 0)
    (if (eq ?activity low) then (bind ?d ?minDuration))
    (if (eq ?activity medium) then (bind ?d (/ (+ ?minDuration ?maxDuration) 2)))
    (if (eq ?activity high) then  (bind ?d ?maxDuration))
    ?d
)

(deffunction same_name (?element ?array)
    (bind ?return FALSE)
    (bind ?name (send ?element get-instance_name))
    (progn$ (?a ?array)
        (bind ?cmp (send ?a get-instance_name))
        (if (eq ?name ?cmp) then (bind ?return TRUE))
    )

    ?return
)


; RULE DEFINITION

(defrule tension_detector "This rule calculates what type of tension the User has"
    (user_created)
    ?user <- (object (is-a User))
    =>
    (bind ?min (send ?user get-min_blood_pressure)) ; greater 90
    (bind ?max (send ?user get-max_blood_pressure)) ; greater 114
    (if (< 90 ?min) then
        (printout t "El usuari té hipertensió" crlf)
        (bind ?problem (find-instance ((?p Diet)) (eq ?p:instance_name "Hipertension")))
        (bind ?last (+ 1 (length$ (send ?user get-problems))))
        (slot-insert$ ?user problems ?last ?problem)
    else (if (< 114 ?max) then
        (printout t "El usuari té hipertensió" crlf)
        (bind ?problem (find-instance ((?p Diet)) (eq ?p:instance_name "Hipertension")))
        (bind ?last (+ 1 (length$ (send ?user get-problems))))
        (slot-insert$ ?user problems ?last ?problem)
    )
    )
    ;

)

(defrule bmi_detector "This rule calcualtes if the User has a normal bmi"
    (user_created)
    ?user <- (object (is-a User))
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

(defrule is_normal "The user has a normal bmi"
    (normal_bmi)
    =>
    (printout t "El usuari té un index de masa corporal normal" crlf)
)

(defrule is_overweight "The User is overwight"
    (overweight)
    ?user <- (object (is-a User))
    =>
    (printout t "El usuari té sobrepres" crlf)
    (bind ?problem (find-instance ((?p Physical)) (eq ?p:instance_name "Sobrepreso")))
    (bind ?last (+ 1 (length$ (send ?user get-problems))))
    (slot-insert$ ?user problems ?last ?problem)
)

(defrule is_obese "The User is obese"
    (obese)
    ?user <- (object (is-a User))
    =>
    (printout t "El usuari té obesitat" crlf)
    (bind ?problem (find-instance ((?p Physical)) (eq ?p:instance_name "Obesidad")))
    (bind ?last (+ 1 (length$ (send ?user get-problems))))
    (slot-insert$ ?user problems ?last ?problem)

)

(defrule balance_rule "Rule to add balance exercices"
    (balance)
    ?user <- (object (is-a User))
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


(defrule musclegrowth_rule "Rule to add musclegrowth exercices"
    (musclegrowth)
    ?user <- (object (is-a User))
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
    ?user <- (object (is-a User))
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

(defrule filter_problems "Rule that filters the problems that benefit the user"
    (abstracted)
    (benefits)
    ?user <- (object (is-a User))
    ?problem <- (object (is-a Problem))
    (test (member ?problem (send ?user get-problems)))
    =>
    (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice))TRUE))
    (loop-for-count (?i 1 (length$ ?personal_exercices))
        ; for each exercice check if it harms the problem
        ; if it does => then remove it
        (bind ?current (nth$ ?i ?personal_exercices))
        (bind ?base (send ?current get-base_exercice))
        (bind ?benefits (send ?base get-benefits))
        (if (same_name ?problem ?benefits) then
            (printout t (send ?base get-instance_name) " beneficia "
                (send ?problem get-instance_name) crlf)
            (send ?current put-bonus TRUE)
        )

    )
)


(defrule filter_physical "Rule that filters the physical problems of the user"
    (abstracted)
    (problem)
    ?user <- (object (is-a User))
    ?problem <- (object (is-a Physical))
    (test (member ?problem (send ?user get-problems)))
    =>
    (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice))TRUE))
    (loop-for-count (?i 1 (length$ ?personal_exercices))
        ; for each exercice check if it harms the problem
        ; if it does => then remove it
        (bind ?current (nth$ ?i ?personal_exercices))
        (bind ?base (send ?current get-base_exercice))
        (bind ?harms (send ?base get-harms))
        (if (same_name ?problem ?harms) then
            (printout t "Es descarta " (send ?base get-instance_name) " por "
                (send ?problem get-instance_name) crlf)
            (send ?current delete)
        )

    )
)




(defrule habits_point_system "Rule that calculates the activiy of a User given its habits"
    (user_created)
    ?user <- (object (is-a User))
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
    (if (eq ?sum -1) then
        (send ?user put-activity low)
    )
    (if (eq ?sum 0) then
        (send ?user put-activity medium)
    )
    (if (eq ?sum 1) then
        (send ?user put-activity high)
        (if (send ?user get-fatigue) then (send ?user put-activity medium))
        (if (< 65(send ?user get-age)) then (send ?user put-activity medium))
    )
    (bind ?act (send ?user get-activity))
    (if (eq low ?act) then
        (printout t "Segons l'activitat del usuari s'han programat els exercicis amb una intesitat baixa" crlf)
    )
    (if (eq medium ?act) then
        (printout t "Segons l'activitat del usuari s'han programat els exercicis amb una intesitat mitjana" crlf)
    )
    (if (eq high ?act) then
        (printout t "Segons l'activitat del usuari s'han programat els exercicis amb una intesitat alta" crlf)
    )

)


;; MOVE TO NEXT MODULE
(defrule end_abstract_module
    (user_created)
    =>
    (printout t "Abstracción de datos completada" crlf)
    (focus solver_module)
)
