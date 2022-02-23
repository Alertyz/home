# Import get_int from cs50 library
from cs50 import get_int

# Prompt for height and rejects values that are greater than 8 and less than 1
while True:
    height = get_int('Height: ')
    if height >= 1 and height <= 8:
        break
    
# Print Pyramid
copy = height
for i in range(height):
    copy -= 1
    for j in range(copy):
        print(' ', end="")
    for j in range(-1, i):
        print('#', end="")
    for j in range(2):
        print(' ', end="")
    for j in range(-1, i):
        print('#', end="")
    print()