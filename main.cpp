#include "AdjacencyListGraph.h"
#include "DynamicArray.h"
#include "AdjacencyMatrixGraph.h"
#include <iostream>
#include <fstream>

using namespace AlgoGraph;



bool CheckInputFileValidity(ifstream& inputFile)
{
	//Need to check threes is file
	return true;
}

int main()
{
	ifstream inputFile;
	if (!CheckInputFileValidity(inputFile))
	{
		cout << "Wrong Input";
		exit(2);
	}

	inputFile.open("a.txt");
	int numberOfVertex;
	int pathStartingVertex;
	int pathEndVertex;
	inputFile >> numberOfVertex;
	inputFile >> pathStartingVertex;
	inputFile >> pathEndVertex;
	int fileINdentation = inputFile.tellg();
	AdjancencyListGraph ListGraph(inputFile, numberOfVertex, fileINdentation);
	AdjacencyMatrixGraph MatrixGraph(inputFile, numberOfVertex, fileINdentation);
	inputFile.close();
	
	return 0;
}



