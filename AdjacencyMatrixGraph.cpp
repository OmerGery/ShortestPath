#include "DynamicList.h"
#include "DynamicArray.h"
#include "adjacencyMatrixGraph.h"
#include "FileValidity.h"
#include <iostream>
#include <fstream>

namespace AlgoGraph
{

	AdjacencyMatrixGraph::AdjacencyMatrixGraph(int i_NumberOfVertex)
	{
		m_NumberOfVertices = i_NumberOfVertex;
		MakeEmptyGraph(i_NumberOfVertex);
	}

	void AdjacencyMatrixGraph::MakeEmptyGraph(int i_NumberOfVertex)
	{

		m_NumberOfVertices = i_NumberOfVertex;
		int size = i_NumberOfVertex+1;
		m_AdjancencyMatrix = new GraphEdge* [size];
		for (int i = 0; i < size; i++)
		{
			m_AdjancencyMatrix[i] = new GraphEdge[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m_AdjancencyMatrix[i][j].SetInfinityWeight();
				m_AdjancencyMatrix[i][j].SetOutVertex(i);
				m_AdjancencyMatrix[i][j].SetInVertex(j);

			}
		}
	}
	void AdjacencyMatrixGraph::IsSelfLoop(int i_OutVertex, int i_InVertex)
	{
		if (i_OutVertex==i_InVertex)
			PrintWrongInput();
	}

	DynamicList<GraphEdge> AdjacencyMatrixGraph::GetAdjList(int i_OutVertex)
	{
		DynamicList<GraphEdge> adjacentVerticiesList;
		for (int i = 1; i <= m_NumberOfVertices; i++)
		{
			if (isAdjacent(i_OutVertex, i))
			{
				GraphEdge edgeToBeAdded = m_AdjancencyMatrix[i_OutVertex][i];
				adjacentVerticiesList.AddItemToTail(edgeToBeAdded);
			}
		}
		return adjacentVerticiesList;
	}

	void AdjacencyMatrixGraph::IsEdgeInRange(int i_OutVertex, int i_InVertex)
	{
		if (i_OutVertex > m_NumberOfVertices || i_InVertex > m_NumberOfVertices || i_OutVertex < 1 || i_InVertex < 1)
			PrintWrongInput();
	}

	AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
	{
		for (int i = 0; i < m_NumberOfVertices; i++)
		{
			delete[] m_AdjancencyMatrix[i];
		}

		delete[] m_AdjancencyMatrix;
	}

	AdjacencyMatrixGraph::AdjacencyMatrixGraph(string i_InputFileName, int i_NumberOfVertex,int i_fileIndentation)
	{
		ifstream inputFile;
		inputFile.open(i_InputFileName);
		inputFile.seekg(i_fileIndentation, inputFile.beg);
		MakeEmptyGraph(i_NumberOfVertex);
		inputFile.seekg(i_fileIndentation, inputFile.beg);
		int inVertex;
		int outVertex;
		float weightOfVertex;
		while (!inputFile.eof())
		{
			inputFile >> outVertex >> inVertex >> weightOfVertex;
			AddEdgeToGraph(outVertex, inVertex, weightOfVertex);
		}
		inputFile.close();
	}




	void AdjacencyMatrixGraph::AddEdgeToGraph(int i_OutVertex, int i_InVertex, float i_WeightOfEdge)
	{
		
		IsEdgeInRange(i_OutVertex, i_InVertex);
		IsSelfLoop(i_OutVertex, i_InVertex);
		if (i_WeightOfEdge < 0)
			PrintWrongInput();
		if (m_AdjancencyMatrix[i_OutVertex][i_InVertex].IsWeightInfinity())
		{
			m_AdjancencyMatrix[i_OutVertex][i_InVertex].SetEdgeWeight(i_WeightOfEdge);
		}
		else //if is not true means edge is not infinity => edge already exist
			PrintWrongInput();
	}

	void AdjacencyMatrixGraph::RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex)
	{
		IsEdgeInRange(i_OutVertex, i_InVertex);
		m_AdjancencyMatrix[i_OutVertex][i_InVertex].SetInfinityWeight();
	}

	bool AdjacencyMatrixGraph::isAdjacent(int i_OutVertex, int i_InVertex)
	{
		IsEdgeInRange(i_OutVertex, i_InVertex);
		return !(m_AdjancencyMatrix[i_OutVertex][i_InVertex].IsWeightInfinity()); //IsWeightInfinity() returns true if infinity meaning not adjacent
	}

}