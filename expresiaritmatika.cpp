/*

- Alif Akbar Kartadinata (2017051049)
- Arib Yusron Hamdani (2017051078)
- Rifan Setiadi (2017051019)

*/

#include <bits/stdc++.h>
using namespace std;

bool isOp(char _isOp)
{
    return (_isOp == '+' || _isOp == '-' || _isOp == '*' || _isOp == '%' || _isOp == '/' || _isOp == '(');
}

int main()
{
    string inptStr;
    char _inptCh;
    while(cin.get(_inptCh))
    {
        if(_inptCh == '\n')
        {
            break;
        }
        if(_inptCh != ' ')
        {
            inptStr.push_back(_inptCh);
        }
    }
    string tmp;
    vector <string> infix;
    vector <string>::iterator it;
    vector <string>::iterator itNew;
    int length = inptStr.length();
    for(int i = 0; i < length; i++)
    {
        if(isdigit(inptStr[i]) || (i == 0 && inptStr[i] == '-' && inptStr[i + 1] != '(')){
            tmp.push_back(inptStr[i]);
            continue;
        }
        else if(tmp.length() != 0)
        {
            infix.push_back(tmp);
            tmp.clear();
        }

        if(inptStr[i] == '-' && (isOp(inptStr[i - 1]) || (i == 0 && inptStr[i + 1] == '(')))
        {
            infix.push_back("-1");
            infix.push_back("*");
        }
        else if(inptStr[i] != ' ')
        {
            infix.push_back(inptStr.substr(i, 1));
        }
    }

    if(tmp.length() != 0)
    {
        infix.push_back(tmp);
        tmp.clear();
    }

    vector <string>::iterator parsing;
    for(parsing = infix.begin(); parsing != infix.end(); parsing++)
    {
        cout << *parsing << " ";
    }
  
    return 0;
}
