""" Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
"""


from typing import List
import operator
from math import floor

def main(tokens: List[str]):
    stack = []
    operators = {
        '+': operator.add,
        '-': operator.sub,
        "*": operator.mul,
        "/": operator.truediv
    }
    for i in range(len(tokens)):
        token = tokens[i]
        if token in operators:
            first = int(stack.pop())
            second = int(stack.pop())
            evaluated = operators[token](second, first)
            print(evaluated)
            stack.append(evaluated)
        else:
            stack.append(token)
    return floor(int(stack.pop()))
            
        

if __name__ == "__main__":
    my_list = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    main(my_list)