# Display error if:
- non numeric parameters except one  - + for each number - DONE
- There are a duplicate numeric parameter - DONE
- dont accept values bigger or lower than MAX MIN_INT

# Display prompt if:
- if no paramters are passed, give the prompt back - DONE 

# Display nothing if:
- list already sorted - DONE

# When list have 3 numbers:
- max operations is 3 - DONE

# When list of operations is 5:
- max operations is 5

# When list of operations is 100:
- try less than 700

# When list of operations is 500:
- try less than 5500




# Pseudocode 
1 - atol -> transform string into long and with this we can check if it is bigger or lower than MAX MIN_INT

2 - check if number already exis -> There are a duplicate numeric parameter

3 - append node to stack a

4 - is diferent if ac = 2 because we have argv in the heap needed to be released