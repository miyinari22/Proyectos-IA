# Generador de Población Inicial para ADN

Este código en MATLAB genera una población inicial de cadenas de ADN de longitud 'r' y tamaño 'tam' utilizando un conjunto de letras permitidas ('a', 'c', 'g' y 't').

## Descripción del Código

La función `poblacion_Inicial()` realiza lo siguiente:

1. Solicita al usuario que ingrese el valor de 'r' (longitud de las cadenas) y 'tam' (tamaño de la población).
2. Verifica que 'r' esté en el rango de 2 a 4; de lo contrario, muestra un mensaje de error.
3. Define el conjunto de letras permitidas ('acgt').
4. Genera una población inicial de cadenas de ADN, donde cada cadena tiene longitud 'r' y se compone de letras aleatorias del conjunto permitido.
5. Muestra la población generada.

## Notas

- Las cadenas generadas simulan la población inicial de secuencias de ADN, donde cada cadena representa un individuo.
- El código utiliza letras permitidas ('a', 'c', 'g' y 't') para formar las cadenas de ADN.
