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
    (make-instance user of Person 
        (instance_name ?name) 
        (age ?age)
        (weight ?weight) 
    ) 
) 
