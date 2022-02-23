# Import get_string from cs50 library
from cs50 import get_string

# Ask user name
answer = get_string("What is your name?\n")

# Print hello with user name
print('hello, ' + answer)