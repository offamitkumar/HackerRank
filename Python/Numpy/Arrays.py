import numpy

def arrays(arr):
    # complete this function
    # use numpy.array
    return numpy.array([ele for ele in reversed(arr)],dtype=float)

arr = input().strip().split(' ')
result = arrays(arr)
print(result)
