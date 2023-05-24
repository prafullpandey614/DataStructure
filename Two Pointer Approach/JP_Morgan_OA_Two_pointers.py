# Problem link : https://www.desiqna.in/12812/morgan-sde1-coding-questions-and-solutions-india-april-2023

n = int(input())
k = int(input())
a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
st = 0 
end = 0 
maxi = -1e9
cnt = 0
while end<n:
    if a[end]<=maxi:
        st = end 
        maxi = a[end]
        end+=1
    else:
        if end-st+1<k:
            maxi = a[end]
            end+=1
            
        else :
            cnt+=1
            st+=1
            maxi = a[end]
            end+=1
print(maxi)
print(cnt)
