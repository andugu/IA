;; Domain for Coaching Potato Ruoutine Planner 

(define (domain CoachingPotatoPlanner)
    (:requirements :strips :adl :equality :typing)
    (:types ejercicio nivel dia - object)
    (:predicates (preparador ?x - ejercicio ?y - ejercicio) ; x es preparador de y
    			 (dificultad ?d - nivel ?x - ejercicio) 	; d es la dificultad del ejercicio x
    			 (objetivo ?n - nivel ?x - ejercicio)		; nivel objetivo para el ejercicio x
    			 (asig ?x - ejercicio ?d - dia)				; dia que se ha realizado el ejercicio d
    			 (conseguido ?x - ejercicio)				; ejercicio conseguido con el nivel deseado
    )
    
    (:action realizado
		:parameters (?e - ejercicio ?n - nivel)
		:precondition ( and (exists (dificultad ?n ?e) ) 
							(exists (objetivo ?n ?e) )
					  )
		:effect (conseguido ?e)    	
    )

    (:action asignar
    	:parameters (?e - ejercicio ?d - dia ?n - nivel)
    	:precondition ( and ( imply ( exists (preparador ?x - ejercicio ?e)  ) ( exists (asig ?x ?d) ) )
    						( exists (dificultad ?n ?e ) )
    						( not ( exists (objetivo ?n ?e ) ) )
    				  )
    	:effect ( and (not (dificultad ?n ?e) )
    				  (change (object ?lvl - nivel) (+ ?n 1))
    				  (dificultad ?lvl ?e)
    				  (asig ?e ?d) 
    			)
    ) 
    

)
