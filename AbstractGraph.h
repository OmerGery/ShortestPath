#pragma once

#include "DynamicList.h"
#include "GraphEdge.h"
#include <iostream>

using namespace std;
namespace AlgoGraph
{
	class AbstractGraph
	{
		protected:
		int m_NumberOfVertices;
		public:
			virtual bool isAdjacent(int i_OutVertex, int i_InVertex) = 0;
			virtual void IsEdgeInRange(int i_OutVertex, int i_InVertex) = 0 ;
			virtual DynamicList<GraphEdge> GetAdjList(int i_OutVertex) = 0 ;
			virtual void AddEdgeToGraph(int i_OutVertex, int i_InVertex, float i_WeightOfEdge) = 0;
			virtual void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex) = 0;
			virtual int GetAmountOfVertices() { return m_NumberOfVertices; }
	};
}