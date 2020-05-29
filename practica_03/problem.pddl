;; Sample for a simple problem  template 

(define (problem nivel_basico)
    (:domain CoachingPotatoPlanner)
    (:objects e1 e2 e3 e4 e5 e6 e7 e8 e9 		- ejercicio
    		  n1 n2 n3 n4 n5 n6 n7 n8 n9 n20 	- nivel
    		  d1 d2 d3 d4 d5 d6 d7 d8 d9 d10 
    		  d11 d12 d13 d14 d15				- dia
    )

    (:init (preparador e1 e2) (preparador e3 e4) (prepardor e5 e6)
    	   (dificultad n1 e1) (dificultad n1 e3) (dificultad n1 e5)
    	   (dificultad n2 e2) (dificultad n2 e4) (dificultad n2 e6)
    	   (dificultad n1 e7) (dificultad n1 e8) (dificultad n1 e9)
    	   (objetivo n6 e1) (objetivo n4 e6) (objetivo n8 e4)
    	   (objetivo n10 e7) (objetivo n10 e8) (objetivo n10 e9)
    	   (sig n1 n2) (sig n2 n3) (sig n3 n4)
    	   (sig n4 n5) (sig n5 n6) (sig n6 n7)
    	   (sig n7 n8) (sig n8 n9)
    	   (sig d1 d2) (sig d2 d3) (sig d3 d4)
    	   (sig d4 d5) (sig d5 d6) (sig d6 d7)
    	   (sig d7 d8) (sig d8 d9) (sig d9 d10)
    	   (sig d10 d11) (sig d11 d12) (sig d12 d13)
    	   (sig d13 d14) (sig d14 d15)
    )


    (:goal (and (conseguido e1) (conseguido e6) (conseguido e4)
    			(conseguido e7)	(conseguido e8) (conseguido e9)
    	   )
    )


)
