# Red Neuronal para Clasificación de Datos

Este código en MATLAB entrena una red neuronal para clasificar datos utilizando un conjunto de entrenamiento y evaluándola con un conjunto de prueba.

## Descripción del Código

La función `tiro()` realiza lo siguiente:

1. Carga datos del archivo 'new-thyroid.data' disponible en [UCI Machine Learning Repository](https://archive.ics.uci.edu/dataset/102/thyroid+disease) y realiza algunas manipulaciones iniciales en la matriz de datos.
2. Divide los datos en conjuntos de entrenamiento ('X' y 't') y prueba ('P' y 'tp').
3. Entrena una red neuronal utilizando el conjunto de entrenamiento.
4. Realiza predicciones ('Y' y 'YP') utilizando la red neuronal entrenada en los conjuntos de entrenamiento y prueba, respectivamente.
5. Calcula el porcentaje de clasificación correcta para ambos conjuntos y muestra los resultados.

## Ejecución del Código

### Requisitos

El código está escrito en MATLAB y requiere el archivo 'new-thyroid.data' de la [base de datos de UCI Machine Learning Repository](https://archive.ics.uci.edu/dataset/102/thyroid+disease).

### Ejecución

1. Descarga el archivo 'new-thyroid.data' de [UCI Machine Learning Repository](https://archive.ics.uci.edu/dataset/102/thyroid+disease) y colócalo en la misma carpeta que el archivo `.m`.
2. Copia y pega el código en un archivo `.m`.
3. Ejecuta MATLAB y carga o abre el archivo `.m`.
4. Llama a la función `tiro()` desde la consola de MATLAB.

## Notas

- La red neuronal utiliza una estructura específica con capas y funciones de activación definidas.
- Se realiza una evaluación de la precisión de la clasificación tanto para el conjunto de entrenamiento como para el conjunto de prueba.
