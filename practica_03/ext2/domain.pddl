;; Domain for Coaching Potato Ruoutine Planner 

(define (domain CoachingPotatoPlanner)
    (:requirements :strips :adl :equality :typing)
    (:types ejercicio nivel dia)
    (:predicates (preparador ?x - ejercicio ?y - ejercicio) ; x es preparador de y
                 (precursor ?x - ejercicio ?y - ejercicio)  ; x es precursor de y
    			       (dificultad ?d - nivel ?x - ejercicio) 	  ; d es la dificultad del ejercicio x
    			       (objetivo ?n - nivel ?x - ejercicio)		    ; nivel objetivo para el ejercicio x
    			       (asig ?x - ejercicio ?d - dia)				      ; dia que se ha realizado el ejercicio d
    			       (conseguido ?x - ejercicio)			        	; ejercicio conseguido con el nivel deseado
                 (sig ?n1 - nivel ?n2 - nivel)              ; n2 = n1+1
                 (ant ?d1 - dia ?d2 - dia)                  ; ayer
                 (primer_dia ?d - dia)                      ; primer dia
                 (ultimo ?x - ejercicio)                     ; ultimo ejercicio asignado
    )

    (:action alcanzado
		:parameters (?e - ejercicio ?n - nivel)
		:precondition (and (dificultad ?n ?e) (objetivo ?n ?e))
		:effect (conseguido ?e)    	
    )

    (:action con-precursor
        :parameters (?e - ejercicio ?d - dia ?n - nivel ?l - nivel ?p - ejercicio)
        :precondition (and  (forall (?x - ejercicio) (and (imply (preparador ?x ?e) (asig ?x ?d))))
                            (imply (not (primer_dia ?d)) (exists (?ayer - dia) (and (ant ?ayer ?d) (asig ?e ?ayer))))
                            (precursor ?p ?e)
                            (ultimo ?p)
                            (dificultad ?n ?e)
                            (not (objetivo ?n ?e))
                            (sig ?n ?l)
                            (not (asig ?e ?d))
                      )
        :effect (and (not (dificultad ?n ?e) )
                     (not (ultimo ?p))
                      (dificultad ?l ?e)
                      (asig ?e ?d)
                      (ultimo ?e)
                )
    )

    (:action primer-ejercicio
        :parameters (?e - ejercicio ?d - dia ?n - nivel ?l - nivel)
        :precondition (and (not (exists (?u - ejercicio) (ultimo ?u)))
                           (not (exists (?u - ejercicio) (precursor ?u ?e)))
                           (forall (?x - ejercicio) (and (imply (preparador ?x ?e) (asig ?x ?d))))
                           (dificultad ?n ?e)
                           (not (objetivo ?n ?e))
                           (sig ?n ?l)
                           (not (asig ?e ?d))
                      )
        :effect (and (not (dificultad ?n ?e) )
                      (dificultad ?l ?e)
                      (asig ?e ?d)
                      (ultimo ?e)
                )
    )

    (:action sin-precursor
        :parameters (?e - ejercicio ?d - dia ?n - nivel ?l - nivel ?p - ejercicio)
        :precondition (and  (forall (?x - ejercicio) (and (imply (preparador ?x ?e) (asig ?x ?d))))
                            (imply (not (primer_dia ?d)) (exists (?ayer - dia) (and (ant ?ayer ?d) (asig ?e ?ayer))))
                            (not (exists (?u - ejercicio) (precursor ?u ?e)))
                            (ultimo ?p)
                            (dificultad ?n ?e)
                            (not (objetivo ?n ?e))
                            (sig ?n ?l)
                            (not (asig ?e ?d))
                      )
        :effect (and (not (dificultad ?n ?e) )
                     (not (ultimo ?p))
                      (dificultad ?l ?e)
                      (asig ?e ?d)
                      (ultimo ?e)
                )
    )

    

)
