#include "bitmap.h"

#define _SIZE 100	//cantidad maxima de semaforos que se pueden crear

class NachosSemaphoresTable {
  public:
    NachosSemaphoresTable();       // Initialize
    ~NachosSemaphoresTable();      // De-allocate
    
    int CreateSemaphore(); // Register the file handle
    int DeleteSemaphore( int id );      // Unregister the file handle
    void addThread();		// If a user thread is using this table, add it
    void delThread();		// If a user thread is using this table, delete it

    void Print();               // Print contents
    
  private:
    BitMap * activeSemaphoresMap;	// A bitmap to control our vector
    int usage;						// How many threads are using this table

};
