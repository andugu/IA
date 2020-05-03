;;**************************
;;* SOLUTION MODULE        *
;;**************************

(defrule calculate_solution "Rule that calculates the best solution"
    (asked_all)
    ?user <- (object (is-a Person))
    =>
    (bind ?exercices (find-all-instances ((?exercice Exercice))TRUE))
    (bind ?activity (send ?user get-activity))
    (bind ?count 0)
    (loop-for-count (?day 1 7) do
        (bind ?duration 0)
        (while (> 30 ?duration) do
            (bind ?rand (+ 1 (mod (random) (length$ ?exercices))))
            (bind ?exercice (nth$ ?rand ?exercices))
            (bind ?minDuration (send ?exercice get-min_exercice_duration))
            (bind ?maxDuration (send ?exercice get-max_exercice_duration))
            (if (eq ?activity low) then (bind ?currentDuration ?minDuration))
            (if (eq ?activity medium) then (bind ?currentDuration (/ (+ ?minDuration ?maxDuration) 2)))
            (if (eq ?activity high) then (bind ?currentDuration ?maxDuration))


            (make-instance (gensym*) of PersonalExercice
                (day ?day)
                (dificulty ?activity)
                (base_exercice ?exercice)
                (duration ?currentDuration)
            )
            (bind ?count (+ ?count 1))
            (bind ?duration (+ ?duration ?currentDuration))
        )
    )
    (assert (solution_calculated))

)
