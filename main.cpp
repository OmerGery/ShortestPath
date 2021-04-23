#include "AdjacencyListGraph.h"
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "GraphAlgorithms.h"
#include "DynamicArray.h"
#include "AdjacencyMatrixGraph.h"
#include "minHeap.h"
#include "AbstractPriorityQueue.h"
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
	float dijkstraHeapPath;


	Result PathOfAdjancencyListGraph = GraphAlgorithms::BellmanFord(&ListGraph,pathStartingVertex,pathEndVertex, listpath);
	Result PathOfAdjacencyMatrixGraph = GraphAlgorithms::BellmanFord(&MatrixGraph, pathStartingVertex, pathEndVertex, matrixpath);
	
	//Need to check pathOf.... before printing!!!
	cout << "List Path Length: " << listpath << endl;
	cout << "Matrix Path Length: " << matrixpath << endl;


	if (GraphAlgorithms::DijkstraHeap(&ListGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
	{
		cout << "dijkstraHeap algorithem returned: path is infinity => inaccessible";
	}
	else cout << "Dijkstra-Heap LIST Path Length " << dijkstraHeapPath << endl;
	

	if (GraphAlgorithms::DijkstraHeap(&MatrixGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
	{
		cout << "dijkstraHeap algorithem returned: path is infinity => inaccessible";
	}
	else cout << "Dijkstra-Heap MATRIX Path Length " << dijkstraHeapPath << endl;



	if (GraphAlgorithms::DijkstraArray(&ListGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
	{
		cout << "Dijkstra-Array algorithem returned: path is infinity => inaccessible";
	}
	else cout << "Dijkstra-Array: LIST Path Length " << dijkstraHeapPath << endl;

	if (GraphAlgorithms::DijkstraArray(&MatrixGraph, pathStartingVertex, pathEndVertex, dijkstraHeapPath))
	{
		cout << "Dijkstra-Array algorithem returned: path is infinity => inaccessible";
	}
	else cout << "Dijkstra-Array: MATRIX Path Length " << dijkstraHeapPath << endl;

	inputFile.close();

	return 0;
}



