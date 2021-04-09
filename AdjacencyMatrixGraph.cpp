#include "DynamicList.h"
#include "DynamicArray.h"
#include "adjacencyMatrixGraph.h"
#include <iostream>
#include <fstream>

namespace AlgoGraph
{

	AdjacencyMatrixGraph::AdjacencyMatrixGraph(int i_NumberOfVertex)
	{
		MakeEmptyGraph(i_NumberOfVertex);
	}

	void AdjacencyMatrixGraph::MakeEmptyGraph(int i_NumberOfVertex)
	{
		m_NumberOfVertices = i_NumberOfVertex;
		int size = i_NumberOfVertex+1;
		m_AdjancencyMatrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			m_AdjancencyMatrix[i] = new int[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m_AdjancencyMatrix[i][j] = INT_MAX;
			}
		}
	}

	DynamicList<int> AdjacencyMatrixGraph::GetAdjList(int i_OutVertex)
	{
		DynamicList<int> adjacentVerticiesList;
		for (int i = 0; i < m_NumberOfVertices; i++)
		{
			if (isAdjacent(i_OutVertex, i))
			{
				adjacentVerticiesList.AddItemToHead(i);
			}
		}
		return adjacentVerticiesList;
	}

	void AdjacencyMatrixGraph::IsEdgeInRange(int i_OutVertex, int i_InVertex)
	{
		if (i_OutVertex > m_NumberOfVertices || i_InVertex > m_NumberOfVertices || i_OutVertex < 1 || i_InVertex < 1)
		{
			cout << "Wrong input";
			exit(1);
		}
	}

	AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
	{
		for (int i = 0; i < m_NumberOfVertices; i++)
		{
			delete[] m_AdjancencyMatrix[i];
		}

		delete[] m_AdjancencyMatrix;
	}

	AdjacencyMatrixGraph::AdjacencyMatrixGraph(ifstream& i_InputFile, int i_NumberOfVertex,int i_fileIndentation)
	{
		MakeEmptyGraph(i_NumberOfVertex);
		i_InputFile.seekg(i_fileIndentation, i_InputFile.beg);
		int inVertex;
		int outVertex;
		int weightOfVertex;
		while (!i_InputFile.eof())
		{
			i_InputFile >> outVertex >> inVertex >> weightOfVertex;
			AddEdgeToGraph(outVertex, inVertex, weightOfVertex);
		}
	}

	//AdjancencyListGraph::CheckInPutValidity(maybe some variables) {}

	void AdjacencyMatrixGraph::AddEdgeToGraph(int i_OutVertex, int i_InVertex, int i_WeightOfEdge)
	{
		IsEdgeInRange(i_OutVertex, i_InVertex);
		int existingEdgeWeight = m_AdjancencyMatrix[i_OutVertex][i_InVertex];
		if (existingEdgeWeight > i_WeightOfEdge)
		{
			m_AdjancencyMatrix[i_OutVertex][i_InVertex] = i_WeightOfEdge;
		}
	}

	void AdjacencyMatrixGraph::RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex)
	{
		IsEdgeInRange(i_OutVertex, i_InVertex);
		m_AdjancencyMatrix[i_OutVertex][i_InVertex] = INT_MAX;
	}

	bool AdjacencyMatrixGraph::isAdjacent(int i_OutVertex, int i_InVertex)
	{
		IsEdgeInRange(i_OutVertex, i_InVertex);
		return m_AdjancencyMatrix[i_OutVertex][i_InVertex] < INT_MAX;
	}

}