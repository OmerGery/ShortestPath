// This is a Graph data structrue implented by Matrix , it inherits from the abstract graph class.
#pragma once
#include "DynamicList.h"
#include "DynamicArray.h"
#include "AbstractGraph.h"
#include "GraphEdge.h"
#include <iostream>

namespace AlgoGraph
{
	
	class AdjacencyMatrixGraph: public AbstractGraph
	{
	private:
		GraphEdge** m_AdjancencyMatrix;

	public:
		AdjacencyMatrixGraph(int i_NumberOfVertex);
		AdjacencyMatrixGraph(string i_InputFileName, int i_NumberOfVertex, int i_fileIndentation, int amountOfEdges);
		~AdjacencyMatrixGraph();
		void MakeEmptyGraph(int i_NumberOfVertex);
		bool isAdjacent(int i_OutVertex, int i_InVertex);
		void IsEdgeInRange(int i_OutVertex, int i_InVertex);
		void IsSelfLoop(int i_OutVertex, int i_InVertex);
		DynamicList<GraphEdge> GetAdjList(int i_OutVertex);
		void AddEdgeToGraph(int i_OutVertex, int i_InVertex, float i_WeightOfEdge);
		void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
		AdjacencyMatrixGraph(const AdjacencyMatrixGraph& other) = delete;
		AdjacencyMatrixGraph& operator=(const AdjacencyMatrixGraph& other) = delete;
	};

}