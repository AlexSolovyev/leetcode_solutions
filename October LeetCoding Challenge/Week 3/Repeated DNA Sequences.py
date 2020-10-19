class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seq_freqs = Counter(s[i:i+10] for i in range(0, len(s) - 9))
        return [res for res in seq_freqs if seq_freqs[res] > 1]
