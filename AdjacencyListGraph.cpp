#include "DynamicList.h"
#include "DynamicArray.h"
#include "AdjacencyListGraph.h"
#include "GraphEdge.h"
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

    DynamicList<GraphEdge> AdjancencyListGraph::GetAdjList(int i_OutVertex)
    {
        return m_AdjancencyList[i_OutVertex];
    }


    AdjancencyListGraph::AdjancencyListGraph(string i_InputFileName, int i_NumberOfVertex, int i_fileIndentation) : m_AdjancencyList(i_NumberOfVertex + 1)
    {
        m_NumberOfVertices = i_NumberOfVertex;
        ifstream inputFile;
        inputFile.open(i_InputFileName);
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

    void AdjancencyListGraph::IsEdgeInRange(int i_OutVertex, int i_InVertex) 
    {
        if (i_OutVertex > m_NumberOfVertices || i_InVertex > m_NumberOfVertices || i_OutVertex < 1 || i_InVertex < 1)
        {
            cout << "Wrong input";
            exit(3);
        }

    }
    void AdjancencyListGraph::IsSelfLoop(int i_OutVertex, int i_InVertex)
    {
        if (i_OutVertex == i_InVertex)
        {
            cout << "invalid input";
            exit(1);
        }

    }



    void AdjancencyListGraph::AddEdgeToGraph(int i_OutVertex, int i_InVertex, float i_WeightOfEdge)
    {
        IsSelfLoop(i_OutVertex,i_InVertex);
        IsEdgeInRange(i_OutVertex, i_InVertex);
        if(i_WeightOfEdge < 0)
        {
            cout << "invalid input";
            exit(1);
        }
        GraphEdge* existingEdge = FindEdgeInGraph(i_OutVertex, i_InVertex);
        if (existingEdge != nullptr)
        {
            cout << "invalid input";
            exit(1);
        }
        else
        {
            GraphEdge EdgeToBeAdded(i_OutVertex, i_InVertex, i_WeightOfEdge);
            m_AdjancencyList[i_OutVertex].AddItemToTail(EdgeToBeAdded);
        }
    }

    void AdjancencyListGraph::RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex)
    {
        if(FindEdgeInGraph(i_OutVertex, i_InVertex)!=nullptr)
        {
            GraphEdge EdgeToBeRemove(i_OutVertex, i_InVertex, 0);
            m_AdjancencyList[i_OutVertex].DeleteItemByValue(EdgeToBeRemove);
        }
    }


    GraphEdge* AdjancencyListGraph::FindEdgeInGraph(int i_OutVertex, int i_InVertex)
    {
        IsEdgeInRange(i_OutVertex, i_InVertex);
        GraphEdge* searchResult;
        GraphEdge EdgeToFind(i_OutVertex, i_InVertex, 0);
        searchResult = m_AdjancencyList[i_OutVertex].ReturnRefrenceToItemByValue(EdgeToFind);
        return searchResult;
    }
}