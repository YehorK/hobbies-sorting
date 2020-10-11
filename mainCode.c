//The program reads F1.txt and takes the data from there such as name, number of hobbies, street address, index and city
//The program reqires to enter the hobbies from the keyboard.
// If the number of hobbies is more than 10 then this line of data is not considered.
//Eventually, program outputs the valid entries into the F2.txt with the previously entered hobbies.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char street[20];
char city[10];
int index;
}Address;

typedef struct{
char name[15];
int numHobby;
char hobbies[10][20];
Address address;
}data;

void output(FILE*, data*);
void input(FILE*, data*);
int main(void){
	data p;
	data *pointer = &p;
	char fileR[10] = "F1.txt", fileW[10] = "F2.txt"; //R and W stand for reading and writing
	FILE *fi,*fo;
	fi = fopen(fileR, "r");
	fo = fopen(fileW, "w");
	
	do{
		input(fi, pointer);
		if(pointer->numHobby > 0 && pointer->numHobby < 11){
			output(fo, pointer);
		}
		else{
			continue;}
	}while(fgetc(fi)!=EOF);

fclose(fi);
fclose(fo);

return 0;	
}

void input(FILE* f, data* data){
	fscanf(f, "%s %d %s %d %s", data->name, &data->numHobby, data->address.street, &data->address.index, data->address.city);
	int i;
	int x;
	char h[15];
	x = data->numHobby;
	if(x > 0 && x <= 10){
		for(i = 0; i < x; i++){
			printf("Enter the hobby(%d): ", i+1);
			scanf("%s", h);
			strcpy(data->hobbies[i], h);
			}
		printf("\n");
	}
}

void output(FILE* f, data* data){
	int i;
	fprintf(f, "Name: %s \nNummber of hobbies: %d\nStreet-index: %s-%d \nCity: %s \nHoobies:", data->name, data->numHobby, data->address.street, data->address.index, data->address.city);
	for(i = 0; i < data->numHobby; i++){
		fprintf(f, "%s ", data->hobbies[i]);}
	fprintf(f, "\n\n");
}
