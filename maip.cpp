
#include<bits/stdc++.h>
using namespace std;
int Ans[100];
int numb = 0;

void Ispalimore(string letters)
{

   while ( true )
    {
        std::stack<char>
            s( std::stack<char>::container_type( letters.begin(), letters.end() ) );
        std::queue<char>
            q( std::queue<char>::container_type( letters.begin(), letters.end() ) );

        while ( !s.empty() && s.top() == q.front() )
        {
            s.pop();
            q.pop();
        }

        if ( s.empty()){

            if( stoi(letters) % 2 != 0)
            {
            numb++;
                Ans[numb] = stoi(letters);
            }
break;
        }
        else
        {

            break;
        }
}



}


int main()
{
int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
stringstream ss;
ss << i;
string str = ss.str();
    Ispalimore(str);

    }

     for(int i = 1; i <= numb; i++)
     {
         cout << Ans[i] << " ";
     }

    return 0;
}
