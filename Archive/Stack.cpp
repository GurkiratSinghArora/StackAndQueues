//Name - Gurkirat Singh Arora
//SFU ID- 301466934
//date- 17th June,2022

#include"Stack.h"
#include<stdexcept>

using std:: logic_error;

Stack::Stack()
{
    size=0;
}
void Stack::push(int x)
{
    if(isEmpty()==true)
    {
        arr[0]=x;
        size++;
    }
    else if(STACKCAP>size && isEmpty()==false)
    {
        int temp[STACKCAP];
        temp[0]=x;
        for(int i=0;i<size;i++)
        {
            temp[i+1]=arr[i];
        }
        for(int i=0;i<size+1;i++)
        {
            arr[i]=temp[i];
        }
        size++;
    }
    else
    {
        throw logic_error("The array is full");
    }
}
int Stack::pop()
{
    if(isEmpty()==true)
    {
        throw logic_error("The array is empty");
    }
    else
    {
        int value=arr[0];
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return value;
    }
}
int Stack::peek() const
{
    if(isEmpty()==false)
    {
        return arr[0];
    }
    else
    {
        throw logic_error("The array is empty");
    }
}
bool Stack::isEmpty() const
{
    if(size==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
