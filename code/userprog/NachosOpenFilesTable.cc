#include "NachosOpenFilesTable.h"

NachosOpenFilesTable(){
	usage = 1;
	openFilesMap = new Bitmap(_SIZE);
	openFiles = new int[_SIZE];	
}

~NachosOpenFilesTable(){
	delete openFilesMap;
	delete openFiles;
}

// Register the file handle
int Open( int UnixHandle ){
	int posicion = openFilesMap.Find();
	if(posicion != -1){
		//hay espacio
		openFiles[posicion] = UnixHandle;
	}else{
		printf("No se puede abrir el archivo.");
	}
	return posicion;
}


// Unregister the file handle
int Close( int NachosHandle ){
	openFilesMap.Clear(NachosHandle);
}


bool isOpened( int NachosHandle ){
	return openFilesMap.Test(NachosHandle);	
}


int getUnixHandle( int NachosHandle ){
	return openFiles[NachosHandle];
}


void addThread(){
	usage++;	
}


void delThread(){
	usage--;
}


void Print(){
	printf("Nachos\tUnix");
	for(int i = 0; i<_SIZE; ++i){
		if(openFilesMap.Test(i)){
			printf("%d \t\t %d", i, openFiles[i]);
		}
	}
}
