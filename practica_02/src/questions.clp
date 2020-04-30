;;**************************
;;* QUESTION ASKER MODULE  *
;;**************************


(deffunction init "Funcio inicial" 
    ()  
    (printout t "Introdueix el nom:" crlf)
    (bind ?name   (readline))
    (printout t "Introdueix la edat:" crlf)
    (bind ?age    (readline)) 
    (printout t "Introdueix el pes:" crlf)
    (bind ?weight (readline))
    (printout t ?name crlf) 
    (printout t "T'has sentit fatigat en la prova d'esforç?"
    (bind ?fatigue (readline))
    (printout t "Introdueix presio arterial minima:")
    (bind ?minPA (readline))
    (printout t "Introudeix presio arterial maxima:") 
    (bind ?maxPA (readline))
    (printout t "Introdueix BPM:" 
    (bind ?bpm (readline))
    
    
    (printout t "Fas alguna activitat sedentaria o de baixa intensitat?(per exemple ...)" crlf)
    (while (bind ?habitName (read)) ~"" do ; name frequency duration \n  
        (bind ?freq (read))
        (bind ?duration (read))
        (make-instance ?habitName of Habit
            (instance_name ?habitName)
            (frequency ?freq)
            (duration ?duration)  
            (activity low) 
        )
    ) 
    


    (make-instance user of Person 
        (instance_name ?name) 
        (age ?age)
        (weight ?weight) 
        (fatigue ?fatigue) 
        (min_blood_pressure ?minPA)
        (max_blood_pressure ?maxPA)  
        (bpm ?bpm)
    ) 
) 
