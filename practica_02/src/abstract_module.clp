;;***************************************
;;*           ABSTRACT                  *
;;* This module creates all the abstract*
;;* attributes that can be deduced      *
;;***************************************


; RULE DEFINITION

(defrule bmi_detector "This rule calcualtes if the person has a normal bmi"
    (asked_basic_questions)
    ?user <- (object (is-a Person))
    =>
    (bind ?bmi (send ?user get-bmi))
    (if (< 24.9 ?bmi) then
        (assert (normal_bmi))
     else (
         if (< 30 ?bmi) then (assert (overweight))
            else (assert (obese))
         )
    )

)


(defrule is_overweight "The person is overwight"
    (overwight)
    ?user <- (object (is-a Person))
    =>
    (bind ?problem (find-instance ((?p Physical)) (eq ?p:instance_name "Sobrepreso")))
    (bind ?last (length$ (send ?user get-problems)))
    (slot-insert$ ?user problems ?last ?problem)
)

(defrule is_obese "The person is obewse"
    (obese)
    ?user <- (object (is-a Person))
    =>
    (bind ?problem (find-instance ((?p Physical)) (eq ?p:instance_name "Obesidad")))
    (bind ?last (length$ (send ?user get-problems)))
    (slot-insert$ ?user problems ?last ?problem)

)
