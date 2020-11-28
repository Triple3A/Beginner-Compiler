#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int num_outs = 0, b;
    int f = 0;
    int errr = 0;
    int num_lines = 0;
    map <string, int> a;
    vector <string> line;
    string _word = "";
    while(_word != "run")
    {
        getline(cin, _word);
        line.push_back(_word);
        num_lines++;
    }
    vector <int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    char word[40];
    int num_input = 0, p = 0;
    vector <int> out;
    for(int i = 0; i < num_lines - 1; i++)
    {
        int flag = 0;
        f = 0;
        vector <string> words;
        for(int j = 0; j < line[i].size(); j++)
        {
            int k = j;
            while(j < line[i].size() && line[i][j] != ' ' && line[i][j] != '=' && line[i][j] != '+' && line[i][j] != '-' && line[i][j] != '!' && line[i][j] != '?')
            {
                word[j - k] = line[i][j];
                if((line[i][j] >= 'A' && line[i][j] <= 'Z') || (line[i][j] >= 'a' && line[i][j] <= 'z'))
                    if((word[0] < 'A' || (word[0] > 'Z' && word[0] < 'a') || word[0] > 'z') && flag == 0)
                    {
                        cout << "Syntax error at line " << i + 1 << endl;
                        errr = 1;
                        flag = 1;
                    }
                if(line[i][j] < '0' || line[i][j] > '9')
                    if(word[j - k] < 'A' || (word[j - k] > 'Z' && word[j - k] < 'a') || word[j - k] > 'z')
                    {
                        cout << "Syntax error at line " << i + 1 << endl;
                        errr = 1;
                    }
                f = 0;
                p = 1;
                j++;
            }
            if(p == 1)
            {
                word[j-k] = '\0';
                words.push_back(word);
                char word[40];
                p = 0;
            }
            if(line[i][j] == '=' || line[i][j] == '+' || line[i][j] == '-' || line[i][j] == '!' || line[i][j] == '?')
            {
                word[0] = line[i][j];
                if(f == 0)
                    f = 1;
                else
                {
                    cout << "Syntax error at line " << i + 1 << endl;
                    errr = 1;
                }
                word[1] = '\0';
                words.push_back(word);
                char word[40];
            }
        }
        if(errr == 0 && words.size() != 0)
        {
            int sum = 0;
            switch(words[0][0])
            {
                case '?':
                    if(words.size() > 2)
                    {
                        cout << "Syntax error at line " << i + 1 << endl;
                        errr = 1;
                    }
                    else
                    {
                        if(num_input >= input.size())
                        {
                            errr = 2;
                            b = num_outs;
                        }
                        a[words[1]] = input[num_input];
                        num_input++;
                    }
                    break;
                case '!':
                    if(words.size() > 2)
                    {
                        cout << "Syntax error at line " << i + 1 << endl;
                        errr = 1;
                    }
                    else
                        {
                            out.push_back(a[words[1]]);
                            num_outs++;
                        }
                    break;
                case '=':
                    cout << "Syntax error at line " << i + 1 << endl;
                    errr = 1;
                    break;
                case '+':
                    cout << "Syntax error at line " << i + 1 << endl;
                    errr = 1;
                    break;
                case '-':
                    cout << "Syntax error at line " << i + 1 << endl;
                    errr = 1;
                    break;
                default:
                    if(words[0][0] >= '0' && words[0][0] <= '9')
                    {
                        cout << "Syntax error at line " << i + 1 << endl;
                        errr = 1;
                    }
                    else if(words[1] != "=")
                    {
                        cout << "Syntax error at line " << i + 1 << endl;
                        errr = 1;
                    }
                    else
                    {
                        for(int j = 2; j < words.size(); j++)
                        {
                            if(words[j][0] >= '0' && words[j][0] <= '9')
                                a[words[j]] = stoi(words[j]);
                            switch(words[j - 1][0])
                            {
                                case '+':
                                    sum += a[words[j]];
                                    break;
                                case '-':
                                    sum -= a[words[j]];
                                    break;
                                case '=':
                                    if(j != 2)
                                    {
                                        cout << "Syntax error at line " << i + 1 << endl;
                                        errr = 1;
                                    }
                                    break;
                                default:
                                    if(j == words.size() - 1)
                                    {
                                        cout << "Syntax error at line " << i + 1 << endl;
                                        errr = 1;
                                    }
                                    break;
                            }
                        }
                        sum += a[words[2]];
                        a[words[0]] = sum;
                        sum = 0;
                    }
                    break;
            }
        }
    }
    if(errr == 0)
        for(int i = 0; i < out.size(); i++)
            cout << out[i] << endl;
    if(errr == 2)
    {
        for(int i = 0; i < b; i++)
            cout << out[i] << endl;
        cout << "Unexpected end of input" << endl;
    }
    return 0;
}
#Beginner-Compiler
