# Import get_float from cs50 library
from cs50 import get_float

# How much change is owed
while True:
    coins = get_float('Change owed: ')
    if coins >= 0:
        break

# Convert dollar to cents
coins = round(coins * 100)

# Number of coins used
change = 0


# If greater than or equal to subtract 25
while True:
    if coins < 25:
        break
    coins -= 25
    change += 1

# If greater than or equal to subtract 10
while True:
    if coins < 10:
        break
    coins -= 10
    change += 1

# If greater than or equal to subtract 5
while True:
    if coins < 5:
        break
    coins -= 5
    change += 1

# If greater than or equal to subtract 1
while True:
    if coins < 1:
        break
    coins -= 1
    change += 1

# Print change
print(change)
