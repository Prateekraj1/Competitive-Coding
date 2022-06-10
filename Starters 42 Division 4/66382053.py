# cook your dish here
itera=int(input())
for i in range(itera):
    j=int(input())
    lst=input()
    lst=list(lst)
    count=1
    for i in range(len(lst)-1):
        if(lst[i]=="1" and lst[i+1]=="0"):
            count+=1
    print(count)