#pragma once
#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"

namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName);
	bool CheckComandArguments(int argc);
	string GetFileName(int argc, char* argv[]);
	void GetOriginVariables(int& NumberOfVertices, int& OriginVertex, int& EndVertex, int& FileIndentation, string FileName);
	void RunBelmanFord(AdjancencyListGraph& listImplementedGraph, AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunHeapImplementedDijkstra(AdjancencyListGraph& listImplementedGraph, AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunArrayImplementedDijkstra(AdjancencyListGraph& listImplementedGraph, AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex);
}

