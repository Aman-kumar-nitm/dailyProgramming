# focus point
# finalans=[]
# ans=[arr[i]]
# count1=[0]*26
# ord(arr[j][k])-ord('a')
# ans.append()
class Solution:

    def findans(self,arr,vis,index,ans):
        count1=[0]*26
        for i in range(len(arr[index])):
            count1[ord(arr[index][i])-ord('a')]+=1
        for j in range(index+1,len(arr),1):
            count2=[0]*26
            for k in range(len(arr[j])):
                count2[ord(arr[j][k])-ord('a')]+=1
#match
            ismatch=True
            for m in range(26):
                if count1[m]!=count2[m]:
                    ismatch=False
                    break
            
            if ismatch==True:
                vis[j]=1
                ans.append(arr[j])
            
        return
    
    def anagrams(self, arr):

#code here
        finalans=[]
        vis=[0]*len(arr)
        for i in range(len(arr)):
            if vis[i]==0:
                vis[i]=1
                ans=[arr[i]]
                self.findans(arr,vis,i,ans)
                finalans.append(ans)
            
        finalans.sort()
        return finalans