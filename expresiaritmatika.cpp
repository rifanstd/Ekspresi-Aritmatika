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

bool isOperator(char _isOp)
{
    return (_isOp == '+' || _isOp == '-' || _isOp == '*' || _isOp == '%' || _isOp == '/');
}

int precedence(char _isPre)
{
    if(_isPre == '*' || _isPre == '/' || _isPre == '%')
    {
        return 2;
    }
    else
    {
        return 1;
    }
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

//     cout << "Print : ";
//     vector <string>::iterator parsing;
//     for(parsing = infix.begin(); parsing != infix.end(); parsing++)
//     {
//         cout << *parsing << " ";
//     }
    
    stack <string> S;
    vector <string> P;
    int i = 0;
    for(it = infix.begin(); it != infix.end(); it++)
    {
        if(isdigit(infix[i].back()))
        {
            P.push_back(infix[i]);
        }
        else if(infix[i] == "(")
        {
            S.push(infix[i]);
        }
        else if(infix[i] == ")")
        {
            while(!S.empty() && S.top() != "(")
            {
                P.push_back(S.top());
                S.pop();
            }
            S.pop();
        }
        else if(isOperator(infix[i][0]))
        {
            if(S.empty() || S.top() == "(")
            {
                S.push(infix[i]);
            }
            else
            {
                while(!S.empty() && S.top() != "(" && (precedence(infix[i][0]) <= precedence((S.top())[0])))
                {
                    P.push_back(S.top());
                    S.pop();
                }
                S.push(infix[i]);
            }
        }
        i++;
    }

    while(!S.empty())
    {
        P.push_back(S.top());
        S.pop();
    }
    
//     cout << "Print : ";
//     for(itNew = P.begin(); itNew != P.end(); itNew++)
//     {
//         cout << *itNew << " ";
//     }
    
    stack<string>Ss;
    vector<string>::iterator pit;
    double A, B, result;
    i = 0;
    for (pit = P.begin(); pit != P.end(); pit++){
    	if (isdigit(P[i].back())){
    		Ss.push(P[i]);
    	}
    	else if (isOperator(P[i][0])){
    		A = strtod((Ss.top()).c_str(),NULL);
    		Ss.pop();
    		B = strtod((Ss.top()).c_str(),NULL);
    		Ss.pop();

    		if (P[i] == "+"){
    			result = B + A;
    		}
    		else if (P[i] == "-"){
    			result = B - A;
    		}
    		else if (P[i] == "/"){
    			result = B / A;
    		}
    		else if (P[i] == "*"){
    			result = B * A; 
    		}
    		else if (P[i] == "%"){
    			result = (int)B % (int)A;
    		}
    		Ss.push(to_string(result));
    	}
    	i++;
    }
    cout << strtod((Ss.top()).c_str(),NULL) << endl;
  
    return 0;
}
