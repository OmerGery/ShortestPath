#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"
#include "ProgramFlowStaticFunction.h"
#include "FileValidity.h"

using namespace AlgoGraph;


int main(int argc, char* argv[])
{
	int NumberOfVertices, OriginVertex, EndVertex, FileStartLocation;
	string inputFileName, outputFileName;
	GetFileNames(argc, argv,inputFileName,outputFileName);

	CheckInputFileValidity(inputFileName);
	GetOriginVariables(NumberOfVertices, OriginVertex, EndVertex, FileStartLocation, inputFileName);

	AdjancencyListGraph ListGraph(inputFileName, NumberOfVertices, FileStartLocation);
	AdjacencyMatrixGraph MatrixGraph(inputFileName, NumberOfVertices, FileStartLocation);

	RunHeapListDijkstra(ListGraph, OriginVertex, EndVertex);
	RunArrayListDijkstra(ListGraph, OriginVertex, EndVertex);
	RunBelmanFordList(ListGraph, OriginVertex, EndVertex);
	RunHeapMatrixDijkstra(MatrixGraph, OriginVertex, EndVertex);
	RunArrayMatrixDijkstra(MatrixGraph, OriginVertex, EndVertex);
	RunBelmanFordMatrix(MatrixGraph, OriginVertex, EndVertex, argv[2]);
	return 0;
}



