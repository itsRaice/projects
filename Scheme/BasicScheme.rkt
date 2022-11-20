#| 
Author: Aryan Rai
Date: 2/25/22
Description: Basic Scheme Functions
|#

;functions for part 1
(define (run1) (+ 4 5 6))
(define (run2) (/ (* 5 (+ 4 5)) 2))
(define (run3) (+ (- 100 (* (/ 20 5) (* 3 3))) (/ 120 10)))
(define (run4) (* 5 (+ 4 (/ (+ (+ 10 10) (* 5 8)) (+ 10 2)))))
(define (run5) (+ (/ (- (/ (/ (* (+ 3 5) (+ 6 4)) 2) 2) 5) 3) (+ (/ (+ (* 2 10) (* 5 4)) 2) (* 4 5))))

;functions for part 2
(define how-much-damage-ff6? (lambda (dam def) (floor (+ 1 (/ (* dam (- 255 def)) 256)))))
(define base-attack-ff7 (lambda (str wb) (+ str wb)))
(define base-damage-ff7 (lambda (lvl ba) (+ ba (* (floor (/ (+ ba lvl) 32)) (floor (/ (* lvl ba) 32))))))
(define calculate-power-ff7 (lambda (pwr bd) (* pwr (/ bd 16))))
(define how-much-damage-ff7? (lambda (def pwr) (floor (* pwr (/ (- 512 def) 512)))))
(define calculate-damage-ff7 (lambda (lvl str wb pwr def) (how-much-damage-ff7? def (calculate-power-ff7 pwr (base-damage-ff7 lvl (base-attack-ff7 str wb))))))

;functions for part 3
(define get-second-item (lambda (lst) (car(cdr lst))))
(define get-third-item (lambda (lst) (car(cdr(cdr lst)))))
(define list-length? (lambda (x) (if (null? x)
                               0
                               (+ 1 (list-length?(cdr x))))))
(define arbitrary-cdr (lambda (size lst) (if (> size (list-length? lst))
                        #f
                        (if (= size 1)
                            lst
                            (arbitrary-cdr (- size 1) (cdr lst))))))
(define make-list (lambda (size val) (if (number? size)
                                         (if (< size 1)
                    '()
                    (if (= size 1)
                                         (cons val '())
                                         (cons val (make-list (- size 1) val))
                                         )
                    )
                                         '()

                    )))

;functions for part 3
(define number-list? (lambda (lst) (if (eqv? lst '())
                                       #t
                                       (if (number? (car lst))
                                           (number-list? (cdr lst))
                                           #f
                                       ))))
(define sum-number-list (lambda (lst) (if (number-list? lst)
                                          (if (null? lst)
                                              0
                                              (+ (car lst) (sum-number-list (cdr lst)))
                                           )
                                          #f
                                          )))
                                         

                               
