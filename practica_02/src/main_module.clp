;;***************************************
;;*           MAIN MODULE               *
;;***************************************

(defmodule MAIN (export ?ALL))

(defrule init "initial rule"
    (initial-fact); start on program run
    =>
    (printout t crlf)
    (printout t "==============================================" crlf)
    (printout t "   Coaching Potato Expert Routine Generator   " crlf)
    (printout t "==============================================" crlf)
    (printout t crlf)
    (assert (system_start)) ; tell the system that it needs to start
    (focus io_module)
)
