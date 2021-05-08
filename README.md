# HW2-Problem-5
HW2 Problem 5

HW 2 PROBLEM 5
YEVGENIY SUMARYEV

In this problem the objective was to use stack in order to find longest increasing subsequence, in a list of elements and the subsequence
may not be contiguous.
 In order to use stacks the approach I chose was to create multiple stacks, one for element in the array, and that stack would contain a 
largest sequence so far up to that element. At the end of the list there would be a list of stacks and the stack with the largest size would 
have the longest subsequence. The way to implement this was for each  element to check previous elements in the list, it would compare
 the top stack element for each element, and if the current element was larger than the top of the stack of the previous elements, it would 
copy that stack into it’s own stack(since every element in the list has its own stack) and then add itself to the top of the stack. That way 
each stack would contain the largest subsequence up to that particular  element. After the last element is reached we would just need to 
find the stack with the largest size and that stack would contain the necessary subsequence. This could easily be accomplished with the loop 
that updates the max size of stacks.
Within the main logic if the program when each element in the list was comparing itself to the stack tops of previous elements I used 
local variable to keep track of index with the largest subsequence so far, and that way one could easily get the index of the largest stack
that fits the criteria.
 I also had the method which just counts the size of the largest subsequence in order to make sure that number agrees with the result from 
other method. The way to find the size of the longest subsequence we just need one stack(with a customized method that I wrote for that stack 
class) and any time the element in the main list is found that is larger than the current top of the stack that new element would be pushed on 
top of the stack, otherwise that element would be added into the stack according to an ordering where that element would replace
the next biggest element. This keeps track of the length of the largest subsequence because each element encountered that can be pushed on top of
the stack would be part of some subsequence that has longest length at that point, and if larger element is found it would be pushed on top of that stack thus increasing the size of the stack. Elements in the stack don’t represent the subsequence only the size. The final size of the stack would be the size of the longest subsequence. 
I modified my stack to have a few additional properties, such as being able to return its size, print the elements in the stack and also replace 
a particular element in the stack according to logic necessary for the array that keeps track of subsequence size. 

