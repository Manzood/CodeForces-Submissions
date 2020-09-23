#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<cstring>

using namespace std;

#define debug(x) cout<<x<<endl;

int check (char *s,int start, int end) {
	for (int i=start;i<(end-start+1)/2+start;i++) {
		if (s[i]!=s[end+start-i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int t;
	cin>>t;
	char s[1000000];
	while (t--) {
		int ansstart=-1, ansend=-1;
		scanf("%s",s);
		long long len=strlen(s);
		//from left
		for (int i=0;i<len;i++) {
			if (s[i]==s[0]) {
				if (check(s,0,i)) {
					ansstart=0;
					ansend=i;
				}
			}
		}
		//from right
		for (int i=len-1;i>=0;i--) {
			if (s[i]==s[len-1]) {
				if (check(s,i,len-1)) {
					if ((len-1-i)>(ansend-ansstart)) {
						ansstart=i;
						ansend=len-1;
					}
				}
			}
		}
		//both
		int start=0,end=len-1;
		int left=0;
		while (s[start]==s[end] && start<end) {
			start++;
			end--;
		}
		if (start==end) {
			printf("%s\n",s);
		}
		else {
			//from left
			for (int i=start;i<end;i++) {
				if (s[i]==s[start]) {
					if (check(s,start,i)) {
						if ((i+start)>(ansend-ansstart)) {
							ansend=i;
							ansstart=0;
							left=1;
						}
					}
				}
			}
			for (int i=end;i>start;i--) {
				if (s[i]==s[end]) {
					if (check(s,i,end)) {
						if ((end-i+start)>(ansend-ansstart)) {
							ansend=len-1;
							ansstart=i;
							left=-1;
						}
					}
				}
			}
			if (left==-1) {
				//cout<<"Entered this loop";
				for (int i=0;i<start;i++) {
					printf("%c",s[i]);
				}
			}
			for (int i=ansstart;i<=ansend;i++) {
				printf("%c",s[i]);
			}
			if (left==1) {
				for (int i=len-start;i<len;i++) {
					printf("%c",s[i]);
				}
			}
			printf("\n");
		}
	}
}