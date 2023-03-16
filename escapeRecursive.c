#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 5
int array[size][size];

int counter = 1;

int toDraw(int x, int y){
	if(array[x][y] != 0){
		array[x][y] = counter; 
	}
	
	if(x == size - 1 && y == size - 1)
		return;
	
	if(x != size && y != size && x != - 1 && y != - 1){
		if(array[x][y + 1] == 1 && y != size - 1){
			counter++;
			toDraw(x, y + 1); 
		} 
		else if(array[x + 1][y] == 1 && x != size - 1){
			counter++;
			toDraw(x + 1, y);
		} 
		else if(array[x][y - 1] != 0){
			if(x != size - 1 || y != 0){
				counter--;
				toDraw(x, y - 1);	
			}
			else if((x != size - 1) && y == 0)
				return;
			else 
				return;
			
		}
		else if(array[x - 1][y] != 0){
			if(y != size - 1 || x != 0){
				counter--;
				toDraw(x - 1, y);		
			}
			else if((y != size - 1) && x == 0)
				return;
			else 
				return;
		}
		else if(x == 0 && y == 0)
			return;
		else if(x == size - 1 && y == size - 1)
			return;	
		}
	else
		return;
}

void print(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){			
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
}

void fillArray(){
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(i == 0 && j == 0)
				array[i][j] = 1;
			else
				array[i][j] = rand() % 2;
}

int main(){
	srand(time(NULL));
	int flag = 1;
	while(flag){
		fillArray();
		counter = 1;
		toDraw(0, 0);	
		print();
		if(array[4][4] == 9)
			flag = 0;
		printf("\n\n");
	}
	printf("Kurtulus Yolu Bulundu...");
}
