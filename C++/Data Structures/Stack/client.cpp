/*Name:Visalakshi Gopalakrishnan
 Date:June 27 2013
 Assignment Number:CS2B a8
 Instructor:Dave Harden
 File: client.cpp

 This is an implemention client file for exception handling using try block,
 catch and throw block
*/

#include <iostream>
#include "stack.h"
#include "stack.cpp"

using std::cin;
using std::cout;
using std::endl;
using StackSavitch::Stack;

int main( )
{
    char next, ans;

    do
    {
        Stack<char> s;
        cout << "Enter a line of text:\n";
        cin.get(next);
        while (next != '\n')
        {
            s.push(next);
            cin.get(next);
        }

        try
        {
        cout << "Written backward that is:\n";
        cout << s.pop( );
        while ( ! s.isEmpty( ) )

            cout << s.pop( );
        }
        catch (PopEmptyStackException e)
        {
            cout << "Error: " << e.getMessage() << endl;
            cout << "Program aborting..\n";
            return 0;
        }
        cout << endl;
        cout << "Again?(y/n): ";
        cin >> ans;
        cin.ignore(10000, '\n');
    }while (ans != 'n' && ans != 'N');

    return 0;
}
