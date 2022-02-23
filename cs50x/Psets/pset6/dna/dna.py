
import csv
import sys

 
def main():
     
    # Ensure correct usage 
    if len(sys.argv) != 3:
        sys.exit('Usage: python dna.py data.csv sequence.txt')
    
    # Database
    data = []
    # Counter
    count = 0
    
    # Read database into memory from file
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        # Loops through rows
        for row in reader:
                    
            # Save data
            data.append(row)
            
    # Read sequence into memory from file
    with open(sys.argv[2]) as f:
        sequence = f.read()
        
    # STR
    result = [0]
    # STR check fuction
    result = dna_result(result, data, sequence)
    # Check who is the owner of the DNA sequence
    STR_match(result, data)
                    
                    
def dna_result(result, data, sequence):

    # Loops over the STR in the database
    for i in range(1, len(data[0])):
        c = 0
        skip = 0
        result.append(0)
        
        # Loops over DNA sequence
        for j in range(len(sequence)):
            if skip == 0:
                
                # Try to match the DNA in the sequence to the one in the database
                if data[0][i] in sequence[j:len(data[0][i])+j]:
                    c += 1
                    skip = len(data[0][i]) - 1
                    mark = 1
                        
                # If it doesn't match, reset the variable
                else:
                    mark = 0
            else:
                skip -= 1
                
            # Record the result and checks if repeats
            if result[i] < c:
                result[i] = c
                    
            # If does not repeat, reset the variable
            elif mark == 0 and skip == 0:
                c = 0
                    
    # Return result                
    return result
    
        
def STR_match(result, data):
    
    # Counter (i like counters <3)
    counter = 0
    # Name
    name = 'name'
    
    # Loops over the database
    for i in range(1, len(data)):
        
        # Loops over the STR results and database STR 
        for j in range(1, len(data[0])):
            
            # Try to match the result STR to the database STR
            if int(data[i][j]) == result[j]:
                counter += 1
                
            # If doesn't match, reset the variable and go to the next person
            else:
                counter = 0
                break
            
            # If all the nucleotides match, print the name of the DNA owner and exit the program 
            if counter == len(data[0])-1:
                name = data[i][0]
                sys.exit(print(name))
        
    # If the STR counts do not match with any of the individuals in the database print 'No match'
    sys.exit(print('No match'))


main()