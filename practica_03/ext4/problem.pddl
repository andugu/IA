;; Sample for a simple problem  template 

(define (problem nivel_basico)
    (:domain CoachingPotatoPlanner)
    (:objects e1 e2 e3 e4 e5 e6 e7 e8 e9 		- ejercicio
    		  n1 n2 n3 n4 n5 n6 n7 n8 n9 n10 	- nivel
    		  d1 d2 d3 d4 d5 d6 d7 d8 d9 d10 
    		  d11 d12 d13 d14 d15				- dia
    )

    (:init (preparador e1 e2) (preparador e3 e4) (preparador e5 e6)
           (precursor e7 e9) (precursor e8 e3)
    	     (dificultad n1 e1) (dificultad n1 e3) (dificultad n1 e5)
    	     (dificultad n2 e2) (dificultad n2 e4) (dificultad n2 e6)
    	     (dificultad n1 e7) (dificultad n1 e8) (dificultad n1 e9)
    	     (objetivo n3 e1) (objetivo n5 e6) (objetivo n2 e4)
    	     (objetivo n1 e7) (objetivo n8 e8) (objetivo n10 e9)
    	     (sig n1 n2) (sig n2 n3) (sig n3 n4)
    	     (sig n4 n5) (sig n5 n6) (sig n6 n7)
    	     (sig n7 n8) (sig n8 n9) (sig n9 n10)
           (primer_dia d1)
           (ant d1 d2) (ant d2 d3) (ant d3 d4) (ant d4 d5)
           (ant d5 d6) (ant d6 d7) (ant d7 d8) (ant d8 d9)
           (ant d9 d10) (ant d10 d11) (ant d11 d12) (ant d12 d13)
           (ant d13 d14) (ant d14 d15)
           (= (capacidad_dia d1) 0) (= (capacidad_dia d2) 0)
           (= (capacidad_dia d3) 0) (= (capacidad_dia d4) 0)
           (= (capacidad_dia d5) 0) (= (capacidad_dia d6) 0)
           (= (capacidad_dia d7) 0) (= (capacidad_dia d8) 0)
           (= (capacidad_dia d9) 0) (= (capacidad_dia d10) 0)
           (= (capacidad_dia d11) 0) (= (capacidad_dia d12) 0)
           (= (capacidad_dia d13) 0) (= (capacidad_dia d14) 0)
           (= (capacidad_dia d15) 0)
    )


    (:goal (conseguido e1) (conseguido e6) (conseguido e4)
           (conseguido e7) (conseguido e8) (conseguido e9)
    )
)
