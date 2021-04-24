#pragma once
#include "DynamicList.h"
#include "AbstractGraph.h"
#include "DynamicArray.h"
#include "AbstractPriorityQueue.h"
#include "minArray.h"
#include "ConstTypes.h"
#include "minHeap.h"
#include <iostream>
using namespace std;

namespace AlgoGraph
{	
	class GraphAlgorithms
	{
		private:
			static DynamicArray<int > s_parentArray;
			static DynamicArray<Weight> s_DegreesArray;
			static QueueType CheckType(PriorityQueue* Q);
			static void RelaxRunnerBF(AbstractGraph* i_Graph, int N);
			static void RelaxRunnerDijkstra(AbstractGraph* i_Graph, VertexDV u, PriorityQueue* Q);
			static bool Relax(int i_OutVertex, int i_InVertex, Weight weightUV);
			static void Init(int i_StartVertex, int i_AmountOfVertices);
			GraphAlgorithms(const GraphAlgorithms& other) = delete;
			GraphAlgorithms& operator=(const GraphAlgorithms& other) = delete;

		public:
			static Result BellmanFord(AbstractGraph* i_Graph,int i_StartVertex,int i_EndVertex,float & o_ShortestPath);
			static bool DijkstraHeap(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath);
			static bool DijkstraArray(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath);
	};
}