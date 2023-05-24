#Problem Link : https://drive.google.com/file/d/1oDUwbQZrLLnaXVqUYbw1862mFGEqM7Ij/view
a = input()
b = input()

count = 0 
i = 0 
j = 0 
while j<len(a):
    if a[j]==b[i]:
        i+=1
    j+=1

print(len(b)-i)
