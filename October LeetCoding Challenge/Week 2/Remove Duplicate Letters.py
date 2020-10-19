class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last_idxs, res = {l: i for i, l in enumerate(s)}, ""
        for i, l in enumerate(s):
            if l not in res:
                while res and res[-1] > l and i < last_idxs[res[-1]]:
                    res = res[:-1]
                res += l
        return res
