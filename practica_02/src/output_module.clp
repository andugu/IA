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
    (if (eq low ?type) then (printout t "Calorias quemadas: " ?self:calories_per_time_low crlf))
    (if (eq medium ?type) then (printout t "Calorias quemadas: " ?self:calories_per_time_medium crlf))
    (if (eq high ?type) then (printout t "Calorias quemadas: " ?self:calories_per_time_hard crlf))
)

(defmessage-handler MuscleGrowth print primary()
    (printout t "Series: " ?self:sets crlf)
    (bind ?user (find-instance ((?p User)) TRUE))
    (bind ?type (send [user] get-activity))
    (if (eq low ?type) then (printout t "Repetitions: " ?self:repetitions_low crlf))
    (if (eq medium ?type) then (printout t "Repetitions: " ?self:repetitions_medium crlf))
    (if (eq high ?type) then (printout t "Repetitions: " ?self:repetitions_high crlf))
)



(defmodule output_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (import abstract_module ?ALL)
    (import solver_module ?ALL)
    (export ?ALL)
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
        (printout t "Duració total del dia " ?total_time " minutos" crlf)
        (printout t "En aquest dia es treballara el " crlf)
        (printout t "============================================" crlf)
        (printout t "============================================" crlf)
        (progn$ (?e ?personal_exercices)
            (send ?e print)
        )

    )
)
