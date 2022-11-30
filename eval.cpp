//Name - Gurkirat Singh Arora
//SFU ID- 301466934
//date- 17th June,2022
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>

using namespace std;


int main ()
{
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    t = S.getnext();
    while(t.tt!=eof  || !opstack.isEmpty())
    {
        if(t.tt==integer)
        {
            numstack.push(t);
            t= S.getnext();
        }
        else  if (t.tt==lptok)
        {
            opstack.push(t);
            t= S.getnext();
        }
        else if(t.tt==rptok)
        {
            Token t1= opstack.peek();
            if(t1.tt==lptok)
            {
                opstack.pop();
                t= S.getnext();
            }
            else
            {
                Token t1=numstack.pop();
                Token t2=numstack.pop();
                Token t3=opstack.pop();
                Token result;
                if(t3.tt == pltok)
                {
                    result.val = t1.val + t2.val;
                }
                else if (t3.tt == mitok)
                {
                    result.val= t2.val- t1.val;
                }
                else if(t3.tt==asttok)
                {
                    result.val=t1.val*t2.val;
                }
                else if(t3.tt==slashtok)
                {
                    result.val=t2.val/t1.val;
                }
                numstack.push(result);
            }
        }
        else if(t.tt==pltok || t.tt==mitok || t.tt==eof)
        {
            if(!opstack.isEmpty() && (opstack.peek().tt==pltok || opstack.peek().tt==mitok || opstack.peek().tt==asttok || opstack.peek().tt==slashtok))
            {
                Token t1=numstack.pop();
                Token t2=numstack.pop();
                Token t3=opstack.pop();
                Token result;
                if(t3.tt == pltok)
                {
                    result.val = t1.val + t2.val;
                }
                else if (t3.tt == mitok)
                {
                    result.val= t2.val- t1.val;
                }
                else if(t3.tt==asttok)
                {
                    result.val=t1.val*t2.val;
                }
                else if(t3.tt==slashtok)
                {
                    result.val=t2.val/t1.val;
                }
                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t=S.getnext();
            }
        }
        else if(t.tt==asttok || t.tt==slashtok)
        {
            if(!opstack.isEmpty() && (opstack.peek().tt==asttok || opstack.peek().tt==slashtok))
            {
                Token t1=numstack.pop();
                Token t2=numstack.pop();
                Token t3=opstack.pop();
                Token result;
                if(t3.tt == pltok)
                {
                    result.val = t1.val + t2.val;
                }
                else if (t3.tt == mitok)
                {
                    result.val= t2.val- t1.val;
                }
                else if(t3.tt==asttok)
                {
                    result.val=t1.val*t2.val;
                }
                else if(t3.tt==slashtok)
                {
                    result.val=t2.val/t1.val;
                }
                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t=S.getnext();

            }
        }
    }
    cout << numstack.peek().val << endl;
    cout << endl;
    return 0;
}

