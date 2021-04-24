#pragma once
#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"
#include <chrono>

namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName);
	bool CheckComandArguments(int argc);
	void GetFileNames(int argc, char* argv[], string& inputFileName, string& outputFileName);
	void GetOriginVariables(int& NumberOfVertices, int& OriginVertex, int& EndVertex, int& FileIndentation, string FileName);
	void RunBelmanFordMatrix(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex,ofstream& outputFile);
	void RunBelmanFordList(AdjancencyListGraph& listImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile);
	void RunHeapListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile);
	void RunHeapMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile);
	void RunArrayMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile);
	void RunArrayListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex, ofstream& outputFile);
	std::chrono::steady_clock::time_point StartTimer();
	void EndTimer(ofstream& fileName, std::chrono::steady_clock::time_point start, const char* FuncName);
}

