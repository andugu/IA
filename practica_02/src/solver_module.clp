;;**************************
;;* SOLUTION MODULE        *
;;**************************


(defmodule solver_module
    (import MAIN ?ALL)
    (import input_module ?ALL)
    (import abstract_module ?ALL)
    (export ?ALL)
)

;; AUXILIAR FUNCTIONS


(deffunction set_date (?array ?pos ?day)
    (bind ?size (length$ ?array))
    (bind ?duration 0)
    (while (> ?duration 30 )
        (bind ?it (+ 1 (mod ?pos ?size)))
        (bind ?exercice (nth$ ?it ?array))
        ; calculate exercice duration based on the activity
        (bind ?currentDuration (send ?exercice get-duration))
        (bind ?duration (+ ?currentDuration ?duration))
        (send ?exercice set-day ?day)
        ; increment loop control variables
        (bind ?duration (+ ?currentDuration ?duration))
        (bind ?pos (+ 1 ?pos))
    )
    ?pos ; return new pos
)

;; RULES

(defrule max_program_days "States the total days of the program"
    (user_created)
    ?user <- (object (is-a Person))
    =>
    ; assign max days based on activity level
    ; at least 4 days of exercice since we must
    ; be sure that all objectives are met
    ; worst case, the user requests the four objectives
    (bind ?activity (send ?user get-activity))
    (if (eq ?activity low) then (assert (max_days 4)))
    (if (eq ?activity medium) then (assert (max_days 5)))
    (if (eq ?activity high) then (assert (max_days 7)))
    ; set initial day
    (assert (day 1))
    ; set initial exercice for the array of exercices
    (assert (bodybalance_pos 1))
    (assert (weightloss_pos 1))
    (assert (manteinance_pos 1))
    (assert (musclegrowth_pos 1))
)

(defrule add_balance_exercices "If there are bodybalance exercices set their date"
    (bodybalance)
    (max_days ?max)
    (day ?d)
    (test (> ?d ?max)) ; only enter if we are missing days
    (bodybalance_pos ?pos) ; save current exercice
    =>
    ; retract and assert to
    ; be able to enter this rule again
    (retract bodybalance)
    (assert (bodybalance))
    ; get body balance exercices
    (bind ?array (find-all-instances ((?e PersonalExercice)) (eq bodybalance ?e:exercice_type)))
    ; set the date of the exercices
    (retract bodybalance_pos)
    (assert (bodybalance_pos (set_date ?array ?pos ?d)))
    ; increase days
    (retract day)
    (assert (day (+ 1 ?d)))
)

(defrule add_manteinance_exercices "If there are bodybalance exercices set their date"
    (manteinance)
    (max_days ?max)
    (day ?d)
    (test (> ?d ?max)) ; only enter if we are missing days
    (manteinance_pos ?pos) ; save current exercice
    =>
    ; retract and assert to
    ; be able to enter this rule again
    (retract manteinance)
    (assert (manteinance))
    ; get body balance exercices
    (bind ?array (find-all-instances ((?e PersonalExercice)) (eq manteinance ?e:exercice_type)))
    ; set the date of the exercices
    (retract manteinance_pos)
    (assert (manteinance_pos (set_date ?array ?pos ?d)))
    ; increase days
    (retract day )
    (assert (day (+ 1 ?d)))
)

(defrule add_musclegrowth_exercices "If there are bodybalance exercices set their date"
    (musclegrowth)
    (max_days ?max)
    (day ?d)
    (test (> ?d ?max)) ; only enter if we are missing days
    (musclegrowth_pos ?pos) ; save current exercice
    =>
    ; retract and assert to
    ; be able to enter this rule again
    (retract musclegrowth)
    (assert (musclegrowth))
    ; get body balance exercices
    (bind ?array (find-all-instances ((?e PersonalExercice)) (eq musclegrowth ?e:exercice_type)))
    ; set the date of the exercices
    (retract musclegrowth_pos)
    (assert (musclegrowth_pos (set_date ?array ?pos ?d)))
    ; increase days
    (retract day)
    (assert (day (+ 1 ?d)))
)

(defrule add_weightloss_exercices "If there are bodybalance exercices set their date"
    (weightloss)
    (max_days ?max)
    (day ?d)
    (test (> ?d ?max)) ; only enter if we are missing days
    (weightloss_pos ?pos) ; save current exercice
    =>
    ; retract and assert to
    ; be able to enter this rule again
    (retract weightloss)
    (assert (weightloss))
    ; get body balance exercices
    (bind ?array (find-all-instances ((?e PersonalExercice)) (eq weightloss ?e:exercice_type)))
    ; set the date of the exercices
    (retract weightloss_pos)
    (assert (weightloss_pos (set_date ?array ?pos ?d)))
    ; increase days
    (retract day)
    (assert (day (+ 1 ?d)))
)


;; MOVE TO NEXT MODULE
(defrule end_solver_module
    (user_created)
    =>
    (printout t "Calculo de la solución completada" crlf)
    (focus output_module)
)
