# cook your dish here
itera=int(input())
for i in range(itera):
    x,y,a=input().split(" ")
    x=int(x);y=int(y);a=int(a)
    if(a>=x and a<y):
        print("YES")
    else:
        print("NO")