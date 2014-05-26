(defun eqn (a b n) (+ (+ (* n n) (* a n)) b) )
(defun is-divisible (a b) (= (mod a b) 0))
(defun has-divisor (n a i) (if (>= n (* a a)) (if (is-divisible n a) T (has-divisor n (+ a i) i) ) nil ))  
(defun is-prime-pre (n) (if (= n 2) T nil))
(defun is-prime (n) (if (<= n 2) (is-prime-pre n)  (not (or (is-divisible n 2) (has-divisor n 3 2)))))
(defun is-prime-val (a b n) (is-prime (eqn a b n)))
(defun primes-eqn (a b n) (if (is-prime-val a b n) (cons n (primes-eqn a b (+ n 1))) nil)   ) 
(defun num-primes (a b) (length (primes-eqn a b 0)))
(defun primes-b (a b) (if (> a -61) nil (cons (num-primes a b) (primes-b (+ a 1) b)) ))
(defun mymax_unsafe (lst cmax) (mymax (cdr lst) (max cmax (car lst))))
(defun mymax (lst cmax) (if (= (length lst) 0) cmax (mymax_unsafe lst cmax) ))

(defun max-primes-b (b) (mymax (primes-b -1000 b) 0 ))
(defun primes-ab (b) (if (> b 1000) nil (cons (max-primes-b b) (primes-ab (+ b 1))) )) 
;; max happens at a = -61 and b = 971]
(write (primes-b -61 971))

