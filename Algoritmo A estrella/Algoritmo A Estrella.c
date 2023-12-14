#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Estructura para almacenar las coordenadas
struct Coordenadas {
	int x;
	int y;
};

// Estructura para representar un nodo en el algoritmo A*
struct Nodo {
	struct Coordenadas coord;
	int costo; // Costo acumulado desde el inicio hasta este nodo
	int estimacion; // Estimación de la distancia restante 
	int total; // Costo total (costo + estimación)
};

void imprimirMatriz(char **matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			printf("+---");
		}
		printf("+\n");
		
		for (int j = 0; j < columnas; j++) {
			printf("| %c ", matriz[i][j]);
		}
		printf("|\n");
	}
	
	for (int j = 0; j < columnas; j++) {
		printf("+---");
	}
	printf("+\n");
}

// Función para imprimir la matriz original
void imprimirMatrizOriginal(char **matriz, int filas, int columnas) {
	printf("Matriz Original:\n");
	imprimirMatriz(matriz, filas, columnas);
}

// Función para liberar la memoria de la matriz y otras estructuras dinámicas
void liberarMemoria(char **matriz, int **visitado, struct Coordenadas **padre, int filas) {
	for (int i = 0; i < filas; i++) {
		free(matriz[i]);
		free(visitado[i]);
		free(padre[i]);
	}
	free(matriz);
	free(visitado);
	free(padre);
}

// Función que implementa el algoritmo A*
void algoritmoAEstrella(char **matriz, int filas, int columnas, struct Coordenadas inicio, struct Coordenadas destino) {
	// Define las costos de las celdas
	int costoP = 10000;
	int costoO = 10;
	int costoM = 25;
	
	// Coordenadas de los movimientos (arriba, abajo, izquierda, derecha)
	int movX[] = { -1, 1, 0, 0 };
	int movY[] = { 0, 0, -1, 1 };
	
	// Inicializa la matriz de visitados y el arreglo de nodos abiertos
	int **visitado = (int **)malloc(filas * sizeof(int *));
	for (int i = 0; i < filas; i++) {
		visitado[i] = (int *)malloc(columnas * sizeof(int));
		for (int j = 0; j < columnas; j++) {
			visitado[i][j] = 0;
		}
	}
	
	struct Nodo *abiertos = (struct Nodo *)malloc(filas * columnas * sizeof(struct Nodo));
	int front = 0;
	int rear = 0;
	
	// Inicializa el nodo inicial y lo agrega a la lista de abiertos
	struct Nodo nodoInicio;
	nodoInicio.coord = inicio;
	nodoInicio.costo = 0;
	nodoInicio.estimacion = abs(inicio.x - destino.x) + abs(inicio.y - destino.y); // Heurística: distancia Manhattan
	nodoInicio.total = nodoInicio.costo + nodoInicio.estimacion;
	abiertos[rear++] = nodoInicio;
	visitado[inicio.x][inicio.y] = 1;
	
	// Variables para rastrear el camino
	struct Coordenadas **padre = (struct Coordenadas **)malloc(filas * sizeof(struct Coordenadas *));
	for (int i = 0; i < filas; i++) {
		padre[i] = (struct Coordenadas *)malloc(columnas * sizeof(struct Coordenadas));
	}
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			padre[i][j].x = -1;
			padre[i][j].y = -1;
		}
	}
	
	while (front < rear) {
		// Extrae el nodo con el menor costo total
		int minIndex = front;
		for (int i = front + 1; i < rear; i++) {
			if (abiertos[i].total < abiertos[minIndex].total) {
				minIndex = i;
			}
		}
		
		struct Nodo current = abiertos[minIndex];
		
		// Si llegamos al destino, reconstruye el camino y sale del bucle
		if (current.coord.x == destino.x && current.coord.y == destino.y) {
			printf("Camino encontrado con un costo de %d:\n", current.costo);
			
			// Reconstruye el camino desde el nodo final hasta el inicial
			struct Coordenadas camino[filas * columnas];
			int paso = 0;
			while (padre[current.coord.x][current.coord.y].x != -1) {
				camino[paso++] = current.coord;
				current.coord = padre[current.coord.x][current.coord.y];
			}
			
			// Imprime el camino
			for (int i = paso - 1; i >= 0; i--) {
				printf("(%d, %d) ", camino[i].x, camino[i].y);
				matriz[camino[i].x][camino[i].y] = '*'; // Marcar el camino en la matriz
			}
			printf("\n");
			
			break;
		}
		
		// Genera y expande los sucesores
		for (int i = 0; i < 4; i++) {
			int nextX = current.coord.x + movX[i];
			int nextY = current.coord.y + movY[i];
			
			if (nextX >= 0 && nextX < filas && nextY >= 0 && nextY < columnas && !visitado[nextX][nextY]) {
				struct Nodo sucesor;
				sucesor.coord.x = nextX;
				sucesor.coord.y = nextY;
				
				// Calcula el costo del sucesor según el tipo de movimiento (horizontal o vertical)
				int costoMovimiento = 10;
				
				// Calcula el costo adicional según el contenido de la celda
				char celda = matriz[nextX][nextY];
				if (celda == 'P') {
					costoMovimiento += costoP;
				} else if (celda == 'O') {
					costoMovimiento += costoO;
				} else if (celda == 'M') {
					costoMovimiento += costoM;
				}
				
				sucesor.costo = current.costo + costoMovimiento;
				
				// Calcula la estimación del sucesor (distancia Manhattan)
				sucesor.estimacion = abs(nextX - destino.x) + abs(nextY - destino.y);
				
				// Calcula el costo total del sucesor
				sucesor.total = sucesor.costo + sucesor.estimacion;
				
				// Agrega el sucesor a la lista de abiertos y marca la celda como visitada
				abiertos[rear++] = sucesor;
				visitado[nextX][nextY] = 1;
				
				// Registra el padre del sucesor para reconstruir el camino
				padre[nextX][nextY] = current.coord;
			}
		}
		
		// Marca el nodo actual como visitado y lo elimina de la lista de abiertos
		visitado[current.coord.x][current.coord.y] = 2;
		front++;
	}
	
	// Imprime la matriz con el camino encontrado
	imprimirMatriz(matriz, filas, columnas);
	
	// Libera la memoria
	liberarMemoria(matriz, visitado, padre, filas);
}

int main() {    
	FILE *archivo;
	archivo = fopen("matriz.txt", "r");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	
	int filas, columnas; // Variables para las dimensiones de la matriz
	fscanf(archivo, "%dx%d", &filas, &columnas);
	
	char **matriz = (char **)malloc(filas * sizeof(char *));
	
	for (int i = 0; i < filas; i++) {
		matriz[i] = (char *)malloc(columnas * sizeof(char));
	}
	
	// Estructuras para almacenar las coordenadas de 'I' y 'F'
	struct Coordenadas letraI;
	struct Coordenadas letraF;
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			fscanf(archivo, " %c", &matriz[i][j]);
			
			// Verifica si es 'I' o 'F' y guarda las coordenadas
			if (matriz[i][j] == 'I') {
				letraI.x = i;
				letraI.y = j;
			} else if (matriz[i][j] == 'F') {
				letraF.x = i;
				letraF.y = j;
			}
		}
	}
	
	fclose(archivo);
	
	//variables para el calculo del tiempo
	clock_t inicio_tiempo, fin_tiempo;
	double tiempo_transcurrido;
	
	// Imprimir la matriz original
	imprimirMatrizOriginal(matriz, filas, columnas);
	
	inicio_tiempo = clock(); // Registra el tiempo de inicio
	
	// Llama a la función del algoritmo A*
	algoritmoAEstrella(matriz, filas, columnas, letraI, letraF);
	
	fin_tiempo = clock(); // Registra el tiempo tras finalizar
	tiempo_transcurrido = ((double)(fin_tiempo - inicio_tiempo)) / CLOCKS_PER_SEC;
	
	printf("Tiempo transcurrido: %.6f segundos\n", tiempo_transcurrido);
	
	return 0;
}
