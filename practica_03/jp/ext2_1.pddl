;; Sample for a simple problem  template 

(define (problem nivel_basico)
    (:domain CoachingPotatoPlanner)
    (:objects e1 e2 e3 e4 e5 e6 e7 e8 e9 		- ejercicio
    		  d0 d1 d2 d3 d4 d5 d6 d7 d8 d9 
    		  d10 d11 d12 d13 d14				- dia
    )

    (:init  (= (orden_dia d0) 0) (= (orden_dia d1) 1)
			(= (orden_dia d2) 2) (= (orden_dia d3) 3)
			(= (orden_dia d4) 4) (= (orden_dia d5) 5)
			(= (orden_dia d6) 6) (= (orden_dia d7) 7)
			(= (orden_dia d8) 8) (= (orden_dia d9) 9)
			(= (orden_dia d10) 10) (= (orden_dia d11) 11)
			(= (orden_dia d12) 12) (= (orden_dia d13) 13)
			(= (orden_dia d14) 14)
			(= (ultimo_dia e1) -1) (= (ultimo_dia e2) -1)
			(= (ultimo_dia e3) -1) (= (ultimo_dia e4) -1)
			(= (ultimo_dia e5) -1) (= (ultimo_dia e6) -1)
			(= (ultimo_dia e7) -1) (= (ultimo_dia e8) -1)
			(= (ultimo_dia e9) -1)

			(= (dia_actual) 0)

			(= (objetivo e1) 2) (= (objetivo e2) 3)
			(= (objetivo e3) 5) (= (objetivo e4) 1)
			(= (objetivo e5) 3) (= (objetivo e6) 3)
			(= (objetivo e7) 3) (= (objetivo e8) 3)
			(= (objetivo e9) 3)
			(= (nivel e1) 0) (= (nivel e2) 0)
			(= (nivel e3) 0) (= (nivel e4) 0)
			(= (nivel e5) 0) (= (nivel e6) 0)
			(= (nivel e7) 0) (= (nivel e8) 0)
			(= (nivel e9) 0)

			(= (num_ej e1) 1) (= (num_ej e2) 2)
			(= (num_ej e3) 3) (= (num_ej e4) 4)
			(= (num_ej e5) 5) (= (num_ej e6) 6)
			(= (num_ej e7) 7) (= (num_ej e8) 8)
			(= (num_ej e9) 9)

			(preparador e1 e2) (preparador e2 e8)
			(predecesor e2 e5)
    )

    (:goal (and (cumplido e1) (cumplido e2) (cumplido e3)
    	        (cumplido e4) (cumplido e5) (cumplido e6) 
    	        (cumplido e7) (cumplido e8) (cumplido e9) 
    	    )
    )
)
