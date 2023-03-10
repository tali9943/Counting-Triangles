import matplotlib.pyplot as plt
import numpy as np

# Apri il file di testo in modalità lettura
with open('./outputResults/results.txt', 'r') as file:
    # Leggi i dati dal file e salva i valori in due liste separate
    x = []
    y = []
    
    file.readline()
    for line in file:
        data = line.split()
        x.append(int(data[0]))
        y.append(float(data[1]))

# Crea un grafico a dispersione dei dati
#plt.plot(x, y)

plt.plot(x, y, color = 'green',
         linestyle = 'solid', marker = 'o',
         markerfacecolor = 'red', markersize = 5)

plt.xticks(range(0,np.size(x)))  
# Aggiungi una griglia al grafico
plt.grid()

# Aggiungi etichette agli assi x e y e un titolo al grafico
plt.xlabel('Numbers of threads')
plt.ylabel('Speedup')
plt.title('Grafico a dispersione')

# Mostra il grafico
plt.savefig("./outputResults/plotResults.png")

