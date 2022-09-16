"""
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function
"""

class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        min = self.getMin()
        if min is None or val < min:
            self.stack.append((val, val))
        else:
            self.stack.append((val, min))

    def pop(self) -> None:
        if self.stack:
            return self.stack.pop()[0]
        return None

    def top(self) -> int:
        if self.stack:
            return self.stack[-1][0]
        return None


    def getMin(self) -> int:
        if self.stack:
            return self.stack[-1][1]
        return None
        