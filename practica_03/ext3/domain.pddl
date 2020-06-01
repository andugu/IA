;; Domain for Coaching Potato Ruoutine Planner 

(define (domain CoachingPotatoPlanner)
    (:requirements :strips :adl :equality :typing)
    (:types ejercicio - item dia - item)
    (:predicates (predecesor ?x - ejercicio ?y - ejercicio) ; x es predecesor de y
                 (preparador ?x - ejercicio ?y - ejercicio) ; x es preparador de y
                 (asig ?e - ejercicio ?d - dia)             ; e se realiza el dia d
                 (cumplido ?e - ejercicio)                  ; objetivo de e cumplido
    )
    (:functions  (nivel ?e - ejercicio)                     ; el nivel de e
                 (objetivo ?e - ejercicio)                  ; nivel objetivo de e
                 (ultimo_dia ?e - ejercicio)                ; ultimo dia que se ha hecho e
                 (orden_dia ?d - dia)                       ; orden de los dias
                 (dia_actual)                               ; el dia actual
                 (ultimo_ejercicio)                         ; ultimo ejercicio hecho
                 (num_ej ?e - ejercicio)                    ; numero de cada ejercicio
                 (capacidad_dia)                            ; nº de exercicios hechos hoy
    )
    (:action completado
      :parameters (?e - ejercicio)
      :precondition (= (nivel ?e) (objetivo ?e) )
      :effect (cumplido ?e)
    )
    (:action dia_siguiente
      :precondition (and (< (dia_actual) 14)
                         (or (forall (?x - ejercicio) (= (ultimo_dia ?x) (dia_actual) ) )
                             (= (capacidad_dia) 6)
                         )
                    )
      :effect (and (increase (dia_actual) 1)
                   (assign (capacidad_dia) 0)
              )
    )
    (:action asignar
      :parameters (?e - ejercicio ?d - dia)
      :precondition (and (not (asig ?e ?d) )
                         (> (orden_dia ?d) (ultimo_dia ?e) )
                         (= (orden_dia ?d) (dia_actual) )
                         (forall (?x - ejercicio) (imply (predecesor ?x ?e) (and (asig ?x ?d) (= (ultimo_ejercicio) (num_ej ?x) ) ) ) )
                         (forall (?x - ejercicio) (imply (preparador ?x ?e) (asig ?x ?d) ) )
                         (< (capacidad_dia) 6)
                    )
      :effect (and (increase (ultimo_dia ?e) 1)
                   (asig ?e ?d)
                   (increase (capacidad_dia) 1)
                   (increase (nivel ?e) 1)
                   (assign (ultimo_ejercicio) (num_ej ?e) )
              )
    )
)