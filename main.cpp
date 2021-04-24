#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"
#include "ProgramFlowStaticFunction.h"
#include "ProgramFlowStaticFunction.h"

using namespace AlgoGraph;


int main(int argc, char* argv[])
{
	ofstream outputFile;
	int NumberOfVertices=0, OriginVertex, EndVertex, FileStartLocation=0,numberOfEdges;
	string inputFileName, outputFileName;
	GetFileNames(argc, argv,inputFileName,outputFileName);

	if (CheckInputFileValidity(inputFileName, numberOfEdges))
		GetOriginVariables(NumberOfVertices, OriginVertex, EndVertex, FileStartLocation, inputFileName);
	else PrintWrongInput();

	AdjancencyListGraph ListGraph(inputFileName, NumberOfVertices, FileStartLocation,numberOfEdges);
	AdjacencyMatrixGraph MatrixGraph(inputFileName, NumberOfVertices, FileStartLocation,numberOfEdges);

	outputFile.open(argv[2]);
	RunHeapListDijkstra(ListGraph, OriginVertex, EndVertex,outputFile);
	RunArrayListDijkstra(ListGraph, OriginVertex, EndVertex, outputFile);
	RunBelmanFordList(ListGraph, OriginVertex, EndVertex, outputFile);
	RunHeapMatrixDijkstra(MatrixGraph, OriginVertex, EndVertex, outputFile);
	RunArrayMatrixDijkstra(MatrixGraph, OriginVertex, EndVertex, outputFile);
	RunBelmanFordMatrix(MatrixGraph, OriginVertex, EndVertex, outputFile);
	outputFile.close();
	return 0;
}



