# Import get_string from cs50 library
from cs50 import get_int
from sys import exit

# Ask for the credit card number
credit = get_int('Number: ')
# Lenght of the credit card number
lenght = len(str(credit))

# If the credit card number is not between 13 or 16 print invalid
if lenght <= 13 and lenght >= 16:
    print('INVALID')
    exit(0)
# Copy the credit card number to a string
copy = str(credit)
count = 0

# Checksum
for i in range(lenght - 1, lenght, -1):
    if (i % 2) == 0:
        count = int(copy[i]) + count
    else:
        number = int(copy[i])
        number *= 2
        if number >= 10:
            count += number % 10
            count += 1
        else:
            count += number
if (count % 10) != 0:
    print('INVALID')
    exit(0)

# Print name of the credit card
count = int(copy[0])

if count == 4:
    print('VISA')
    exit(0)
    
count *= 10
count += int(copy[1])

if count == 34 or count == 37:
    print('AMEX')
    exit(0)
elif count >= 51 and count <= 55:
    print('MASTERCARD')
    exit(0)
else:
    print('INVALID')
    exit(0)