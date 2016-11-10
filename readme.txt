/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name: GU Qiao
Login: qgu
Hours to complete assignment (optional): 20



/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/

I adopt an algorithm from standard library std::next_permutation to get
the combination of the points. Four points are got every times. Then compute
their slopes and compare. If they are equal, a line is formed, if not, go
to next one.

I use Vector2D as the base class of the Point. It has methods to compute
the dot product and cross product. I overload the operator<< to give the
format cout for Point class. and create a static method that use cross
product to compare slope and is used as function pointer in the std::sort().

/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/

In Vector2D class, there are actually two way to compare. '<' is overloaded
as comparing x first and y second. Static method slopeLargerFirst() will
compare the slope of two vector.

When I get a line(composed of several points), they will be sorted by the
'<' method mentioned above. And then, I will check whether I can find a
identical one in the lines vector(composed of line). If not, the line will
be pushed to the lines.


/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10
     20
     40
     80
    100
    150
    200
    400
   1000
   2000
   4000
  10000


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute:
Sorting:



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute: It has 4 nested for loops. So the complexity is O(N^4)
Sorting: I use quick sort, which takes O(N^2) time in worst-case. And
N items causes O(N^3) time.



/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
No.


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.
 **********************************************************************/




/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback
 *  on how much you learned from doing the assignment, and whether
 *  you enjoyed doing it.
 **********************************************************************/
