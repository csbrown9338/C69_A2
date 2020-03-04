#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

static int to_evict_maybe;

/* Page to evict is chosen using the clock algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */

int clock_evict() {
	int found = 0;
	// Loop through them frames
	while (found == 0) {
		// Check the current frame we're at
		// If the ref bit is turned on, turn it off and go to next
		pgtbl_entry_t *p = coremap[to_evict_maybe].pte;
		if (p->frame & PG_REF) {
			p->frame &= ~PG_REF;
			to_evict_maybe = (to_evict_maybe+1) % memsize;
		}
		// Otherwise, return it :)
		else found = 1;
	}

	return to_evict_maybe;
}

/* This function is called on each access to a page to update any information
 * needed by the clock algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void clock_ref(pgtbl_entry_t *p) {
	// just uh change the ref bit... which is already taken care of :)

	return;
}

/* Initialize any data structures needed for this replacement
 * algorithm. 
 */
void clock_init() {
	// Also have a pointer i guess?
	to_evict_maybe = 0;

}
