n=int(input())
a=[]
m=0
ind=-1
x=list(input().split(' '))
#print(x)
for i in range(n): 
	a.append(int(x[i]))	
	if a[i]>=m:
		ind=i;
a=sorted(a)
print(a)
mi=a[len(a)-1]
for i in range(n):
	if a[i]==mi: 
		break;
	for j in range(i+1,n):
		if (a[i]|a[j])>a[i]:
			temp=a[i]
			a[i]=a[j]|a[i]
			a[j]=a[j]&temp
		if mi<a[j]:
			mi=a[j]	
ans=0
for i in range(n):
	ans+=(a[i]*a[i])
print(ans)
