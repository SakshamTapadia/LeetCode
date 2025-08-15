mod=10**9+7
class Solution:
    def sumOfFlooredPairs(self, nums: List[int]) -> int:
        mx,res=max(nums),0
        tree=[0]*4*mx
        cnt=Counter(nums)

        def addVal(idx,val):
            idx+=1
            while idx<len(tree):
                tree[idx]+=val
                idx+=idx&(-idx)

        def getVal(idx):
            res,idx=0,idx+1
            while idx>0:
                res+=tree[idx]
                idx-=idx&(-idx)
            return res            

        for i in nums:
            addVal(i,1)

        for i in range(1,mx+1):
            freq=cnt[i]  
            if not freq:continue          
            for j in range(i,mx+1,i):                
                d=j//i                
                left,right=max(0,j),min(mx,j+i-1)                
                tot=getVal(right)-getVal(left-1)
                res+=freq*tot*d
                res%=mod

        return res