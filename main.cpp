#include "AdjacencyListGraph.h"
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "GraphAlgorithms.h"
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
	// we know that the file is valid
	inputFile >> numberOfVertex;
	inputFile >> pathStartingVertex;
	inputFile >> pathEndVertex;
	int fileINdentation =(int) inputFile.tellg();
	 
	AdjancencyListGraph ListGraph(inputFile, numberOfVertex, fileINdentation);
	AdjacencyMatrixGraph MatrixGraph(inputFile, numberOfVertex, fileINdentation);
	
	float matrixpath;
	float listpath;

	Result PathOfAdjancencyListGraph = GraphAlgorithms::BellmanFord(&ListGraph,pathStartingVertex,pathEndVertex, listpath);
	Result PathOfAdjacencyMatrixGraph = GraphAlgorithms::BellmanFord(&ListGraph, pathStartingVertex, pathEndVertex, matrixpath);

	cout << "List Path Length: " << listpath << endl;
	cout << "Matrix Path Length: " << matrixpath << endl;
	inputFile.close();
	return 0;
}



