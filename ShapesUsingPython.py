length = 8
breadth = 20
#Spquare 
print("----------Spquare---------------")
for x in range(length):
    for y in range(breadth):
        if x == 0 or x == length-1:
            print ('*', end='')
        elif y == 0 or y == breadth-1:
            print ('*', end='')
        elif y != 0 or y != breadth-1:
            print (' ', end='')
    else:
        print ('')
#Filled Triagle      
print("----------Filled Triagle---------------")
for x in range(length):
    for y in range(x):
        if y == 0 or y != length-1:
            print ('*', end='')
    else:
        print('')   

#Unfilled Triagle - Upright  
print("----------Unfilled Triagle - Upright ---------------")
for x in range(length):
    for y in range(x+1):
        if y == 0 or y == x or x == length-1: 
            print (y, end='')
        else:
            print(' ', end='')
    else:
        print('')

#Unfilled Triagle - Downright
print("----------#Unfilled Triagle - Downright ---------------")

for x in range(length -1, 0, -1 ):
    for y in range(x+1):
        if y == 0 or y == x or x == length-1: 
            print (y, end='')
        else:
            print(' ', end='')
    else:
        print('')
print("----------paralleloGram2---------------")
for x in range(length):
    leading = ' ' * x
    if x == 0 or x == length-1:
        row = '*' * breadth
    else:
        row = '*' + ' ' * (breadth-2) + '*'
    
    print(leading + row)
    
