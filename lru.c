#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

/* Page to evict is chosen using the accurate LRU algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */

int lru_evict() {
	// Take ya list.
	// Loop through until you reach the very very last one :) (next == null)
	// das da one
	
	return 0;
}

/* This function is called on each access to a page to update any information
 * needed by the lru algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void lru_ref(pgtbl_entry_t *p) {

	// Have the previous and next point to each other.
	// Loop through the previous ones until you reach null
	// Make the head now point to the referenced one
	return;
}


/* Initialize any data structures needed for this 
 * replacement algorithm 
 */
void lru_init() {
	// Make a doubly linked list (BUT THAT'S DONE IN THE COREMAP I THINK????)
	// So nothing to see here :D

}
