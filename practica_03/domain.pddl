;; Domain for Coaching Potato Ruoutine Planner 

(define (domain CoachingPotatoPlanner)
    (:requirements :strips :adl :equality :typing)
    (:types ejercicio nivel dia)
    (:predicates (preparador ?x - ejercicio ?y - ejercicio) ; x es preparador de y
    			 (dificultad ?d - nivel ?x - ejercicio) 	; d es la dificultad del ejercicio x
    			 (objetivo ?n - nivel ?x - ejercicio)		; nivel objetivo para el ejercicio x
    			 (asig ?x - ejercicio ?d - dia)				; dia que se ha realizado el ejercicio d
    			 (conseguido ?x - ejercicio)				; ejercicio conseguido con el nivel deseado
    )
    
    (:action realizado
		:parameters (?e - ejercicio ?n - nivel)
		:precondition (and (dificultad ?n ?e)  
						   (objetivo ?n ?e)
					  )
		:effect (conseguido ?e)    	
    )

    (:action asignar
    	:parameters (?e - ejercicio ?d - dia ?n - nivel)
    	:precondition (and (imply (preparador ?x ?e) (asig ?x ?d) )
    						(dificultad ?n ?e)
    						(not (objetivo ?n ?e ))
    				  )
    	:effect (and (not (dificultad ?n ?e) )
    				  (change (object ?lvl) (+ ?n 1))
    				  (dificultad ?lvl ?e)
    				  (asig ?e ?d) 
    			)
    ) 
    

)
