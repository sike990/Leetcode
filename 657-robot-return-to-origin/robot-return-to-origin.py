class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x = 0
        y = 0
        for ch in moves:
            if ch == 'L':
                x -= 1
            elif ch == 'R':
                x += 1
            elif ch == 'U':
                y += 1
            else:
                y -= 1
        return (y == 0 and x == 0)