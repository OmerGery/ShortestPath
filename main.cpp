/* Shortest path project - by Nadav Avraham , Omer Gery.
Operating instructions:
1.Enter a positive integer to select how many vertices will be in the graph and press enter.
2.Enter a positive integer to select the starting vertex to find shortest paths from and press enter.
3.Enter a positive integer to select the ending vertex to find shortest paths to.
4.Enter a series of 3 numbers represnting a edge in the graph in the following format:
<OutVertex> (1 space) <InVertex> (1 space) <EdgeWeight> (enter)
Outvertex,InVertex - a number between 1 - to the number you selected in 1. EdgeWeight - a non negative number, can be a fraction.
5.Repeat stage 4 to as many edges as you wish.
Notes:
- Negative edge weight is not allowed.
- The Graph is a simple graph - parallel edges and self loops are not allowed. 
*/
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
	int NumberOfVertices = 0, OriginVertex, EndVertex, FileStartLocation = 0, numberOfEdges;
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



