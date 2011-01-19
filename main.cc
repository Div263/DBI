#include <stdlib.h>
#include <iostream>
#include "Record.h"
#include "DBFile.h"


using namespace std;

extern "C" {
	int yyparse(void);   // defined in y.tab.c
}

extern struct AndList *final;

int main () {

	// try to parse the CNF
	cout << "Enter in your CNF: ";
  	if (yyparse() != 0) {
		cout << "Can't parse your CNF.\n";
		exit (1);
	}

	// suck up the schema from the file
	Schema lineitem ("catalog", "lineitem");
		
	// grow the CNF expression from the parse tree 
	CNF myComparison;
	Record literal;
	myComparison.GrowFromParseTree (final, &lineitem, literal);
	
	// print out the comparison to the screen
	myComparison.Print ();

	// now open up the text file and start procesing it
        FILE *tableFile = fopen ("/home/divya/Desktop/lineitem.tbl", "r");

        Record temp;
        Schema mySchema ("catalog", "lineitem");

        // read in all of the records from the text file and see if they match
	// the CNF expression that was typed in
	int counter = 0;
	ComparisonEngine comp;
	DBFile DB;
	int count=0;
        while (temp.SuckNextRecord (&mySchema, tableFile) == 1 && count < 5) {
			DB.Add(temp);
			count++;
		}
     /*   while (temp.SuckNextRecord (&mySchema, tableFile) == 1) {
		counter++;
		if (counter % 10000 == 0) {
			cerr << counter << "\n";
		}

		if (comp.Compare (&temp, &literal, &myComparison))
                	temp.Print (&mySchema);

        }
       */
		cout<<"End of main\n";
}


