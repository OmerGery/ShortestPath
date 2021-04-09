#pragma once

#include "DynamicList.h"
#include "DynamicArray.h"
#include <iostream>

namespace AlgoGraph
{
	class AdjacencyMatrixGraph
	{
	private:
		int** m_AdjancencyMatrix;
		int m_NumberOfVertices;


	public:
		AdjacencyMatrixGraph(int i_NumberOfVertex);
		AdjacencyMatrixGraph(ifstream& i_InputFile, int i_NumberOfVertex, int i_fileIndentation);
		~AdjacencyMatrixGraph();
		void MakeEmptyGraph(int i_NumberOfVertex);
		bool isAdjacent(int i_OutVertex, int i_InVertex);
		void IsEdgeInRange(int i_OutVertex, int i_InVertex);
		DynamicList<int> GetAdjList(int i_OutVertex);
		void AddEdgeToGraph(int i_OutVertex, int i_InVertex, int i_WeightOfEdge);
		void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
	};

}