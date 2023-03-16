#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int array[size][size];

int checkTable(int number){
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(array[i][j] == number)
				return 0;
	return 1;
}

int game(int number){
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(array[i][j] == number){
				array[i][j] = 0;
				return 0;
			}
	return 1;
}


void toDraw(int x, int y){
	int number = rand() % 100 + 1;
	if(!checkTable(number))
		return toDraw(x, y);
	else
		array[x][y] = number;
	if(y < size - 1 && x != size)
		return toDraw(x, y + 1);
	else if(y == size - 1 && x == size - 1)
		return;
	else if(y == size - 1)
		return toDraw(x + 1, 0);
}

void print(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%4d", array[i][j]);
		}
		printf("\n");
	}
}

int main(){
	srand(time(NULL));
	toDraw(0, 0);
	int counter = 1;
	while(counter != 100){
		print();	
		int number;
		printf("\n\nEnter the number = ");
		scanf("%d", &number);
		if(number == counter && !game(number))
			counter++;
		else 
			printf("Try Again!");
		printf("\n\n");
	}	
	return 0;
}
