#include "DynamicList.h"
#include "DynamicArray.h"
#include "AdjacencyListGraph.h"
#include <iostream>
#include <fstream>

namespace AlgoGraph
{
    AdjancencyListGraph::AdjancencyListGraph(int i_NumberOfVertex): m_AdjancencyList(i_NumberOfVertex+1)
    {
        m_NumberOfVertices = i_NumberOfVertex;
    }

    AdjancencyListGraph AdjancencyListGraph::MakeEmptyGraph(int i_NumberOfVertex)
    {
        return AdjancencyListGraph(i_NumberOfVertex);
    }

    bool AdjancencyListGraph::isAdjacent(int i_OutVertex, int i_InVertex)
    {
        return FindEdgeInGraph(i_OutVertex, i_InVertex) != nullptr;
    }

    DynamicList<EdgeInAdjacencyList> AdjancencyListGraph::GetAdjList(int i_OutVertex)
    {
        return m_AdjancencyList[i_OutVertex];
    }


    AdjancencyListGraph::AdjancencyListGraph(ifstream& i_InputFile, int i_NumberOfVertex, int i_fileIndentation) : m_AdjancencyList(i_NumberOfVertex + 1), m_NumberOfVertices(i_NumberOfVertex)
    {
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

    AdjancencyListGraph::~AdjancencyListGraph()
    {
    }


    void AdjancencyListGraph::IsEdgeInRange(int i_OutVertex, int i_InVertex) 
    {
        if (i_OutVertex > m_NumberOfVertices || i_InVertex > m_NumberOfVertices || i_OutVertex < 1 || i_InVertex < 1)
        {
            cout << "Wrong input";
            exit(1);
        }

    }


    void AdjancencyListGraph::AddEdgeToGraph(int i_OutVertex, int i_InVertex, int i_WeightOfEdge)
    {
        IsEdgeInRange(i_OutVertex, i_InVertex);
        EdgeInAdjacencyList* existingEdge = FindEdgeInGraph(i_OutVertex, i_InVertex);
        if (existingEdge != nullptr)
        {
            if (existingEdge->m_EdgeWeight <= i_WeightOfEdge)
            {
                return;
            }
            else
            {
                RemoveEdgeFromGraph(i_OutVertex, i_InVertex);
            }
        }
        else
        {

            EdgeInAdjacencyList EdgeToBeAdded;
            EdgeToBeAdded.m_EdgeWeight = i_WeightOfEdge;
            EdgeToBeAdded.m_NeighboorVertex = i_InVertex;
            m_AdjancencyList[i_OutVertex].AddItemToHead(EdgeToBeAdded);
        }
    }

    void AdjancencyListGraph::RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex)
    {
        if(FindEdgeInGraph(i_OutVertex, i_InVertex)!=nullptr)
        {
            EdgeInAdjacencyList EdgeToBeRemove;
            EdgeToBeRemove.m_EdgeWeight = 0;
            EdgeToBeRemove.m_NeighboorVertex = i_InVertex;
            m_AdjancencyList[i_OutVertex].DeleteItemByValue(EdgeToBeRemove);
        }
    }


    EdgeInAdjacencyList* AdjancencyListGraph::FindEdgeInGraph(int i_OutVertex, int i_InVertex)
    {
        IsEdgeInRange(i_OutVertex, i_InVertex);
        EdgeInAdjacencyList* searchResult;
        EdgeInAdjacencyList EdgeToFind;
        EdgeToFind.m_EdgeWeight = 0;
        EdgeToFind.m_NeighboorVertex = i_InVertex;
        searchResult = m_AdjancencyList[i_OutVertex].ReturnRefrenceToItemByValue(EdgeToFind);
        return searchResult;
    }
}