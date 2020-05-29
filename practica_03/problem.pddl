;; Sample for a simple problem  template 

(define (problem nivel_basico)
    (:domain CoachingPotatoPlanner)
    (:objects e1 e2 e3 e4 e5 e6 e7 e8 e9 		- ejercicio
    		  1 2 3 4 5 6 7 8 9 20 				- nivel
    		  d1 d2 d3 d4 d5 d6 d7 d8 d9 d10 
    		  d11 d12 d13 d14 d15				- dia
    )

    (:init (preparador e1 e2) (preparador e3 e4) (prepardor e5 e6)
    	   (dificultad 1 e1) (dificultad 1 e3) (dificultad 1 e5)
    	   (dificultad 2 e2) (dificultad 2 e4) (dificultad 2 e6)
    	   (dificultad 1 e7) (dificultad 1 e8) (dificultad 1 e9)
    	   (objetivo 6 e1) (objetivo 4 e6) (objetivo 8 e4)
    	   (objetivo 10 e7) (objetivo 10 e8) (objetivo 10 e9)
    )


    (:goal (and (conseguido e1) (conseguido e6) (conseguido e4)
    			(conseguido e7)	(conseguido e8) (conseguido e9)
    	   )
    )


)
