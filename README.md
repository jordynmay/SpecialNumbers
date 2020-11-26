## What is a Special Number?
Here, we define special numbers as numbers where every rotation they have is prime. 
For example, the number 197 is a special number because 197, 719, and 971 are all prime.
Note the distinction between rotations and combinations or permutations.
We are only considering rotations.
Another example is the number 281. 281 itself is prime, but 128 is not and neither is 812.
Therefore, 281 is not a special number.

## Files in this Repo
There are two files, a C++ file and a Lisp file.
Both are programs that do exactly the same thing.
There exists a function in each called countSpecialPrimes() that takes an integer n and returns the number of 
special primes that exist in the range 2 to n.
So why two files?
This is the first Lisp program I have ever written, and I didn't want to have to manually check my output.
So, I wrote an equivalent program in C++ first.
It helped serve as a way to confirm correctness of the output of my Lisp program as well as guide my thought process 
when writing the Lisp code.
Commented out in both files are some random test cases. If you would like to test those, simply uncomment that portion of code.

### To Run the C++ File
```
g++ cpp_version.cpp -o program
./program x
```
x being whatever value you want to test. If no argument is provided, x defaults to 100.

### To Run the Lisp File
```
(load "lisp_version.lsp")
(countSpecialPrimes x)
```
x being whatever value you want to test.
