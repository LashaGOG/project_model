# script to plot graphs from "exec_times.txt"

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import linregress

#   AUTHORS : TAN Philippe
#             GOGRITCHIANI Lasha
#             CHEN Virginie


filename = "exec_times.txt" # format : size | t_naive[i]| t_fft[i] separated with spaces


# Lecture des données
chemin_fichier = 'exec_times.txt'
donnees = pd.read_csv(chemin_fichier, sep=" ", header=None, names=["Taille", "Temps naïf", "Temps fft"])


#Courbe de naïf
plt.figure()
plt.plot(donnees["Taille"], donnees["Temps naïf"], 'o-', label="Naïf")
plt.xlabel("Taille du polynôme")
plt.ylabel("Temps d'exécution moyen")
plt.title("Temps d'exécution moyen de l'algorithme naïf")
plt.legend()


#Courbe de naïf log-log
plt.figure()
log_size =np.log(donnees["Taille"])
log_time_naive = np.log(donnees["Temps naïf"])

plt.plot(log_size, log_time_naive, 'o-', label="Naïf log-log")

slope, intercept, r_value, p_value, std_err = linregress(log_size, log_time_naive)
plt.plot(log_size, intercept + slope * log_size, 'r', label=f'Régression linéaire (pente = {slope:.2f})')

plt.xlabel("Taille du polynôme (log scale)")
plt.ylabel("Temps d'exécution moyen naïf (log scale)")
plt.title("Temps d'éxécution moyen de naïf en echelle log-log")
plt.legend()


#Courbe de FFT

plt.figure()
plt.plot(donnees["Taille"], donnees["Temps fft"], 'o-', label="fft")
plt.xlabel("Taille du polynôme")
plt.ylabel("Temps d'éxécution moyen")
plt.title("Temps d'éxécution moyen de l'algorithme fft")

plt.legend()

plt.show()


