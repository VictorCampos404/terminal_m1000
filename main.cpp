#include <stdio.h>
#include <stdlib.h>
#include "packages/input_data/input_data.h"
#include "packages/myTools/myTools.h"
#include "packages/profiles/profiles.h"

int main(int argc, char** argv) {
	//initProfiles(); 
	//	-> feature de profiles não implementada por falta
	//	de tempo, era um "plus" no terminal.
	initMyTools();
	
	while(1 == 1){
		input();
	}


	return 0;
}
