# Import get_string from cs50 library
from cs50 import get_string

# Ask the user for text
text = get_string('Text: ')

# Counter
counter = 0

# Count how many letters are in the text
for i in text:
    if i.isalpha():
        counter += 1
l = counter
counter = 0

# Count how many words are in the text
for i in text:
    if i.isspace():
        counter += 1
w = counter
if text[len(text) - 1] == '!' or text[len(text) - 1] == '.' or text[len(text) - 1] == '?':
    w += 1
counter = 0

# Count how many senteences are in the text
for i in range(len(text)):
    if text[i] == '!' or text[i] == '.' or text[i] == '?':
        counter += 1
s = counter

# Average letters
r = l * 100
R = r / w
L = R

# Average sentences
r = s * 100
R = r / w
S = R

# Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

# Print the grade
if index > 17:
    print('Grade 16+')
elif index < 0:
    print('Before Grade 1')
else:
    print('Grade ' + str(index))