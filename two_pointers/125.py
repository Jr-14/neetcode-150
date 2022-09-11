""" Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
"""

def main():
    str_input = input("")
    str_input = "".join([i for i in str_input if i.isalpha()])
    str_input = str_input.lower().replace(" ", "").strip()
    print(str_input)

if __name__ == "__main__":
    main()