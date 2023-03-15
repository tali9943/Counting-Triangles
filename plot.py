import matplotlib.pyplot as plt
import numpy as np
import random as rnd


def createPlot():
    with open('./outputResults/results.txt', 'r') as file:    #open txt file to read datas
        # read and save the data 
        x = []
        y = []
        
        file.readline()
        for line in file:
            data = line.split()
            x.append(int(data[0]))
            y.append(float(data[1]))

    # define the plot 
    plt.plot(x, y, color = 'green',linestyle = 'solid', marker = 'o', markerfacecolor = 'blue', markersize = 5, label='Speedup')

    xvals = np.array(plt.gca().set_xlim([0,len(x)]))
    yvals = np.array(plt.gca().set_ylim([0, 30])) #set the y axes

    plt.plot(xvals, yvals, color='red', linestyle='dashed', linewidth=2, label='Linear speedup')
 
    # add grid in the plot
    plt.grid()

    plt.xlabel('Numbers of threads')
    plt.ylabel('Speedup')
    plt.title('Grafico a dispersione')

    plt.legend()

    #save the result 
    plt.savefig("./outputResults/plotResults"+ str(rnd.randrange(1,15)) +".png")
    


if __name__=="__main__":
    createPlot()

