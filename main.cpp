#include "AdjacencyListGraph.h"
#include "DynamicArray.h"
#include "AdjacencyMatrixGraph.h"
#include <iostream>
#include <fstream>

using namespace AlgoGraph;



bool CheckInputFileValidity(string i_inputFileName)
{
	ifstream inputFile;
	inputFile.open(i_inputFileName);
	//Continue to check if file is ok......
	
	return true; //just for now
}

bool CheckComandArguments(int argc)
{
	return argc == 2;
}

int main(int argc, char* argv[])
{
	string inputFileName;
	if (CheckComandArguments(argc))
	{
		inputFileName = argv[1];
	}
	else
	{
		cout << "Error with program command arguments";
		exit(2);
	}

	if (!CheckInputFileValidity(inputFileName))
	{
		cout << "Wrong Input";
		exit(3);
	}
	ifstream inputFile;
	inputFile.open(inputFileName);
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



