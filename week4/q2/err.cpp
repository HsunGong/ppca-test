#include <bits/stdc++.h>

using namespace std;
int S(int num)
{
    int sum(0);
    while (num >= 1)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int run()
{
    double n;
    cin >> n;
    int o(0), i;
    for (i = 1; i <= 500000; i++)
    {
        if (S(i * n) == S(i) / n)
        {
            o = 1;
            break;
        }
    }
    if (o)
        cout << i << '\n';
    else
        cout << -1 << '\n';
}

int main() {
	int size;
	cin >> size;
	for (int xxx = 0; xxx < size; ++xxx) 
	run();
}