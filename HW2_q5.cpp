#include <iostream>
#include <set>
#include <iterator>
#include "stackForLIS.h"
using namespace std;

// Function to find the length of the longest increasing subsequence in a given array
int findLongestSubSize(int arr[], int n){

    stackForLIS<int> stackLIS;

   // process every element one by one
    for (int i = 0; i < n; i++)
    {
        //If stack is empty
        //insert the first element 
        //into a stack
        if(stackLIS.isEmptyStack()){
            stackLIS.push(arr[i]);
            continue;
        }

       // If current element is more than the last element in stack, 
       // then push that element on the stack. 
       // This means a new largest subsequence was found
       // Otherwise find the smallest element in stack, 
       // which is more than or equal to newItem,
       // and replace it with newItem. Custom stack method
       // takes care of that insertion 
        if(stackLIS.top() < arr[i]) 
            stackLIS.push(arr[i]);
        else{ //Otherwise replace the element using custom method in stack
            stackLIS.replaceElement(arr[i]);
        }
    
    }

    return stackLIS.stackSize();
}

// Function to find the length of the longest increasing subsequence in a given array
void findLongestSub(int arr[], int n){
    int localMax = 0;
   // dynamically allocate an array of stacks  
    stackForLIS<int> *stacksLIS = new stackForLIS<int>[n];
    
    //insert the first element on the first stack
    stacksLIS[0].push(arr[0]);

    //for entire array
    for (int i = 1; i < n; i++)
    {
        //make localMax index = current index
        localMax = i;
        //find the largest subsequence up to arr[j]
        //and push it on the stack
        for (int j = 0; j < i; j++)
        {
            //check the top of every stack to see if it's
            //larger than current element
            //keep track of the largest stack found so far using
            //localMax variable which tells us the index of largest stack
            if(arr[i] > stacksLIS[j].top() && 
                    stacksLIS[j].stackSize() > stacksLIS[localMax].stackSize()){
                
                localMax = j;
               // stacksLIS[localMax].push(arr[i]);
            }
        }
        //largest stack was found
        //copy that stack into current stack
        stacksLIS[i] = stacksLIS[localMax];
        //and add current number to it
        stacksLIS[i].push(arr[i]);
 
    }

    localMax = 0;
    //find the largest stack by looping through every stack
    for (int i = 0; i < n; i++)
    {
        //whenever larger stack was found make it's index = localMax
        if(stacksLIS[localMax].stackSize() < stacksLIS[i].stackSize())
            localMax = i;
        
    }

    //print longest subsequence
    stacksLIS[localMax].printList();
     
    //free up memory
    delete [] stacksLIS;
    
}


 
int main()
{
    int arr[] = { 12, 8, 3, 5, 4, 1, 15, 9, 5, 7, 45, 23, 8, 2, 10, 9, 12, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
  //  cout << "The length of the LIS is " << findLISLength(arr, n)<<endl;
    cout << "The length of the longest subsequence is: " << endl;
    cout<< findLongestSubSize(arr, n);
    cout << endl;
    cout << "The longest increasing subsequence is: " << endl;
    findLongestSub(arr, n);
 
    return 0;
}