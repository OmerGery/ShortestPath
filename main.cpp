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
	// initating variables and getting arguments from argv
	ofstream outputFile;
	int NumberOfVertices=0, OriginVertex, EndVertex, FileStartLocation=0,numberOfEdges;
	string inputFileName, outputFileName;
	GetFileNames(argc, argv,inputFileName,outputFileName);
	// checking input validity
	if (CheckInputFileValidity(inputFileName, numberOfEdges))
		GetOriginVariables(NumberOfVertices, OriginVertex, EndVertex, FileStartLocation, inputFileName);
	else PrintWrongInput();
	// building the graphs : one as a matrix and one as a list of neighbors
	AdjancencyListGraph ListGraph(inputFileName, NumberOfVertices, FileStartLocation,numberOfEdges);
	AdjacencyMatrixGraph MatrixGraph(inputFileName, NumberOfVertices, FileStartLocation,numberOfEdges);
	// opening the output file to write the times:
	outputFile.open(outputFileName);
	//running the algorirthms 
	RunHeapListDijkstra(ListGraph, OriginVertex, EndVertex,outputFile);
	RunArrayListDijkstra(ListGraph, OriginVertex, EndVertex, outputFile);
	RunBelmanFordList(ListGraph, OriginVertex, EndVertex, outputFile);
	RunHeapMatrixDijkstra(MatrixGraph, OriginVertex, EndVertex, outputFile);
	RunArrayMatrixDijkstra(MatrixGraph, OriginVertex, EndVertex, outputFile);
	RunBelmanFordMatrix(MatrixGraph, OriginVertex, EndVertex, outputFile);
	outputFile.close();
	return 0;
}



