#include <bits/stdc++.h>
#define DEBUG

using namespace std;
typedef long long ll;

#ifdef DEBUG
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void print(int n, vector <int> arr) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  cout << '\n';
}


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;

  int n = (1 << k);
  int xr = 0;
  vector <int> b(n);

  for (int &x : b) {
    cin >> x;
    xr ^= x;
  }

  if (xr) {
    cout << "Fou\n";
    return 0;
  }

  cout << "Shi\n";
  vector <int> p(n), q(n), ind(n), a(n);
  
  for (int i = 0; i < n; i++) {
    p[i] = i;
    q[i] = i;
    ind[i] = i;
  } 

  function<void(int, int)> fix = [&](int i, int j) { 
    if (q[i] == (p[i] ^ a[i]))
      return;
    
    if (q[i] == (p[i] ^ a[j])) {
      
      swap(q[i], q[j]);
      swap(p[i], p[j]);
      swap(ind[p[i]], ind[p[j]]);

    } else if (q[i] == (p[j] ^ a[i])) {

      swap(p[i], p[j]);
      swap(ind[p[i]], ind[p[j]]);

    } else if (q[i] == (p[j] ^ a[j])) {

      swap(q[i], q[j]);

    } else {

      int t = ind[a[i] ^ q[i]];
      
      swap(ind[p[t]], ind[p[i]]);
      swap(p[t], p[i]);
      swap(q[t], q[i]);
      swap(q[t], q[j]);
      swap(q[i], q[j]);

      fix(t, j);
    }
  };

  for (int i = 0; i + 1 < n; i++) {
    a[i + 1] ^= (a[i] ^ b[i]); // a[i-1]^b[i-1]^b[i] -->>> b[0]^b[1]^ ... b[i]
    // printf("a+1:%d\n", a[i] ^ b[i]);
    a[i] = b[i];

    fix(i, i + 1);
  }

  print(n, p);
  print(n, q);

}


//Way-2
#include<bits/stdc++.h>
 
using namespace std;
 
int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
 
int n,ncnt;
int a[5005],p[5005],q[5005],dp[5005],dq[5005],tmp[5005];
 
int main(){
	n=1<<readint();
	int sum=0;
	for(int i=1;i<=n;i++) a[i]=readint(),sum^=a[i];
	if(sum) return printf("Fou\n"),0;
	memset(p,-1,sizeof(p));
	memset(q,-1,sizeof(q));
	while(1){
		int now=-1;
		for(int i=1;i<=n;i++){
			if(p[i]<0){
				now=i;
				break;
			}
		}
		if(now<0) break;
		for(int i=0;i<n;i++){
			if(!dp[i]&&!dq[a[now]^i]){
				p[now]=i,q[now]=a[now]^i,dp[i]=now,dq[a[now]^i]=now;
				break;
			}
		}
		if(p[now]<0){
			ncnt=0;
			for(int i=0;i<n;i++) if(!dp[i]) tmp[++ncnt]=i;
			int th=rand()%ncnt+1,g=a[now]^tmp[th];
			p[now]=tmp[th],dp[tmp[th]]=now,q[now]=g,dp[p[dq[g]]]=0,p[dq[g]]=-1,q[dq[g]]=-1,dq[g]=now;
		}
	}
	printf("Shi\n");
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",q[i]);
	printf("\n");
	return 0;
}
