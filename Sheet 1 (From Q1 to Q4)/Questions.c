/*
Q1: Will you need to include stack.h in stack.c ? Why?
A: Yes. Including stack.h ensures that function prototypes and data type definitions match between the header and implementation, 
preventing inconsistencies.
*/

// ------------------------------------------

/*
Q2: At this point, will you be able to build test.c? Why?
A: No, not fully. test.c depends on functions from stack.obj, so stack.c must be compiled first, 
then linked with test.c to produce the executable.
*/

// ------------------------------------------

/*
Q3: Pre- and post-conditions for stack_size.
Pre: The stack is initialized.
Post: Returns the number of elements without modifying the stack.
*/

// ------------------------------------------

/*
Q4: Why shouldn’t this function be written in the implementation level?
A: Printing is application-specific. Implementation level should only manage data, 
keeping it reusable without enforcing a specific output format.
*/