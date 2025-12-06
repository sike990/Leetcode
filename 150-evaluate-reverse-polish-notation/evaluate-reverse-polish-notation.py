class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for el in tokens:
            if el in ('*',"+","-","/"):
                el2 = stack[-1] 
                stack.pop()
                el1 = stack[-1]
                stack.pop()
                curr = None
                if el == "*":
                    curr = el1*el2
                elif el == "+":
                    curr = el1+el2
                elif el == "-":
                    curr = el1-el2
                else:
                    curr = trunc(el1/el2)
                stack.append(curr)
            else:
                stack.append(int(el))
        return stack[-1]