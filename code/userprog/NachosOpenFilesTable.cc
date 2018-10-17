#include "NachosOpenFilesTable.h"

NachosOpenFilesTable::NachosOpenFilesTable(){
	this->usage = 1;
	this->openFilesMap = new BitMap(_SIZE);
	this->openFiles = new int[_SIZE];	
}

NachosOpenFilesTable::~NachosOpenFilesTable(){
	delete openFilesMap;
	delete openFiles;
}

// Register the file handle
int NachosOpenFilesTable::Open( int UnixHandle ){
	int posicion = openFilesMap->Find();
	if(posicion != -1){
		//hay espacio
		openFiles[posicion] = UnixHandle;
	}else{
		printf("No se puede abrir el archivo.");
	}
	return posicion;
}


// Unregister the file handle
int NachosOpenFilesTable::Close( int NachosHandle ){
	openFilesMap->Clear(NachosHandle);
	return openFiles[NachosHandle];
}


bool NachosOpenFilesTable::isOpened( int NachosHandle ){
	return openFilesMap->Test(NachosHandle);	
}


int NachosOpenFilesTable::getUnixHandle( int NachosHandle ){
	return openFiles[NachosHandle];
}


void NachosOpenFilesTable::addThread(){
	usage++;	
}


void NachosOpenFilesTable::delThread(){
	usage--;
}


void NachosOpenFilesTable::Print(){
	printf("Nachos\tUnix");
	for(int i = 0; i<_SIZE; ++i){
		if(openFilesMap->Test(i)){
			printf("%d \t\t %d", i, openFiles[i]);
		}
	}
}
