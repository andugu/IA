;; Sample for a simple problem  template 

(define (problem nivel_basico)
    (:domain CoachingPotatoPlanner)
    (:objects e1 e2 e3 e4 e5 e6 e7 e8 e9        - ejercicio
              n1 n2 n3 n4 n5 n6 n7 n8 n9 n10    - nivel
              d1 d2 d3 d4 d5 d6 d7 d8 d9 d10 
              d11 d12 d13 d14 d15               - dia
    )

    (:init (preparador e1 e2) (preparador e2 e3) (preparador e4 e5)
           (preparador e5 e6) (preparador e6 e7) (preparador e8 e9)
           (dificultad n1 e1) (dificultad n1 e3) (dificultad n1 e5)
           (dificultad n1 e2) (dificultad n1 e4) (dificultad n1 e6)
           (dificultad n1 e7) (dificultad n1 e8) (dificultad n1 e9)
           (objetivo n3 e1) (objetivo n5 e6) (objetivo n2 e4)
           (sig n1 n2) (sig n2 n3) (sig n3 n4)
           (sig n4 n5) (sig n5 n6) (sig n6 n7)
           (sig n7 n8) (sig n8 n9) (sig n9 n10)
           (primer_dia d1)
           (ant d1 d2) (ant d2 d3) (ant d3 d4) (ant d4 d5)
           (ant d5 d6) (ant d6 d7) (ant d7 d8) (ant d8 d9)
           (ant d9 d10) (ant d10 d11) (ant d11 d12) (ant d12 d13)
           (ant d13 d14) (ant d14 d15)
    )


    (:goal (and (conseguido e1) (conseguido e6) (conseguido e4)
           )
    )


)
