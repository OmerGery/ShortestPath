#include "GraphAlgorithms.h"
#include "ConstTypes.h"
#include "DynamicArray.h"
#include "AbstractPriorityQueue.h"

namespace AlgoGraph
{
	//Static Variables Initialization
	DynamicArray<Weight> GraphAlgorithms:: s_DegreesArray(1);
	DynamicArray<int> GraphAlgorithms:: s_parentArray(1);


	//Relax inplementation -> rrturning true or false due to improvment success of not.
	bool GraphAlgorithms::Relax(int i_OutVertex, int i_InVertex, Weight weightUV )
	{
		
		if (weightUV.infinity || s_DegreesArray[i_OutVertex].infinity)
			return false;
		Weight* dV = &(s_DegreesArray[i_InVertex]);
		Weight* dU = &(s_DegreesArray[i_OutVertex]);

		if (dV->infinity) //improve for sure
		{
			dV->infinity = false;
			dV->weight = dU->weight + weightUV.weight;
			s_parentArray[i_InVertex] = i_OutVertex;
			return true;
		}

		if (dV->weight > dU->weight + weightUV.weight) //check if inprove
		{
			dV->weight = dU->weight + weightUV.weight;
			s_parentArray[i_InVertex] = i_OutVertex;
			return true;
		}
		else return false;
	}
	

	//Init inplementation -> ensure initail state of D[v] and P[v] arrays.
	// D = Degrees array - all infinity and origin vertex to zero.
	// P = Parents array - all to null.
	void GraphAlgorithms::Init(int i_StartVertex, int i_AmountOfVertices)
	{
		//clearing from earlier uses
		s_DegreesArray.clear();
		s_parentArray.clear();
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

	//Running relax as part of Belman ford algorithm. N-1 iteration on all the edges of the graph.
	//iteration N is inside Belman Ford Function.
	void GraphAlgorithms::RelaxRunnerBF(AbstractGraph* i_Graph, int N)
	{
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
	}

	//Belman Ford algorithm implementation returning Result (enum) answers if there is a shortest path.
	//Shortest path weight is stored in refrenced variavble o_ShortestPath.
	Result GraphAlgorithms::BellmanFord(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath)
	{

		int N = i_Graph->GetAmountOfVertices();
		Init(i_StartVertex, N);
		RelaxRunnerBF(i_Graph, N); //N-1 iterations

		for (int u = 1; u <= N; u++) // N iteration resulting the answer of the shortesr path if exists.
		{
			DynamicList<GraphEdge> currentVertexAdjList = i_Graph->GetAdjList(u);
			int AmountOfNeighbors = currentVertexAdjList.getSize();
			for (int j = 0; j < AmountOfNeighbors; j++)
			{
				GraphEdge uTov = currentVertexAdjList.GetItemByIndex(j);
				Weight weightUV = uTov.GetEdgeWeight();
				int v = uTov.GetInVertex();
				if (Relax(u, v, weightUV))
					return Result::NEGATIVE_CYCLE; //relax returned true so in iteration N found an improving edge => Negetive cycle
			}
		}

		if (s_DegreesArray[i_EndVertex].infinity)
		{
			return Result::INFINITY_PATH; // D[end_vertex] is infinity thus no path from origin to end vertex.
		}

		o_ShortestPath = s_DegreesArray[i_EndVertex].weight; //found a path -> store it inside o_ShortestPath returns to caller function.
		return Result::SUCCESS;
	}




	//Running relax and decreaseKey as part of Dijkstra algorithm. 
	//Run througe all vertex neighbors and if found improving edge reduce the weight of the path in D[v] and fixes the priority queue.
	void GraphAlgorithms::RelaxRunnerDijkstra(AbstractGraph* i_Graph, VertexDV u, PriorityQueue* Q)
	{

		DynamicList<GraphEdge> currentVertexAdjList = i_Graph->GetAdjList(u.Vertex);
		int AmountOfNeighbors = currentVertexAdjList.getSize();
		for (int j = 0; j < AmountOfNeighbors; j++)
		{
			GraphEdge uTov = currentVertexAdjList.GetItemByIndex(j);
			Weight weightUV = uTov.GetEdgeWeight();
			int v = uTov.GetInVertex();
			if (Relax(u.Vertex, v, weightUV))
			{
				Q->decreaseKey(v, s_DegreesArray[v].weight);
			}
		}
	}


	//Dijkstra algorithm implementation returning true or false answers if there is a path from origin to end vertex.
	//Shortest path weight if exists is stored in refrenced variavble o_ShortestPath.
	//implemented with minHeap.
	bool GraphAlgorithms::DijkstraHeap(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath)
	{
		int N = i_Graph->GetAmountOfVertices();
		Init(i_StartVertex, N);
		
		minHeap Q(s_DegreesArray, N);
		
		while (!Q.isEmpty())
		{
			VertexDV u = Q.DeleteMin();
			RelaxRunnerDijkstra(i_Graph, u, &Q);
		}

		o_ShortestPath = s_DegreesArray[i_EndVertex].weight;
		return s_DegreesArray[i_EndVertex].infinity;
	}


	//Dijkstra algorithm implementation returning true or false answers if there is a path from origin to end vertex.
	//Shortest path weight if exists is stored in refrenced variavble o_ShortestPath.
	//implemented with minArray.
	bool GraphAlgorithms::DijkstraArray(AbstractGraph* i_Graph, int i_StartVertex, int i_EndVertex, float& o_ShortestPath)
	{
		int N = i_Graph->GetAmountOfVertices();
		Init(i_StartVertex, N);
		minArray Q(s_DegreesArray, N);

		while (!Q.isEmpty())
		{
			VertexDV u = Q.DeleteMin();
			RelaxRunnerDijkstra(i_Graph, u, &Q);
		}
		o_ShortestPath = s_DegreesArray[i_EndVertex].weight;
		return s_DegreesArray[i_EndVertex].infinity;
	}


	//not in use -> but mainly to determain the type of the queue can be used in future versions. 
	QueueType GraphAlgorithms::CheckType(PriorityQueue* Q)
	{
		minHeap* heap = dynamic_cast<minHeap*>(Q);
		if (heap != nullptr)
		{
			return QueueType::MinHeap;
		}
		else return QueueType::Array;
	}
}