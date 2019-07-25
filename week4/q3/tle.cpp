#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[105],b[105],l;
long long gcd(long long x, long long y){
    if(x > y){
        if(x % y == 0)
            return y;
        else return gcd(x % y, y);
    }
    else{
        if(y % x == 0)
            return x;
        else return gcd(x, y % x);
    }
}
int run(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%i64d",&a[i]);
        scanf("%i64d",&b[i]);
    }
    l = a[0];
    for(int i = 1; i < n; i++)
        l = a[i] * l / gcd(l, a[i]);
    int checker = 0;
    for(int i = 0; i < n; i++){
        while(1){
            if(a[i] == l)
                break;
            else if (a[i] > l){
                checker = 1;
                break;
            }
            else {
                a[i] *= b[i];
            }
        }
    }
    if(checker == 1)
        printf("-1\n");
    else
        printf("%lld\n", l);
}
#include <iostream>
using namespace std;
int main()
{
    // run();
    int cnt = 0;
    cin >> cnt;
    while (!cin.eof()){
        cnt ++;
    // printf("Will print %d: ", cnt);
        run();
    }
}