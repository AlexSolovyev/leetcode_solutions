class RecentCounter:

    def __init__(self):
        self.requests = []
        self.cur_elem = 0

    def ping(self, t: int) -> int:
        self.requests.append(t)
        if len(self.requests) == 1:
            return 1
        else:
            size = len(self.requests)
            for i in range(self.cur_elem, size):
                if self.requests[-1] <= self.requests[i] + 3000:
                    self.cur_elem = i
                    return size - self.cur_elem


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
