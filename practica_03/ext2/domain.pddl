;; Domain for Coaching Potato Ruoutine Planner 

(define (domain CoachingPotatoPlanner)
    (:requirements :strips :adl :equality :typing)
    (:types ejercicio nivel dia position)
    (:predicates (preparador ?x - ejercicio ?y - ejercicio)   ; x es preparador de y
    	         (predecesor ?x - ejercicio ?y - ejercicio)   ; x es predecesor de y
    			 (dificultad ?d - nivel ?x - ejercicio) 	  ; d es la dificultad del ejercicio x
    			 (objetivo ?n - nivel ?x - ejercicio)		  ; nivel objetivo para el ejercicio x
    			 (asig ?x - ejercicio ?d - dia)               ; dia d en el que se hace el ejercicio x
    			 (conseguido ?x - ejercicio)				  ; ejercicio conseguido con el nivel deseado
                 (sig ?n1 - nivel ?n2 - nivel)                ; n2 = n1+1
                 (ant ?d1 - dia ?d2 - dia)                    ; ayer
                 (primer_dia ?d - dia)                        ; primer dia
                 (ultimo_ejercicio ?d - dia ?e - ejercicio)   ; ultimo ejercicio hecho el dia d
    )

    (:action alcanzado
		:parameters   (?e - ejercicio ?n - nivel)
		:precondition (and (dificultad ?n ?e) (objetivo ?n ?e))
		:effect       (conseguido ?e)
    )

    (:action asignar
    	:parameters   (?e - ejercicio ?d - dia ?n - nivel ?l - nivel)
    	:precondition (and (not (asig ?e ?d))
    		               (imply (not (primer_dia ?d)) (exists (?ayer - dia) (and (ant ?ayer ?d) (asig ?e ?ayer) ) ) )
    		               (forall (?x - ejercicio) (imply (preparador ?x ?e) (asig ?x ?d) ) )
    		               (forall (?x - ejercicio) (imply (predecesor ?x ?e) (and (asig ?x ?d) (ultimo_ejercicio ?d ?x) ) ) )
                           (dificultad ?n ?e)
                           (not (objetivo ?n ?e))
                           (sig ?n ?l)
    				  )
    	:effect       (and (asig ?e ?d)
    		               (forall (?x - ejercicio) (not (ultimo_ejercicio ?d ?x) ) )
    		               (ultimo_ejercicio ?d ?e)
    		               (not (dificultad ?n ?e))
    				       (dificultad ?l ?e)
    			      )
    )
)