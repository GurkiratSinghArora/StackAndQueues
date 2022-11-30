//Name - Gurkirat Singh Arora
//SFU ID- 301466934
//date- 17th June,2022
#include "Queue.h"
#include<stdexcept>

using std::logic_error;
// Desc:  Constructor
Queue::Queue() : size(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0)
{
    arr= new int [capacity];
} // constructor


// Desc:  Destructor
Queue::~Queue()
{
    delete[] arr;
    arr= nullptr;
} // destructor


// Desc:  Copy Constructor
Queue::Queue(const Queue &other)
{
    if (this != &other)
    {
        size = other.size;
        capacity = other.capacity;
        frontindex = other.frontindex;
        backindex = other.backindex;
        arr= new int [capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
} // copy constructor


// Desc:  Assignment operator
Queue & Queue::operator=(const Queue &rhs)
{
    if (this != &rhs)
    {
        delete[] arr;
        size = rhs.size;
        capacity = rhs.capacity;
        frontindex = rhs.frontindex;
        backindex = rhs.backindex;
        arr= new int [capacity];
        for (unsigned i = 0; i < size; i++)
        {
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
} // lhs = rhs


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x)
{
    if(size==capacity)
    {
        capacity=capacity*2;
        int *new_arr=new int[capacity];
        int j=0;
        for(int i=frontindex;i<size;i++)
        {
            new_arr[j]= arr[i];
            j++;
        }
        int i=0;
        while(i<backindex)
        {
            new_arr[j]=arr[i];
            i++;
            j++;
        }
        frontindex=0;
        backindex=size%capacity;
        delete[] arr;
        arr=new_arr;
        new_arr=nullptr;
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1) % capacity;
    }
    else
    {
        size++;
        arr[backindex] = x;
        backindex = (backindex + 1) % capacity;
    }
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue()
{
    if(isEmpty())
    {
        throw logic_error("The circular array is empty");
    }
    else if(size<capacity/4 && ((capacity/2)>=INITIAL_SIZE))
    {
        capacity=capacity/2;
        int j=0;
        int *new_arr= new int [capacity];
        for(int i=frontindex;i<backindex;i++)
        {
            new_arr[j]=arr[i];
            j++;
        }
        frontindex=0;
        backindex=j;
        delete[] arr;
        arr=new_arr;
        new_arr=nullptr;
    }
    size--;
    frontindex = (frontindex + 1) % capacity;
} // dequeue

// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const
{
    if(isEmpty())
    {
        throw logic_error("The circular array is empty");
    }
    return arr[frontindex];
} // top

// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const
{
    return size == 0;
} // isempty




