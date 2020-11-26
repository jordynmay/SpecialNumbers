; Returns 1 if n is prime; 0 otherwise
; Initial call should start with i=2
(defun isPrime (n i)
    (if (> i (sqrt n)) ; Going up to sqrt is sufficient for checking factors
        (return-from isPrime 1)
        (progn
            (if (= (rem n i) 0)
                (return-from isPrime 0)
                (isPrime n (+ i 1))
            )
        )
    )
)

; Returns the number of digits in n
(defun numDigits (n)
    (if (= (floor (/ n 10)) 0)
        (return-from numDigits 1)
        (return-from numDigits (+ 1 (numDigits (floor (/ n 10)))))
    )
)

; Returns n rotated once to the right (i.e. 197 -> 719)
(defun rotate (n)
    (progn
        (defparameter leastSigDig (rem n 10))
        (defparameter powFactor (- (numDigits n) 1))
        (defparameter multThis (EXPT 10 powFactor))
        (return-from rotate (+ (floor (/ n 10)) (* leastSigDig multThis)))
    )
)

; Returns 1 if all rotations of n are prime; 0 otherwise
; If it returns 1, we call n a special prime
(defun allRotsPrime (n i)
    (if (= i 0)
        (return-from allRotsPrime 1)
        (progn
            (defparameter numberList (map 'list #'digit-char-p (prin1-to-string n)))
            (if (member 0 numberList)
                (return-from allRotsPrime 0) ; No reason to check if n contains a 0
                (progn
                    (defparameter nPrime (isPrime n 2))
                    (if (= nPrime 0)
                        (return-from allRotsPrime 0) ; If even one is not prime, return 0
                        (progn ; Else recursive call with new n and decremented i
                            (defparameter rotsPrime (allRotsPrime (rotate n) (- i 1)))
                            (return-from allRotsPrime rotsPrime)
                        )
                    )
                )
            )
        )
    )
)

(setq biglist '()) ; Global list that holds all special numbers

; Returns the number of special primes from 2 to n
(defun countSpecialPrimes (n)
    (if (<= n 1) ; Base case
        (return-from countSpecialPrimes (length bigList))
        (progn
            (if(= (isPrime n 2) 1)
                (progn
                    (defparameter nDigs (numDigits n))
                    (if (= nDigs 1)
                        (push n biglist) ; Bc we already know n itself is prime
                        (progn
                            (if(= (allRotsPrime n nDigs) 1)
                                (push n biglist)
                            )
                        )
                    )
                )
            )
            (countSpecialPrimes (- n 1))
        )
    )
)

; Some test inputs
;(print (countSpecialPrimes 10))
;(setq biglist '()) 
;(print (countSpecialPrimes 100))
;(setq biglist '()) 
;(print (countSpecialPrimes 257))
;(setq biglist '()) 
;(print (countSpecialPrimes 545))
;(setq biglist '()) 
;(print (countSpecialPrimes 814))
;(setq biglist '()) 
;(print (countSpecialPrimes 999))
