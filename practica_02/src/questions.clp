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
    (printout t "T'has sentit fatigat en la prova d'esforç?" crlf)
    (bind ?fatigue (readline))
    (printout t "Introdueix presio arterial minima:" crlf)
    (bind ?minPA (readline))
    (printout t "Introudeix presio arterial maxima:" crlf) 
    (bind ?maxPA (readline))
    (printout t "Introdueix BPM:" crlf)
    (bind ?bpm (readline))
    
    
    (printout t "Fas alguna activitat sedentaria o de baixa intensitat?(per exemple ...)" crlf)
    (while (neq no (bind ?habitName (read))) do ; name frequency duration \n  
        (printout t "Quina?" crlf)
        (bind ?habitName (read))
        (printout t "Amb quina frequencia?" crlf)
        (bind ?freq (read))
        (printout t "Amb quina duracio?" crlf)
        (bind ?duration (read))
        (make-instance ?habitName of Habit
            (instance_name ?habitName)
            (frequency ?freq)
            (duration ?duration)  
            (activity low) 
        )
        (printout t "Fas alguna altre?" crlf)
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
