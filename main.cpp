#include "AdjacencyListGraph.h"
#include "DynamicArray.h"
#include <iostream>
#include <fstream>
using namespace AlgoGraph;

int main()
{
	ifstream myfile;
	myfile.open("a.txt");
	int size = 0;
	int enter;
	int exit;

	myfile >> size;
	myfile >> enter;
	myfile >> exit;

	AdjancencyListGraph myGraph(myfile, size);

	

	return 0;
}