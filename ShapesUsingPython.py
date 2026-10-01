length = 8
breadth = 20
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
        
for x in range(length):
    for y in range(x):
        if y == 0 or y != length-1:
            print ('*', end='')
    else:
        print('')   


for x in range(length):
    for y in range(x+1):
        if y == 0 or y == x or x == length-1: 
            print (y, end='')
        else:
            print(' ', end='')
    else:
        print('')


for x in range(length -1, 0, -1 ):
    for y in range(x+1):
        if y == 0 or y == x or x == length-1: 
            print (y, end='')
        else:
            print(' ', end='')
    else:
        print('')
        

        
