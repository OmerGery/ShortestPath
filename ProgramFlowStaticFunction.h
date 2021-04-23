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
	void RunBelmanFordMatrix(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunBelmanFordList(AdjancencyListGraph& listImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunHeapListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunHeapMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunArrayMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex);
	void RunArrayListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex);
}
