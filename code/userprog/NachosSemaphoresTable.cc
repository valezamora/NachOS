#include "NachosSemaphoresTable.h"

NachosSemaphoresTable::NachosSemaphoresTable(){
	this->usage = 1;
	this->activeSemaphoresMap = new BitMap(_SIZE);
}

NachosSemaphoresTable::~NachosSemaphoresTable(){
	delete activeSemaphoresMap;
}

// Register the file handle
int NachosSemaphoresTable::CreateSemaphore(){
	int posicion = activeSemaphoresMap->Find();
	
	return posicion;
}

