#include "DynamicList.h"
#include "DynamicArray.h"
#include "AdjacencyListGraph.h"
#include <iostream>
#include <fstream>

namespace AlgoGraph
{
    AdjancencyListGraph::AdjancencyListGraph(int i_NumberOfVertex)
    {
        m_AdjancencyList.set_logic_size(i_NumberOfVertex);
    }

    AdjancencyListGraph::AdjancencyListGraph(ifstream& i_InputFile, int i_NumberOfVertex)
    {
        m_AdjancencyList.set_logic_size(i_NumberOfVertex);
        int inVertex;
        int outVertex;
        int weightOfVertex;
        for(int i=0;i<(i_NumberOfVertex-1);i++)
        {
            i_InputFile >> outVertex >> inVertex >> weightOfVertex;
            AddEdgeToGraph(outVertex, inVertex, weightOfVertex);
        }
    }

    AdjancencyListGraph::~AdjancencyListGraph()
    {
        
    }


    void AdjancencyListGraph::AddEdgeToGraph(int i_OutVertex, int i_InVertex,  int i_WeightOfEdge)
    {
        if( FindEdgeInGraph(i_OutVertex, i_InVertex) != nullptr)
        {
            return;
        }
        else
        {
            EdgeInAdjacencyList EdgeToBeAdded;
            EdgeToBeAdded.m_EdgeWeight = i_WeightOfEdge;
            EdgeToBeAdded.m_NeighboorVertex = i_InVertex;
            m_AdjancencyList[i_OutVertex].addTail(EdgeToBeAdded);
        }
    }

    void AdjancencyListGraph::RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex)
    {
        EdgeInAdjacencyList EdgeToBeRemove;
        EdgeToBeRemove.m_EdgeWeight = 0;
        EdgeToBeRemove.m_NeighboorVertex = i_InVertex;
        m_AdjancencyList[i_OutVertex].DelItem(EdgeToBeRemove);
    }


    EdgeInAdjacencyList* AdjancencyListGraph::FindEdgeInGraph(int i_OutVertex, int i_InVertex)
    {
        EdgeInAdjacencyList* searchResult;
        EdgeInAdjacencyList EdgeToFind;
        EdgeToFind.m_EdgeWeight = 0;
        EdgeToFind.m_NeighboorVertex = i_InVertex;
        searchResult= m_AdjancencyList[i_OutVertex].getItem(EdgeToFind);
        return searchResult;
    }

}





