# Selección de Parejas mediante Ruleta por Costo

Este código en MATLAB simula un proceso de selección de parejas de individuos basado en un método de ruleta, considerando los costos asociados a cada individuo dentro de una población.

## Descripción del Código

La función `seleccionRuletaPorCosto()` hace lo siguiente:

1. Solicita al usuario el tamaño de la población.
2. Genera costos aleatorios para cada individuo en el rango de 1 a 100.
3. Calcula un factor de ajuste (Cj) para cada individuo, teniendo en cuenta un valor de corrección.
4. Calcula la probabilidad de selección (Pj) para cada individuo basándose en sus costos relativos.
5. Realiza la selección de parejas utilizando el método de ruleta:
   - Selecciona parejas aleatorias de individuos basándose en sus probabilidades de selección (Pj).
   - Asegura que no se seleccionen individuos duplicados como pareja.
6. Muestra los resultados, incluyendo los detalles de cada individuo, sus costos, Cj, Pj y la sumatoria de Pj.
7. Muestra las parejas seleccionadas.

## Notas

- Los costos aleatorios generados simulan atributos o características de los individuos en la población.
- La selección de parejas se realiza con una probabilidad ponderada basada en los costos relativos.
