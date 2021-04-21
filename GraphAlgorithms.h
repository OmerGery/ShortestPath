#pragma once
#include "DynamicList.h"
#include "AbstractGraph.h"
#include "DynamicArray.h"
#include "ConstTypes.h"
#include "minHeap.h"
#include <iostream>
using namespace std;

namespace AlgoGraph
{	
	class GraphAlgorithms
	{
		
	public:
		static DynamicArray<int > s_parentArray;
		static DynamicArray<Weight> s_DegreesArray;
		static bool Relax(int i_OutVertex,int i_InVertex, Weight weightUV);
		static void Init(int i_StartVertex,int i_AmountOfVertices);
		static Result BellmanFord(AbstractGraph* i_Graph,int i_StartVertex,int i_EndVertex,float & o_ShortestPath);
		static float DijkstraHeap(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath);
	};
}