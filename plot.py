import matplotlib.pyplot as plt
import numpy as np
import random as rnd
import os

def plitString(path):
    head_tail = os.path.split(path)
    path_name = head_tail[1].split('.')
    return path_name[0]


def createPlot():
    with open('./outputResults/results.txt', 'r') as file:    #open txt file to read datas
        #read and save the data 
        x = []
        y = []
        
        file.readline()
        name = file.readline()
        path_name = plitString(name)

        for line in file:
            data = line.split()
            x.append(int(data[0]))
            y.append(float(data[1]))

    #define the plot 
    plt.plot(x, y, color = 'green',linestyle = 'solid', marker = 'o', markerfacecolor = 'blue', markersize = 5, label='Speedup')

    xvals = np.array(plt.gca().set_xlim([0,25]))
    yvals = np.array(plt.gca().set_ylim([0, 25]))

    plt.plot(xvals, yvals, color='red', linestyle='dashed', linewidth=2, label='Linear speedup')
 
    #add grid in the plot
    plt.grid()

    plt.xlabel('Number of threads')
    plt.ylabel('Speedup')
    plt.title('Graph')

    plt.legend()

    plt.savefig("./outputResults/"+ path_name +".png")
    


if __name__=="__main__":
    createPlot()

