import sys


def MultiplicationTable(userNum):
   
    numCount = 0
    
    while numCount <= 10:
        
        
        for num in range(1, 11):
            print(userNum, 'x', num, '=', userNum * num)
            numCount += 1

        return 0


def DoubleValue(userNum):
    
    print(userNum, 'x', 2, '=', userNum * 2, '\n')

    return 0


print(DoubleValue(4))