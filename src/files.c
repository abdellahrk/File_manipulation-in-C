/*
 ============================================================================
 Name        : files.c
 Author      : Abdellah Ramadan
 Version     : 0.01
 Copyright   : A school project. Can be used anywhere.
 Description : Create and/or delete a file in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // access() function found here to check if file exists

int main(void) {
	setbuf(stdout, NULL);

	char choice;

	printf("Enter D to delete or C to create a file: ");
	choice = getchar();

	switch(choice){

	case 'D':
		deletefile();
		break;

	case 'C':
		createfile();
		break;
	default:
		puts("Enter D or C");
	}
	return 0;
}

void createfile(){

	int status;

	printf("Enter the name of the file to be created: ");
	char filename[100];
	scanf("%s", &filename);

	FILE *file;

	if( access(filename, F_OK) !=-1 ){
		puts("File already exists");
	}
	else {
		if(file = fopen(filename, "w")){
			puts("File created successfully");
		}
		else{
			puts("File could not be created");
		}
	}
	fclose(file);

}

void deletefile(){
	int status;
	char filename[100];
	printf("Enter the name of the file to be deleted: ");
	scanf("%s", &filename);

	status = remove(filename);

	if(status == 0){
		puts("File deleted successfully");
	}
	else {
		puts("Error deleting file");
	}

}
