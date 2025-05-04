class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n>2:
            if n%3:
                return False
            n//=3
        return n==1