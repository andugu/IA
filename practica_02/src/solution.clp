;;**************************
;;* SOLUTION MODULE        *
;;**************************





(deffunction functionFinal "Funcio final"
    ()

    (bind ?exercices (find-all-instances ((?exercice Exercice))TRUE))

    (bind ?count 0)
    (loop-for-count (?day 1 7) do
        (bind ?duration 0)
        (while (> 30 ?duration) do
            (bind ?rand (+ 1 (mod (random) (length$ ?exercices))))
            (bind ?exercice (nth$ ?rand ?exercices))
            (bind ?minDuration (send ?exercice get-min_exercice_duration))
            (bind ?maxDuration (send ?exercice get-max_exercice_duration))
            (bind ?currentDuration (/ (+ ?minDuration ?maxDuration) 2))

            (make-instance (gensym*) of PersonalExercice
                (day ?day)
                (dificulty medium)
                (base_exercice ?exercice)
                (duration ?currentDuration)
            )
            (bind ?count (+ ?count 1))
            (bind ?duration (+ ?duration ?currentDuration))
        )
    )

    (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice)) TRUE))
    (make-instance program of Program
        (exercices personal_exercices)
    )
    (loop-for-count (?day 1 7) do
        (printout t "Day:" ?day crlf)
        (bind ?personal_exercices (find-all-instances ((?exercice PersonalExercice))(eq ?day ?exercice:day)))
        (progn$ (?e ?personal_exercices)
            (printout t
                (send (send ?e get-base_exercice) get-instance_name) " " ; name
                (send ?e get-duration) " minuts"
            crlf)
        )

    )

)
