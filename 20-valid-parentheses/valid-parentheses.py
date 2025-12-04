class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        helper = {")":"(","}":"{","]":"["}
        for c in s:
            if c in helper:
                if stack and stack[-1] == helper.get(c,False):
                    stack.pop()
                else :
                    return False
            else:
                stack.append(c)
        return len(stack) == 0