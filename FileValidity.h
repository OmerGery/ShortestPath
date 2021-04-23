#pragma once
#include "AdjacencyListGraph.h"
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "GraphAlgorithms.h"
#include "DynamicArray.h"
#include "AdjacencyMatrixGraph.h"
#include "minHeap.h"
#include "AbstractPriorityQueue.h"
#include <string>
#include <iostream>
#include <fstream>

namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName, int& endLocation);
	bool firstThreeSelectionAreValid(int numberOfVertex, int pathStartingVertex, int pathEndVertex);
	void PrintWrongInput();
	void RunAlgorithms(AdjancencyListGraph& ListGraph, AdjacencyMatrixGraph& MatrixGraph,int pathStartingVertex,int pathEndVertex);
}