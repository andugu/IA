;;***************************************
;;*           INPUT/OUTPUT              *
;;* This module works in all the        *
;;* input/output operations to the user *
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
    (bind ?user (find-instance ((?p Person)) TRUE))
    (bind ?type (send [user] get-activity))
    (if (eq low ?type) then (printout t "Calorias per minut: " ?self:calories_per_time_low crlf))
    (if (eq medium ?type) then (printout t "Calorias per minut: " ?self:calories_per_time_medium crlf))
    (if (eq high ?type) then (printout t "Calorias per minut: " ?self:calories_per_time_hard crlf))
)

(defmessage-handler MuscleGrowth print primary()
    (printout t "Series: " ?self:sets crlf)
    (bind ?user (find-instance ((?p Person)) TRUE))
    (bind ?type (send [user] get-activity))
    (if (eq low ?type) then (printout t "Repetitions: " ?self:repetitions_low crlf))
    (if (eq medium ?type) then (printout t "Repetitions: " ?self:repetitions_medium crlf))
    (if (eq high ?type) then (printout t "Repetitions: " ?self:repetitions_high crlf))
)

;; AUXILIAR FUNCTION DEFINITIONS

;; Asks a question to the user
(deffunction ask (?question)
    (printout t ?question crlf)
    (bind ?answer (read))
    ?answer
)

(deffunction ask_habit (?user ?type ?question)
    (printout t ?question crlf)
    (bind ?counter 1)
    (while (neq no (bind ?habitName (read))) do ; name frequency duration \n
        (bind ?habitName (ask "Quina?"))
        (bind ?freq (ask "Quants cops a la setmana?"))
        (bind ?duration (ask "Amb quina duració?[minuts]"))
        (bind ?habit (make-instance ?habitName of Habit
            (instance_name ?habitName)
            (frequency ?freq)
            (duration ?duration)
            (activity ?type)
        ))
        (slot-insert$ ?user habits ?counter ?habit)
        (printout t "Fas alguna altra?" crlf)
        (bind ?counter (+ 1 ?counter))
    )
    ; (send ?user put-habits (all-instances HABIT))
)

;; START IO RULE DEFINITION

(defrule init "initial rule"
    (initial-fact); start on program run
    =>
    (printout t crlf)
    (printout t "==============================================" crlf)
    (printout t "   Coaching Potato Expert Routine Generator   " crlf)
    (printout t "==============================================" crlf)
    (printout t crlf)
    (assert (system_start)) ; tell the system that it needs to start
)

(defrule create_user "rule that creates a user when the system start"
    (system_start)
    =>
    (seed 1556)
    (make-instance user of Person
        (activity medium)
    )

    (assert (user_created))
)

(defrule habit_questions "rule that asks which habit the person has"
    (asked_basic_questions)
    ?user <- (object (is-a Person))
    =>
    (ask_habit ?user low "Tens habits sedentaris?[si/no] (e.g. Veure televisió, ordinador, seure al sofa, etc.)")
    (ask_habit ?user medium "Tens habits de activitat mitjana?[si/no] (e.g. Sortir a passejar, fer estiraments, fregar)")
    (ask_habit ?user high "Tens habits de alta activitat?[si/no] (e.g. Anar a corra, natació, tenis)")
    (assert (asked_all))
)

(defrule input_questions "rule that asks questions to the user"
    (user_created)
    ?user <- (object (is-a Person))
    =>
    (send ?user put-instance_name      (ask "Introdueix el nom:"))
    (send ?user put-age                (ask "Introdueix la edat:"))
    (bind ?weight                      (ask "Introdueix el pes [kg]:"))
    (bind ?height                      (ask "Introdueix altura [m]:"))
    (send ?user put-weight             ?weight)
    (send ?user put-height             ?height)
    (send ?user put-fatigue            (ask "Ara hauras de fer una prova de esforç. Et sents fatigat?"))
    (send ?user put-min_blood_pressure (ask "Introdueix la presió arterial minima:"))
    (send ?user put-max_blood_pressure (ask "Introdueix la presió arterial máxima:"))
    (send ?user put-bpm                (ask "Introdueix beats per minute:"))
    (send ?user put-bmi                (/ ?weight (* ?height ?height))) ; abstract attribue
    (bind ?objectives                  (ask "Quins objectius t'agradaria aconseguir amb la rutina?[Balance/Manteinance/MuscleGrowth/WeightLoss/]"))
    (assert (asked_basic_questions))
)


; output solution module
(defrule print_exercices
    (solution_calculated)
    =>
    (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice)) TRUE))
    (make-instance program of Program
        (exercices personal_exercices)
    )

    (loop-for-count (?day 1 7) do
        (printout t "============================================" crlf)
        (printout t "============================================" crlf)
        (printout t "DIA:" ?day crlf)
        (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice))(eq ?day ?exercice:day)))
        (bind ?total_time 0)
        (progn$ (?e ?personal_exercices)
            (bind ?total_time (+ ?total_time (send ?e get-duration)))
        )
        (printout t "Duració total del dia " ?total_time " minutos" crlf)
        (printout t "En aquest dia es treballara el BodyBalance" crlf)
        (printout t "============================================" crlf)
        (printout t "============================================" crlf)
        (progn$ (?e ?personal_exercices)
            (send ?e print)
        )

    )
)
