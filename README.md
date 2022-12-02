# EDIT DISTANCE DYNAMIC

Frase:
Quando avevo cinqve anni, mia made mi perpeteva sempre che la felicita e la chiave della vita. Quando andai a squola mi domandrono come vuolessi essere da grande. Io scrissi: selice. Mi dissero che non avevo capito il corpito, e io dissi loro che non avevano capito la wita.

Osservazioni:
Nel momento della correzione, ho potuto notare che le parole: “made” e “selice” rimangono tali, essendo due parole corrette nel dizionario italiano; mentre le parole “squola” e “corpito” vengono corrette in maniera sbagliata.
Dopo aver eseguito l’esercizio, mi sono reso conto che l’edit_distance è molto lento a leggere tutte le parole del file, a differenza dell’edit_distance_dyn che ci mette molto meno tempo.
Quindi, per rendere più efficiente il calcolo della distanza tra le parole, l’algoritmo utilizza una tecnica di programmazione dinamica producendo il lavoro in tempo minore rispetto all’edit distance che produce il lavoro in tempo esponenziale.

Metodo Dinamico:
Utilizzando l’algoritmo dinamico (tecnica basata sulla divisione del problema in sotto problemi), viene richiesta più memoria rispetto al metodo classico. Questo è molto favorevole, poiché l’aumento della memoria è trascurabile rispetto al tempo di calcolo.
