#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int size;
        cin >> size;
        char s[size];
        cin >> s;
        string st = "";
        string chars = "";
        for (int c = 0; c < size; c++)
        {
            //cout << "I : " << s[c] << endl;
            chars += s[c];
            if (chars.size() > 0 && stoi(chars) / 27 > 0)
            {
                if (chars[chars.size() - 1] == '0')
                {
                    if (c + 1 < size && s[c + 1] == '0')
                    {
                        //cout << "be: " << chars << endl;
                        st += (char)((chars[0] - '0') + 'a' - 1);
                        chars.erase(chars.begin());
                        //cout << "Ereased:" << chars << endl;
                        st += (char)(stoi(chars) + 'a' - 1);
                        c++;
                        chars = "";
                    }
                    else
                    {
                        //cout << "be: " << chars << endl;
                        chars.erase(chars.begin() + chars.size() - 1);
                        //cout << "Ereased:" << chars << endl;
                        //cout << "?: " << (char)(stoi(chars) + 'a' - 1) << endl;
                        st += (char)(stoi(chars) + 'a' - 1);
                        chars = "";
                        //cout << "?2 :> " << chars << endl;
                    }
                }
                else
                {
                    //cout << "?: " << (char)((chars[0] - '0') + 'a' - 1) << endl;
                    st += (char)((chars[0] - '0') + 'a' - 1);
                    //cout << "be: " << chars << endl;
                    chars.erase(chars.begin());
                    //cout << "Ereased:" << chars << endl;
                }
            }
        }
        if (chars.size() > 0)
            for (int c = 0; c < chars.size(); c++)
                st += (char)((chars[c] - '0') + 'a' - 1);
        cout << st << endl;
    }

    return 0;
}