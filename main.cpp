#include "AdjacencyListGraph.h"
#include "DynamicArray.h"
#include <iostream>
#include <fstream>
using namespace AlgoGraph;

int main()
{
	ifstream inputFile;
	inputFile.open("a.txt");
	int numberOfVertex;
	int pathStartingVertex;
	int pathEndVertex;

	inputFile >> numberOfVertex;
	inputFile >> pathStartingVertex;
	inputFile >> pathEndVertex;

	AdjancencyListGraph myGraph(inputFile, numberOfVertex);

	

	return 0;
}