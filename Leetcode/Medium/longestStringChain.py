class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda w: -len(w))
        hashmap = {} #To map each word to its index in the list.

        for i,w in enumerate(words):
            hashmap[w] = i
        dp = {} #Hashmap for memoization
        def dfs(i):
            if i in dp:
                return dp[i]
            res = 1
            for j in range(len(words[i])):
                w = words[i]
                substr = w[:j] + w[j+1:]
                if substr in hashmap:
                    res = max(res,1 + dfs(hashmap[substr]))
            dp[i] = res
            return res

        for i in range(len(words)):
            dfs(i)
        return max(dp.values())