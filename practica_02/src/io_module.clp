;;**************************
;;*     INPUT/OUTPUT       *
;;**************************


;; MESSAGE HANDLER DEFINITIONS 
(defmessage-handler PersonalExercice print primary()
    (bind ?base ?self:base_exercice)
    (printout t "===========================" crlf)
    (printout t "Exercici: " (send ?base get-instance_name) crlf)
    (printout t "Duració: "  ?self:duration crlf)
    (printout t "===========================" crlf)
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
    (while (neq no (bind ?habitName (read))) do ; name frequency duration \n
        (bind ?habitName (ask "Quina?"))
        (bind ?freq (ask "Quants cops a la setmana?"))
        (bind ?duration (ask "Amb quina duració?"))
        (make-instance ?habitName of Habit
            (instance_name ?habitName)
            (frequency ?freq)
            (duration ?duration)
            (activity high)
        )
        (printout t "Fas alguna altra?" crlf)
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
    (make-instance user of Person)
    (assert (user_created)) 
) 

(defrule habit_questions "rule that asks which habit the person has"
    (asked_basic_questions)
    ?user <- (object (is-a Person))
    => 
    (ask_habit ?user low "Tens habits sedentaris?[si/no]")
    (ask_habit ?user medium "Tens habits de activitat mitjana?[si/no]")
    (ask_habit ?user high "Tens habits de alta activitat?[si/no]")
    (assert (asked_all))
)

(defrule input_questions "rule that asks questions to the user"
    (user_created)
    ?user <- (object (is-a Person))
    =>
    (send ?user put-instance_name      (ask "Introdueix el nom:"))
    (send ?user put-age                (ask "Introdueix la edat:"))
    (send ?user put-weight             (ask "Introdueix el pes:"))
    (send ?user put-fatigue            (ask "Ara hauras de fer una prova de esforç. Et sents fatigat?"))
    (send ?user put-min_blood_pressure (ask "Introdueix la presió arterial minima:"))
    (send ?user put-max_blood_pressure (ask "Introdueix la presió arterial máxima:"))
    (send ?user put-bpm                (ask "Introdueix BPM:"))
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
        (printout t "Day:" ?day crlf)
        (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice))(eq ?day ?exercice:day)))
        (progn$ (?e ?personal_exercices)
            (send ?e print)
        )

    )
)






