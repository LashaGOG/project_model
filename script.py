# script to plot graphs from "exec_times.txt"

filename = "exec_times.txt" # format : size | t_naive[i]| t_fft[i] separated with spaces

import pandas as pd
import matplotlib.pyplot as plt

# Lecture des données
chemin_fichier = 'exec_times.txt'
donnees = pd.read_csv(chemin_fichier, sep=" ", header=None, names=["Taille", "Temps naïf", "Temps fft"])

# plt.figure()

# plt.plot(donnees["Taille"], donnees["Temps naïf"], 'o-'
# , label="naïf")
# plt.xlabel("Taille du polynôme")
# plt.ylabel("Temps d'exécution moyen")
# plt.title("Temps d'exécution moyen de l'algorithme naïf")
# plt.legend()

plt.figure()

plt.plot(donnees["Taille"], donnees["Temps fft"], 'o-', label="fft")
plt.xlabel("Taille du polynôme")
plt.ylabel("Temps d'éxécution moyen")
plt.title("Temps d'éxécution moyen de l'algorithme fft")
plt.legend()

plt.show()
