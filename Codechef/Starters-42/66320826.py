# cook your dish here
T=int(input())
for i in range(T):
    a,b=input().split(" ")
    if(a==b):
        print("YES")
        continue
    a=int(a);b=int(b)
    if((a+b)%2==0):
        print("YES")
    else:
        print("NO")