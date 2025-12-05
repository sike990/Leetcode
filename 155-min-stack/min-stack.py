class MinStack:

    def __init__(self):
        self.stack = []
        self.currmin = None
    def push(self, val: int) -> None:
        if self.stack:
            self.currmin = min(val,self.currmin)
        else:
            self.currmin = val
        self.stack.append((val,self.currmin))

    def pop(self) -> None:
        if self.currmin == self.stack[-1][0]:
            if len(self.stack) > 1:
                self.currmin = self.stack[-2][1]
            else:
                self.currmin = None
        self.stack.pop()

    def top(self) -> int:
       return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()