;;***************************************
;;*           INPUT                     *
;;*                                     *
;;***************************************


;; MESSAGE HANDLER DEFINITIONS
(defmessage-handler PersonalExercice print primary()
    (bind ?base ?self:base_exercice)
    (printout t "--------------------------------------------" crlf)
    (printout t "Exercici: " (send ?base get-instance_name) crlf)
    (printout t "Duració: "  ?self:duration " minuts " crlf)
    (send ?base print)
    (printout t "--------------------------------------------" crlf)
)

(defmessage-handler Exercice print primary()
    ; print nothing
)

(defmessage-handler WeightLoss print primary()
    (bind ?user (find-instance ((?p User)) TRUE))
    (bind ?type (send [user] get-activity))
    (if (eq low ?type) then (printout t "Previsió de calorias cremades: " ?self:calories_per_time_low crlf))
    (if (eq medium ?type) then (printout t "Previsió de calorias cremades: " ?self:calories_per_time_medium crlf))
    (if (eq high ?type) then (printout t "Previsió de calorias cremades: " ?self:calories_per_time_hard crlf))
)

(defmessage-handler MuscleGrowth print primary()
    (printout t "Series: " ?self:sets crlf)
    (bind ?user (find-instance ((?p User)) TRUE))
    (bind ?type (send [user] get-activity))
    (if (eq low ?type) then (printout t "Repetitions: " ?self:repetitions_low crlf))
    (if (eq medium ?type) then (printout t "Repetitions: " ?self:repetitions_medium crlf))
    (if (eq high ?type) then (printout t "Repetitions: " ?self:repetitions_high crlf))
)

(defmessage-handler PersonalExercice subclass primary()
    (send ?self:base_exercice subclass)
)

(defmessage-handler PersonalExercice bodyparts primary()
    (send ?self:base_exercice get-body_parts)
)

(defmessage-handler BodyBalance subclass primary()
    bodybalance
)

(defmessage-handler WeightLoss subclass primary()
    weightloss
)

(defmessage-handler MuscleGrowth subclass primary()
    musclegrowth
)

(defmodule output_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (import abstract_module ?ALL)
    (import solver_module ?ALL)
    (export ?ALL)
)

(deffunction has_type (?type ?exercices)
    (bind ?return FALSE)
    (progn$ (?e ?exercices)
        (bind ?t (send ?e subclass))
        (if (eq ?t ?type) then (bind ?return TRUE))
    )
    ?return
)

(deffunction has_body_part (?type ?exercices)
    (bind ?return FALSE)
    (progn$ (?e ?exercices)
        (bind ?parts (send ?e bodyparts))
        (progn$ (?b ?parts)
            (if (eq ?b ?type) then (bind ?return TRUE))
        )
    )
    ?return
)

(deffunction print_types (?exercices)
    (printout t "Els objectius del dia d'avui son:" crlf)
    (if (has_type bodybalance ?exercices) then (printout t "Bodybalance" crlf))
    (if (has_type musclegrowth ?exercices) then (printout t "MuscleGrowth" crlf))
    (if (has_type weightloss ?exercices) then (printout t "WeightLoss" crlf))
)

(deffunction print_bodyparts (?exercices)
    (printout t "En aquest dia es treballaran les seguents parts del cos:" crlf)
    (if (has_body_part Pectoral ?exercices) then (printout t "Pectoral" crlf))
    (if (has_body_part Abdominales ?exercices) then (printout t "Abdominales" crlf))
    (if (has_body_part Espalda ?exercices) then (printout t "Espalda" crlf))
    (if (has_body_part Hombros ?exercices) then (printout t "Hombros" crlf))
    (if (has_body_part Piernas ?exercices) then (printout t "Piernas" crlf))
    (if (has_body_part Brazos ?exercices) then (printout t "Brazos" crlf))
    (if (has_body_part Gluteos ?exercices) then (printout t "Gluteos" crlf))

)

; output solution module
(defrule print_exercices
    (user_created)
    (max_days ?max)
    =>
    (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice)) TRUE))
    (make-instance program of Program
        (exercices personal_exercices)
    )

    (loop-for-count (?day 1 ?max) do
        (printout t "============================================" crlf)
        (printout t "============================================" crlf)
        (printout t "DIA:" ?day crlf)
        (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice))(member ?day ?exercice:day)))
        (bind ?total_time 0)
        (progn$ (?e ?personal_exercices)
            (bind ?total_time (+ ?total_time (send ?e get-duration)))
        )
        (printout t "S'espera una durada de " ?total_time " minuts al programa d'avui" crlf)
        (print_types ?personal_exercices)
        (print_bodyparts ?personal_exercices)
        (printout t "============================================" crlf)
        (printout t "============================================" crlf)
        (progn$ (?e ?personal_exercices)
            (send ?e print)
        )

    )
)
