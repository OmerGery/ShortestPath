#include "GraphAlgorithms.h"
#include "ConstTypes.h"
#include "DynamicArray.h"

namespace AlgoGraph
{
	DynamicArray<Weight> GraphAlgorithms:: s_DegreesArray(1);
	DynamicArray<int> GraphAlgorithms:: s_parentArray(1);
	bool GraphAlgorithms::Relax(int i_OutVertex, int i_InVertex, Weight weightUV )
	{
		
		if (weightUV.infinity || s_DegreesArray[i_OutVertex].infinity)
			return false;
		Weight* dV = &(s_DegreesArray[i_InVertex]);
		Weight* dU = &(s_DegreesArray[i_OutVertex]);
		if (dV->infinity)
		{
			dV->infinity = false;
			dV->weight = dU->weight + weightUV.weight;
			s_parentArray[i_InVertex] = i_OutVertex;
			return true;
		}
		if (dV->weight > dU->weight + weightUV.weight)
		{
			dV->weight = dU->weight + weightUV.weight;
			s_parentArray[i_InVertex] = i_OutVertex;
			return true;
		}
		else return false;
	}
	void GraphAlgorithms::Init(int i_StartVertex, int i_AmountOfVertices)
	{
		for (int i = 0; i <= i_AmountOfVertices; i++)
		{
			s_parentArray.push_back(NO_PARENT);
			Weight initialWeight;
			initialWeight.infinity = true;
			s_DegreesArray.push_back(initialWeight);
		}
		s_DegreesArray[i_StartVertex].infinity = false;
		s_DegreesArray[i_StartVertex].weight = 0;
	}
	Result GraphAlgorithms::BellmanFord(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath)
	{
		int N = i_Graph->GetAmountOfVertices();
		Init(i_StartVertex, N);
		for (int i = 1; i <= N - 1; i++)
		{
			for (int u = 1; u <= N; u++)
			{
				DynamicList<GraphEdge> currentVertexAdjList = i_Graph->GetAdjList(u);
				int AmountOfNeighbors = currentVertexAdjList.getSize();
				for (int j = 0; j < AmountOfNeighbors; j++)
				{
					GraphEdge uTov = currentVertexAdjList.GetItemByIndex(j);
					Weight weightUV = uTov.GetEdgeWeight();
					int v = uTov.GetInVertex();
					Relax(u, v, weightUV);
				}
			}
		}
		for (int u = 1; u <= N; u++)
		{
			DynamicList<GraphEdge> currentVertexAdjList = i_Graph->GetAdjList(u);
			int AmountOfNeighbors = currentVertexAdjList.getSize();
			for (int j = 0; j < AmountOfNeighbors; j++)
			{
				GraphEdge uTov = currentVertexAdjList.GetItemByIndex(j);
				Weight weightUV = uTov.GetEdgeWeight();
				int v = uTov.GetInVertex();
				if (Relax(u, v, weightUV))
					return Result::NEGATIVE_CYCLE;//static_cast<int>(Result::NEGATIVE_CYCLE); // Negative cycle
			}
		}
		if (s_DegreesArray[i_EndVertex].infinity)
		{
			return Result::INFINITY_PATH;
		}
		o_ShortestPath = s_DegreesArray[i_EndVertex].weight;
		return Result::SUCCESS;
	}
}