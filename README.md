# Testing Jumble Puzzle

The result from different testing methods as well as black-box input partitioning.

Testing accessors:

   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 
 0 k  q  y  u  q  f  j  k  x  y  q  v  n  r  t  y  s  f  
 1 r  z  r  m  z  l  y  g  f  v  e  u  l  q  f  p  d  b  
 2 h  l  q  d  q  r  r  c  r  w  d  n  x  e  u  o  q  q  
 3 e  k  l  a  i  t  g  d  p  h  c  s  p  i  j  t  h  b  
 4 s  f  y  f  v  l  a  d  z  p  b  f  u  d  k  k  l  r  
 5 w  q  a  o  z  m  i  x  r  p  i  f  e  f  f  e  c  l  
 6 h  b  v  f  u  k  b  y  e  q  f  q  o  j  w  t  w  o  
 7 s  i  l  e  e  g  n  i  d  o  c  k  n  g  b  q  q  m  
 8 b  x  q  c  q  p  t  k  h  h  q  r  q  d  w  f  c  a  
 9 y  s  s  y  o  q  c  j  o  m  w  u  f  b  d  f  x  u  
10 d  z  h  i  f  t  a  k  c  z  v  h  s  y  b  l  o  e  
11 t  s  w  c  r  f  h  p  x  p  r  b  s  s  h  s  j  x  
12 d  f  i  l  e  b  x  w  b  c  t  o  a  y  a  x  z  f  
13 b  j  b  k  r  x  i  r  i  m  q  p  z  w  m  s  h  l  
14 p  j  h  t  a  z  h  b  u  x  h  w  a  d  l  p  t  o  
15 y  e  z  i  w  k  m  g  s  o  v  q  z  g  d  i  x  r  
16 p  d  d  z  p  l  c  r  w  n  q  w  q  e  c  y  j  y  
17 i  b  f  j  y  k  m  j  f  q  w  l  t  v  z  k  q  t  

Row position: 7
Column position: 10
Size of matrix (18): 18
Direction (n/s/e/w): w

Testing BadJumbleException class:
Difficulty must be either, easy, medium, or hard.
Difficulty must be either, easy, medium, or hard.
ERROR: entered word must be less than 10 characters
ERROR: entered word must be more than 3 characters
ERROR: entered word must be more than 3 characters
Testing copy constructor:

   0  1  2  3  4  5  6  7  8  9 
 0 l  p  h  c  k  c  y  u  f  d  
 1 q  m  H  E  L  L  O  k  l  f  
 2 z  k  t  g  y  g  d  t  t  n  
 3 h  c  v  p  f  d  f  b  r  p  
 4 z  l  k  v  s  h  w  y  w  s  
 5 h  t  d  g  m  b  q  b  k  k  
 6 x  c  v  g  u  m  o  n  m  w  
 7 v  y  t  b  y  t  n  u  q  h  
 8 m  f  j  a  q  t  g  n  g  c  
 9 w  k  u  z  y  a  m  n  e  r  

Should look the same:

   0  1  2  3  4  5  6  7  8  9 
 0 l  p  h  c  k  c  y  u  f  d  
 1 q  m  H  E  L  L  O  k  l  f  
 2 z  k  t  g  y  g  d  t  t  n  
 3 h  c  v  p  f  d  f  b  r  p  
 4 z  l  k  v  s  h  w  y  w  s  
 5 h  t  d  g  m  b  q  b  k  k  
 6 x  c  v  g  u  m  o  n  m  w  
 7 v  y  t  b  y  t  n  u  q  h  
 8 m  f  j  a  q  t  g  n  g  c  
 9 w  k  u  z  y  a  m  n  e  r  

Dotted diagonal:

   0  1  2  3  4  5  6  7  8  9 
 0 .  p  h  c  k  c  y  u  f  d  
 1 q  .  H  E  L  L  O  k  l  f  
 2 z  k  .  g  y  g  d  t  t  n  
 3 h  c  v  .  f  d  f  b  r  p  
 4 z  l  k  v  .  h  w  y  w  s  
 5 h  t  d  g  m  .  q  b  k  k  
 6 x  c  v  g  u  m  .  n  m  w  
 7 v  y  t  b  y  t  n  .  q  h  
 8 m  f  j  a  q  t  g  n  .  c  
 9 w  k  u  z  y  a  m  n  e  .  

Should be same as original 1:

   0  1  2  3  4  5  6  7  8  9 
 0 l  p  h  c  k  c  y  u  f  d  
 1 q  m  H  E  L  L  O  k  l  f  
 2 z  k  t  g  y  g  d  t  t  n  
 3 h  c  v  p  f  d  f  b  r  p  
 4 z  l  k  v  s  h  w  y  w  s  
 5 h  t  d  g  m  b  q  b  k  k  
 6 x  c  v  g  u  m  o  n  m  w  
 7 v  y  t  b  y  t  n  u  q  h  
 8 m  f  j  a  q  t  g  n  g  c  
 9 w  k  u  z  y  a  m  n  e  r  

Should be same as original 2:

   0  1  2  3  4  5  6  7  8  9 
 0 l  p  h  c  k  c  y  u  f  d  
 1 q  m  H  E  L  L  O  k  l  f  
 2 z  k  t  g  y  g  d  t  t  n  
 3 h  c  v  p  f  d  f  b  r  p  
 4 z  l  k  v  s  h  w  y  w  s  
 5 h  t  d  g  m  b  q  b  k  k  
 6 x  c  v  g  u  m  o  n  m  w  
 7 v  y  t  b  y  t  n  u  q  h  
 8 m  f  j  a  q  t  g  n  g  c  
 9 w  k  u  z  y  a  m  n  e  r  

Testing assignment operator:

   0  1  2  3  4  5 
 0 m  w  e  v  h  w  
 1 l  e  z  o  h  y  
 2 e  e  h  b  r  c  
 3 e  E  Y  B  v  c  
 4 e  z  i  f  t  i  
 5 q  t  n  t  f  s  

Should look the same:

   0  1  2  3  4  5 
 0 m  w  e  v  h  w  
 1 l  e  z  o  h  y  
 2 e  e  h  b  r  c  
 3 e  E  Y  B  v  c  
 4 e  z  i  f  t  i  
 5 q  t  n  t  f  s  

Star diagonal:

   0  1  2  3  4  5 
 0 *  w  e  v  h  w  
 1 l  *  z  o  h  y  
 2 e  e  *  b  r  c  
 3 e  E  Y  *  v  c  
 4 e  z  i  f  *  i  
 5 q  t  n  t  f  *  

Should be same as original 3:

   0  1  2  3  4  5 
 0 m  w  e  v  h  w  
 1 l  e  z  o  h  y  
 2 e  e  h  b  r  c  
 3 e  E  Y  B  v  c  
 4 e  z  i  f  t  i  
 5 q  t  n  t  f  s  

Should be same as original 4:

   0  1  2  3  4  5 
 0 m  w  e  v  h  w  
 1 l  e  z  o  h  y  
 2 e  e  h  b  r  c  
 3 e  E  Y  B  v  c  
 4 e  z  i  f  t  i  
 5 q  t  n  t  f  s  

Should be same as original 4:

   0  1  2  3  4  5 
 0 m  w  e  v  h  w  
 1 l  e  z  o  h  y  
 2 e  e  h  b  r  c  
 3 e  E  Y  B  v  c  
 4 e  z  i  f  t  i  
 5 q  t  n  t  f  s  


Passed memory leak test!
Provide a string to hide in the puzzle, all lower case: hithere

Choose your difficulty level: "easy", "medium" or "hard": medium

   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 
 0 g  b  g  k  m  h  w  k  x  b  b  o  i  a  x  t  r  o  g  d  b  
 1 r  w  j  b  x  p  c  g  h  p  s  a  x  o  w  l  d  g  z  q  x  
 2 s  s  u  h  i  t  h  e  r  e  w  w  k  i  n  i  g  k  q  c  m  
 3 k  k  g  f  s  m  n  a  r  o  a  v  o  q  d  h  q  z  f  g  o  
 4 u  b  b  a  p  w  d  w  s  f  d  d  g  d  w  z  y  h  g  x  f  
 5 h  k  k  f  c  s  h  i  d  u  t  h  v  r  j  q  o  v  m  r  j  
 6 z  b  r  t  s  j  v  o  v  f  m  w  o  g  n  c  g  q  t  j  d  
 7 q  s  p  e  g  r  k  p  v  w  x  r  d  w  q  v  k  p  c  n  w  
 8 g  f  p  u  p  h  f  d  f  f  m  v  r  w  e  k  z  b  e  e  i  
 9 s  x  b  q  h  p  z  t  n  l  u  x  r  k  d  u  g  x  j  h  m  
10 v  b  c  c  r  r  a  s  e  i  t  p  z  g  j  b  o  y  e  b  l  
11 n  g  a  w  c  o  d  a  i  k  h  d  m  o  q  j  s  o  g  g  j  
12 v  c  r  w  t  u  h  c  v  t  o  y  g  u  q  s  p  b  n  y  n  
13 y  p  j  a  v  s  q  w  j  u  o  h  s  t  y  w  t  e  h  o  s  
14 e  e  j  d  y  m  o  v  j  u  q  z  r  m  u  n  v  h  t  h  m  
15 p  n  f  s  k  u  w  j  w  h  j  y  k  q  u  y  g  e  f  k  m  
16 k  l  p  v  d  h  b  f  j  t  e  h  u  n  k  f  k  s  e  l  m  
17 e  w  s  l  d  y  f  x  t  k  w  y  r  e  w  v  l  u  h  q  e  
18 m  d  t  t  j  y  q  m  y  z  z  t  m  f  x  o  k  i  d  c  n  
19 p  y  x  c  x  d  x  k  v  h  y  y  j  l  n  e  u  m  t  g  n  
20 j  h  b  b  u  m  y  d  x  l  b  o  s  i  g  u  z  s  a  l  u  

Enter row location: 2
Enter column location: 3
Enter direction ("n", "e", "s" or "w"): e
You found it!
You took 66 seconds.
