;;***************************************
;;*           INPUT                     *
;;*                                     *
;;***************************************

(defmodule input_module
    (import MAIN ?ALL)
    (export ?ALL)
)

;; TEMPLATES

(deftemplate objectives
    (multislot types)
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

(deffunction ask_list ()
    (bind ?answer (readline))
    (str-explode ?answer); return a list of values
)

;; START INPUT RULE DEFINITION

(defrule create_user "rule that creates a user when the system start"
    (system_start)
    =>
    (make-instance user of Person
        (activity medium) ; defualt activity
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
)

(defrule problems_questions "rule that asks if the user has a certain condition or problem"
    (asked_basic_questions)
    ?user <- (object (is-a Person))
    ?problem <- (object (is-a Problem)) ;; MISSING REMOVE OBESITY FROM A PROBLEM => EAISER FORM ONTOLOGY
    =>
    (bind ?name (send ?problem get-instance_name))
    (bind ?answer (ask (str-cat "Tens " ?name)))
    (if (eq si ?answer) then (send ?user put-problems (send ?user get-problems) ?problem ))
    (printout t (send ?user get-problems) crlf)
)


;
(deffunction set_objectives (?obj)
    (if (member 1 ?obj) then (assert (balance)))
    (if (member 2 ?obj) then (assert (manteinance)))
    (if (member 3 ?obj) then (assert (musclegrowth)))
    (if (member 4 ?obj) then (assert (weightloss)))
)

(deffunction ask_objectives ()
    (printout t "Quins objectius t'agradaria aconseguir amb la rutina?[Escriu multiples valors, com a minim 1]" crlf)
    (printout t "1. Balance" crlf)
    (printout t "2. Manteinance" crlf)
    (printout t "3. MuscleGrowth" crlf)
    (printout t "4. WeightLoss" crlf)
    (bind ?objectives (ask_list))
    (set_objectives ?objectives)

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
    ; here max blood pressure is the systolic pressure, since medically it is higher
    ; here min blood pressure is the dyastolic pressure since medically it is lower
    (send ?user put-max_blood_pressure (ask "Introdueix la presió arterial sistólica[mm Hg]:"))
    (send ?user put-min_blood_pressure (ask "Introdueix la presió arterial diastólica[mm Hg]:"))
    (send ?user put-bpm                (ask "Introdueix beats per minute:"))
    (send ?user put-bmi                (/ ?weight (* ?height ?height))) ; abstract attribute
    (ask_objectives)
    (assert (asked_basic_questions))
)





;; MOVE TO NEXT MODULE
(defrule end_input_module
    (user_created)
    =>
    (printout t "Lectura de datos de entrada completada" crlf)
    (focus abstract_module)
)
