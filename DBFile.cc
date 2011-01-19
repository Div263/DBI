#include <iostream>
#include "DBFile.h"
using namespace std;

// stub file .. replace it with your own DBFile.cc

DBFile::DBFile () {
	
	cur_record=NULL;
	

}
DBFile::~DBFile () {
	cout<<"in destructor\n";
}

int DBFile::Create (char *f_path, fType f_type, void *startup) {
}

void DBFile::Load (Schema &f_schema, char *loadpath) {
}

int DBFile::Open (char *f_path) {
}

void DBFile::MoveFirst () {
}

int DBFile::Close () {
}

void DBFile::Add(Record &rec) {
	Record *rec_pnt;
	rec_pnt = &rec;
	if(DBPage.Append(rec_pnt))
	{
		cout<<"Record Inserted"<<endl;
	}
	else
		cout<<"Error Appending\n";
	
	
}

int DBFile::GetNext (Record &fetchme) {
}

int DBFile::GetNext (Record &fetchme, CNF &cnf, Record &literal) {
}
