import matplotlib.pyplot as plt

# Apri il file di testo in modalità lettura
with open('./outputResults/results.txt', 'r') as file:
    # Leggi i dati dal file e salva i valori in due liste separate
    x = []
    y = []
    for line in file:
        data = line.split()
        x.append(int(data[0]))
        y.append(float(data[1]))

# Crea un grafico a dispersione dei dati
plt.scatter(x, y)

# Aggiungi una griglia al grafico
plt.grid()

# Aggiungi etichette agli assi x e y e un titolo al grafico
plt.xlabel('Asse x')
plt.ylabel('Asse y')
plt.title('Grafico a dispersione')

# Mostra il grafico
plt.show()
