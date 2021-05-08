//Header file: stackForLIS.h
#ifndef H_stackForLIS 
#define H_stackForLIS
 
#include <iostream> 
#include <cassert>

#include "stackADT.h"
 
using namespace std;



//a custom stack built for the longest
//increasing subsequence problem
//the main difference between regular stack and this stack
// is that this stack keeps count of it's size 
//and also I built a function that will replace a smallest
//element of the stack with the bigger than that element 
//this technique allows us to calculate the length of longest sequence 
template <class Type>
class stackForLIS: public stackADT<Type>
{
public:
    //Overload the assignment operator.
    const stackForLIS<Type>& operator=(const stackForLIS<Type>&); 
      
    //Function to initialize the stack to an empty state.
    void initializeStack();
      
    //Function to determine whether the stack is empty.
    bool isEmptyStack() const;
      
    //Function to determine whether the stack is full.
    bool isFullStack() const;
      
    //Function to add newItem to the stack.
    void push(const Type& newItem);

    //Function to return the top element of the stack.
    Type top() const;
      
    //Function to remove the top element of the stack.
    void pop();

    //print the stack
    void printList();
     
    //replaces the element in the stack 
    //according to LIS ordering 
    void replaceElement(const Type& newItem);


    //returns size of stack
    int stackSize();

    //constructor
    //Create an array of the size stackSize to hold 
    //the stack elements. The default stack size is 100.
    stackForLIS(int stackSize = 100); 

    //copy constructor
    stackForLIS(const stackForLIS<Type>& otherStack); 

      

    //destructor
    //Remove all the elements from the stack.
    ~stackForLIS();   

private:
    //variable for the maximum stack size
    int maxStackSize; 
    //variable to point to the top of the stack
    int stackTop; 
    //pointer to the array that holds the
    //stack elements
    Type *list;       
                      

    //Function to make a copy of otherStack.
    void copyStack(const stackForLIS<Type>& otherStack); 

    
};

//initializeStack
template <class Type>
void stackForLIS<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

//check if stack is empty
template <class Type>
bool stackForLIS<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}//end isEmptyStack

//check if stack is full
template <class Type>
bool stackForLIS<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
} //end isFullStack

//add new item to the top of stack
template <class Type>
void stackForLIS<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   
        
        //increment stackTop                     
        stackTop++; 
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push


//get top element
template <class Type>
Type stackForLIS<Type>::top() const
{
    //if stack is empty
    //terminate the program
    assert(stackTop != 0);      

    //return the top element
    //it would be stacktop - 1 position                    
    return list[stackTop - 1];  
                                
                               
}//end top

//remove the top element
template <class Type>
void stackForLIS<Type>::pop()
{
    if (!isEmptyStack())
         //decrement stackTop 
        stackTop--;      
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

//get the size of the stack
template <class Type>
int stackForLIS<Type>::stackSize() 
{
    return stackTop;
}//end stackSize

//print the elements in the stack
//starting from the first element 
template <class Type>
void stackForLIS<Type>::printList(){
    Type item;

    for (int i = 0; i < stackTop; i++)
    {
        cout<<list[i]<<" ";
    }
    cout << endl;
} 

//replace the element in the stack 
template <class Type>
void stackForLIS<Type>::replaceElement(const Type& newItem){
    int i = 0;

    //find the smallest element in stack, 
    //which is more than or equal to newItem,
    //and replace it with newItem.
    while(i < stackTop && list[i] < newItem)
        i++;
    list[i] = newItem; 
}

//constructor for stack 
template <class Type>
stackForLIS<Type>::stackForLIS(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size must be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        //set the stack size to
        //the value specified by
        //the parameter stackSize
        maxStackSize = stackSize;    
                                    
                                    
    //set stackTop to 0
    stackTop = 0;        
    //create an array to hold elements of the stack          
    list = new Type[maxStackSize];  
                                    
}//end constructor

 //destructor
template <class Type>
stackForLIS<Type>::~stackForLIS()
{
    //deallocate the memory occupied 
    //by the array
    delete [] list; 
}//end destructor

//copies the stack 
template <class Type>
void stackForLIS<Type>::copyStack
                (const stackForLIS<Type>& otherStack)
{ 
    //delete previous list
    delete [] list;
    //set the currents stacks properties
    //to that of other stack	
    maxStackSize = otherStack.maxStackSize;	
    stackTop = otherStack.stackTop;	
	
    //create new list
    list = new Type[maxStackSize];

    //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
} //end copyStack

//copy constructor
template <class Type>
stackForLIS<Type>::stackForLIS(const stackForLIS<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

//overload = operator
template <class Type>
const stackForLIS<Type>& stackForLIS<Type>::operator=
                            (const stackForLIS<Type>& otherStack)
{ 
    //to avoid self-copy
    if (this != &otherStack) 
        copyStack(otherStack);

    return *this; 
} //end operator=         

#endif