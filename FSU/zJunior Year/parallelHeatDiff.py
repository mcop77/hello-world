# Marshall Copeland
# mtc19a
# Due Date: 12/3/2021
# The program in this file is the individual work of Marshall Copeland

import time
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap

if __name__ == "__main__":
    startingTemp = input("Enter a starting temperature: ")
    startTime = time.time()
    pool.map_async(function, range(0,2))
    startingTemp = int(startingTemp)
    oldTemp = np.zeros((startingTemp+2,startingTemp+2))
    Temp = np.zeros((startingTemp+2,startingTemp+2))
    tempArray = np.zeros((startingTemp+2,startingTemp+2))
    newGrid = np.zeros((startingTemp, startingTemp))

    row = []
    col = []

    for i in range(0, startingTemp+2):
        oldTemp[i,0] = startingTemp
        Temp[i,0] = startingTemp
    
    for i in range(1, startingTemp+1):
        for j in range(1, startingTemp+1):
            oldTemp[i,j] = (1/4)*(Temp[i-1,j] + Temp[i+1,j] + Temp[i,j-1] + Temp[i,j+1])
    
    for x in range(1,3001):
        if np.array_equal(oldTemp, Temp):
            break
        else:
            tempArray = Temp.copy()
            for i in range(1, startingTemp+1):
                for j in range(1, startingTemp+1):
                    Temp[i,j] = (1/4)*(oldTemp[i-1,j] + oldTemp[i+1,j] + oldTemp[i,j-1] + oldTemp[i,j+1])
            oldTemp = tempArray.copy()
    
    for i in range(1, startingTemp+1):
        for j in range(1, startingTemp+1):
            newGrid[i-1,j-1] = Temp[i,j]

    size = (startingTemp) * (startingTemp)

    for i in range(0,size):
        row.append((i + startingTemp) % (startingTemp)+1)

    for x in range(0,size):
        col.append(int(x / (startingTemp))+1)

    print("Time: ", end="")
    print(time.time() - startTime)

    colors = ["darkblue", "blue", "aqua", "lawngreen", "yellow", "orange", "red", "darkred"]
    cmap = mpl.colors.ListedColormap(colors)

    normalize = mpl.colors.Normalize(vmin=0, vmax=startingTemp)

    plt.scatter(row, col, c = newGrid, cmap = cmap, norm = normalize)
    plt.show()
