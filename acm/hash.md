![image-20240921110005020](C:\Users\wzq\Desktop\c++\code\acm\assets\image-20240921110005020.png)

```c++
#include<iostream>
using namespace std;
typedef unsigned long long ull;//ull溢出相当于对2^64取模 
const int N=100010, P=131;//P一般取131或13331
int n,m;
char str[N];
ull h[N],p[N];
ull get(int l,int r){
	//求l~r一段的哈希值公式 
	return h[r]-h[l-1]*p[r-l+1];
} 
int main(){
	scanf("%d%d%s",&n,&m,str+1);
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*P;//求p的次幂 
		h[i]=h[i-1]*P+str[i];//求前缀哈希值 
	}
	while(m--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(get(l1,r1)==get(l2,r2)) puts("Yes");
		else puts("No");
	}
	return 0;
}

```

