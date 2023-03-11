#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int N, V;
    cin >> N;
    int colors[N];

    for (int i = 0; i < N; i++)
    {
        cin >> V;
        if (V == -1)
            colors[i] = 1;
        else
            colors[i] = 0;
    }

    int zeroLeft = -1, zeroRight = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        if (!colors[i])
        {
            if (!count)
                zeroLeft = i;
            else
                zeroRight = i;

            if (zeroRight)
            {
                int color = 1;
                int pos = 1;
                int middle = 1;
                for (int c = zeroRight - 1; c > zeroLeft; c--)
                {
                    colors[c] = color;
                    if (zeroLeft >= 0)
                    {
                        if (((zeroRight - zeroLeft) / 2) > middle)
                            pos++;
                        else if (((zeroRight - zeroLeft) / 2) < middle)
                            pos--;
                        else
                        {
                            if ((zeroRight - zeroLeft) % 2 == 0)
                                pos--;
                        }
                        middle++;
                    }
                    else
                        pos++;
                    if (pos > 9)
                        color = 9;
                    else
                        color = pos;
                }
                zeroLeft = zeroRight;
                zeroRight = 0;
                count = 0;
            }
        }

        if (colors[i])
        {
            count++;
            int color = count;
            if (count > 9)
                color = 9;
            if (i + 1 == N)
            {
                for (int c = N - 1; c > zeroLeft; c--)
                {
                    colors[c] = color;
                    count--;
                    if (count < 9)
                        color--;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << colors[i] << " ";
    }

    return 0;
}