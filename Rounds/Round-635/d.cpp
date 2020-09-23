#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iostream>

using namespace std;

#define debug(x) cout<<x<<endl;

int main () {
	int t;
	cin>>t;
	while (t--) {
		int r,g,b;
		scanf("%d %d %d",&r,&g,&b);
		vector <pair<int,char> > nums(r+g+b);
		for (int i=0;i<r;i++) {
			scanf("%d",&nums[i].first);
			nums[i].second='r';
		}
		for (int i=0;i<g;i++) {
			scanf("%d",&nums[i+r].first);
			nums[i+r].second='g';
		}
		for (int i=0;i<b;i++) {
			scanf("%d",&nums[i+r+g].first);
			nums[i+r+g].second='b';
		}
		sort(nums.begin(),nums.end());
		long long rval=-1,gval=-1,bval=-1;
		int counter=0;
		while (!(rval>0 && gval>0 && bval>0)) {
			if (nums[counter].second=='r' && rval<0) {
				rval=nums[counter].first;
			}
			else if (nums[counter].second=='b' && bval<0) {
				bval=nums[counter].first;
			}
			else  if (nums[counter].second=='g' && gval<0) {
				gval=nums[counter].first;
			}
			counter++;
		}
		vector <int> blueindex(b);
		vector <int> redindex(r);
		vector <int> greenindex(g);
		int bcounter=0,rcounter=0,gcounter=0;
		for (int i=0;i<r+g+b;i++) {
			if (nums[i].second=='b') {
				blueindex[bcounter++]=i;
			}
			else if (nums[i].second=='g') {
				greenindex[gcounter++]=i;
			}
			else {
				redindex[rcounter++]=i;
			}
		}
		//printf("%lld %lld %lld\n",rval,gval,bval);
		long long diff1,diff2,diff3;
		long long min=-1;
		long long current,temp1,temp2,temp3;
		rcounter=-1;gcounter=-1;bcounter=-1;
		for (int i=0;i<(r+g+b);i++) {
			//printf("%d %c\n",nums[i].first,nums[i].second);
			if (nums[i].second=='r') {
				rval=nums[i].first;
				rcounter++;
			}
			else if (nums[i].second=='b') {
				bval=nums[i].first;
				bcounter++;
			}
			else {
				gval=nums[i].first;
				gcounter++;
			}
			//printf("%lld %lld %lld\n",rval,gval,bval);
			diff1=rval-bval;
			diff2=rval-gval;
			diff3=gval-bval;
			temp1=rval;
			temp2=gval;
			temp3=bval;
			if (min==-1) {
				min=diff1*diff1+diff2*diff2+diff3*diff3;
			}
			else {
				current=diff1*diff1+diff2*diff2+diff3*diff3;
				if (current<min) {
					min=current;
				}
			}
			if (rcounter>0 && gcounter>0 && bcounter>0) {
				if (nums[i].second=='r') {
					if (gcounter+1<g) {
						gval=nums[greenindex[gcounter+1]].first;
					}
					diff1=rval-bval;
					diff2=rval-gval;
					diff3=gval-bval;
					current=diff1*diff1+diff2*diff2+diff3*diff3;
					if (current<min) {
						min=current;
					}
					gval=temp2;
					if (bcounter+1<b) {
						bval=nums[blueindex[bcounter+1]].first;
					}
					diff1=rval-bval;
					diff2=rval-gval;
					diff3=gval-bval;
					current=diff1*diff1+diff2*diff2+diff3*diff3;
					if (current<min) {
						min=current;
					}
					bval=temp3;
				}
				else if (nums[i].second=='g') {
					if (rcounter+1<r) {
						rval=nums[redindex[rcounter+1]].first;
					}
					diff1=rval-bval;
					diff2=rval-gval;
					diff3=gval-bval;
					current=diff1*diff1+diff2*diff2+diff3*diff3;
					if (current<min) {
						min=current;
					}
					rval=temp1;
					if (bcounter+1<b) {
						bval=nums[blueindex[bcounter+1]].first;
					}
					diff1=rval-bval;
					diff2=rval-gval;
					diff3=gval-bval;
					current=diff1*diff1+diff2*diff2+diff3*diff3;
					if (current<min) {
						min=current;
					}
					bval=temp3;
				}
				else {
					if (gcounter+1<g) {
						gval=nums[greenindex[gcounter+1]].first;
					}
					diff1=rval-bval;
					diff2=rval-gval;
					diff3=gval-bval;
					current=diff1*diff1+diff2*diff2+diff3*diff3;
					if (current<min) {
						min=current;
					}
					gval=temp2;
					if (rcounter+1<r) {
						rval=nums[redindex[rcounter+1]].first;
					}
					diff1=rval-bval;
					diff2=rval-gval;
					diff3=gval-bval;
					current=diff1*diff1+diff2*diff2+diff3*diff3;
					if (current<min) {
						min=current;
					}
					rval=temp1;
				}
			}
		}
		printf("%lld\n",min);
	}
}