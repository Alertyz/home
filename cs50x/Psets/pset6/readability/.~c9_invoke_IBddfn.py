from cs50 import get_string
import ctype

def main():
    text = get_string('Text: ')

    counter = 0

    for i in len(text):
        if ctype.isalpha(text[i]):
            counter += 1
    
    l = counter
    counter = 0

    for i in len(text):
        if ctype.isspace(text[i]):
            counter += 1

    w = counter
    counter = 0

    for i in len(text):
        if text[i] == 33 or text[i] == 46 or text[i] == 63:
            counter += 1

    s = counter
    
    L = rule_three(l, w)
    
    
    
    
    def rule_three

