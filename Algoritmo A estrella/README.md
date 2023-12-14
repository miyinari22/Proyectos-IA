# Algoritmo A*

Este programa implementa el algoritmo A* para encontrar el camino más corto en una matriz con obstáculos desde un punto de inicio ('I') hasta un punto de destino ('F').

## Descripción del Código

El código consta de las siguientes secciones:

### Estructuras y Funciones

- **Coordenadas**: Estructura para almacenar las coordenadas (x, y).
- **Nodo**: Estructura para representar un nodo en el algoritmo A*.
- **imprimirMatriz** y **imprimirMatrizOriginal**: Funciones para imprimir la matriz y su versión original.
- **liberarMemoria**: Función para liberar la memoria de las estructuras dinámicas.
- **algoritmoAEstrella**: Implementación del algoritmo A*.

### Función Principal

La función `main()` realiza lo siguiente:

1. Lee una matriz desde un archivo "matriz.txt".
2. Encuentra las coordenadas de inicio ('I') y destino ('F').
3. Ejecuta el algoritmo A* para encontrar el camino más corto.
4. Imprime la matriz original y la matriz con el camino marcado.
5. Calcula y muestra el tiempo transcurrido en la ejecución del algoritmo.

## Formato del Archivo "matriz.txt"

El archivo de entrada "matriz.txt" debe tener el siguiente formato:

```
número_de_filas x número_de_columnas
Matriz
```

Ejemplo:

```
6x6
O O O M O O
O P O M O O
M O O M O O
O O O M P P
O M M O O O
I P P P P F
```

Donde:
- 'I' es el punto de inicio.
- 'F' es el punto de destino.
- 'P' son obstáculos con costo alto.
- 'O' son obstáculos con costo medio.
