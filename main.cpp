#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"
#include "ProgramFlowStaticFunction.h"
using namespace AlgoGraph;


int main(int argc, char* argv[])
{
	string inputFileName= GetFileName(argc, argv);

	/*
	Need to check here file validity
	CheckInputFileValidity(inputFileName)
	*/

	int NumberOfVertices;
	int OriginVertex;
	int EndVertex;
	int FileIndentation;
	GetOriginVariables(NumberOfVertices, OriginVertex, EndVertex, FileIndentation, inputFileName);

	AdjancencyListGraph ListGraph(inputFileName, NumberOfVertices, FileIndentation);
	AdjacencyMatrixGraph MatrixGraph(inputFileName, NumberOfVertices, FileIndentation);
	
	RunBelmanFord(ListGraph, MatrixGraph, OriginVertex, EndVertex);
	RunHeapImplementedDijkstra(ListGraph, MatrixGraph, OriginVertex, EndVertex);
	RunArrayImplementedDijkstra(ListGraph, MatrixGraph, OriginVertex, EndVertex);

	return 0;
}



