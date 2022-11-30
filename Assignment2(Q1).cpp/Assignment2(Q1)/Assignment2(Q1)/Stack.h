// Desc:  Implementation of an int sequence with push/pop in a LIFO order
class Stack {

    private:

        // Desc:  arr = static array of capacity STACKCAP
        //        size = the number of elements presently in the stack
        //  Inv:  Follows the A2 Spec, namely that the stack elements 
        //        are in order within A[0..size-1], where the top of
        //        the stack is A[0].
        static const unsigned STACKCAP = 8;
        int arr[STACKCAP];
        unsigned size;

    public:

        // Desc:  Object constructor
        // Post: creates a new Stack and intializes the size of the array to 0
        Stack();

        
        // Desc:  Insert element x to the top of the stack.
        //  Pre:  STACKCAP is not equal to size i.e. the array is not full.
        // Post:  element x is inserted at index 0 and if the array is partially filled then the
        //all the other elements are shifted by 1 index ahead.
    
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  the array on the stack is not empty.
        // Post:  return and remove the element at index 0 of the array, all the other element are //shifted by one index backwards.
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  the array on the stack is not empty.
        // Post:  return element at the top of the stack i.e. element at index 0 of the array.
        int peek() const;


        // Desc:  checks if the array is empty or not.
        // Post:  returns true if the size of the array is 0 and false otherwise.
        bool isEmpty() const;

};


