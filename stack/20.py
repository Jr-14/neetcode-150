""" Valid Parenthesis

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
"""

def main():
    def match_parent(o, c):
        if o == "(" and c == ")":
            return True
        if o== "{" and c == "}":
            return True
        if o== "[" and c == "]":
            return True
        return False

    avail_strings = "(){}[]"
    closing_parent = ")}]"
    stack = []
    str_input = input("")
    for char in str_input:
        stack.append(char)
        if char in closing_parent:
            if len(stack) < 2:
                return False
            pen_char = stack[-2]
            last_char = stack[-1]
            if match_parent(pen_char, last_char):
                stack.pop()
                stack.pop()
            else:
                return False

    if len(stack):
        return False
    return True

    



if __name__ == "__main__":
    val = main()
    print(val)