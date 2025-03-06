#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int numDuplicates(int name_count, char** name, int price_count, int* price, int weight_count, int* weight) {
	if (name_count != price_count || price_count != weight_count) return 0; // Validação de entrada

	int numOfDuplicates = 0;
	int* validIndexArray = (int*)malloc(sizeof(int) * name_count);

	if (validIndexArray == NULL) {
		printf("ERRO DE ALOCAÇÃO!!");
		return -1;
	}

	int sizeOfValidIndexArray = name_count;
	for (int i = 0; i < name_count; i++) {
		validIndexArray[i] = i;
	}

	for (int j = 0; j < sizeOfValidIndexArray; j++) {
		if (validIndexArray[j] != -1) {
			char* currentName = name[validIndexArray[j]];
			int currentPrice = price[validIndexArray[j]];
			int currentWeight = weight[validIndexArray[j]];


			int currentDuplicates = 0;
			for (int k = j + 1; k < sizeOfValidIndexArray; k++) {
				if (validIndexArray[k] != -1 && strcmp(name[validIndexArray[j]], name[validIndexArray[k]]) == 0 && price[validIndexArray[j]] == price[validIndexArray[k]] && weight[validIndexArray[j]] == weight[validIndexArray[k]]) {
					currentDuplicates++;
					validIndexArray[k] = -1;
				}
			}

			if (currentDuplicates > 0) {
				numOfDuplicates += (currentDuplicates + 1);
				validIndexArray[j] = -1;
			}
		}
	}

	return numOfDuplicates;
}

void SystemPause() { //Função utilizada para pausar a execução do código, permitindo o usuário ver com mais clareza o que está acontecendo no código
	setbuf(stdin, NULL);
	printf("\nPressione qualquer tecla para continuar.\n");
	getchar();
	setbuf(stdin, NULL);
}

int main() {
	char* names[] = { "apple", "banana", "apple", "orange", "banana", "apple" };
	int prices[] = { 10, 20, 10, 30, 20, 10 };
	int weights[] = { 5, 10, 5, 15, 10, 5 };

	int count = numDuplicates(6, names, 6, prices, 6, weights);
	printf("Numero de duplicatas: %d\n", count); // Esperado: 2 (apple e banana)

	SystemPause();
	return 0;
}
