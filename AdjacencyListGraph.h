#pragma once

#include "DynamicList.h"
#include "DynamicArray.h"
#include "GraphEdge.h"

namespace AlgoGraph
{

    class AdjancencyListGraph
    {
    
        private:
    

        DynamicArray<DynamicList<GraphEdge>> m_AdjancencyList;
        int m_NumberOfVertices;

        public:

        AdjancencyListGraph(int i_NumberOfVertex);
        AdjancencyListGraph(ifstream& i_InputFile, int i_NumberOfVertex, int i_fileIndentation);
        static AdjancencyListGraph MakeEmptyGraph(int i_NumberOfVertex);
        bool isAdjacent(int i_OutVertex, int i_InVertex);
        DynamicList<GraphEdge> GetAdjList(int i_OutVertex);
        void IsEdgeInRange(int i_OutVertex, int i_InVertex);
        ~AdjancencyListGraph();
        void AddEdgeToGraph(int i_OutVertex, int i_InVertex,  float i_WeightOfEdge); 
        void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
        GraphEdge* FindEdgeInGraph(int i_OutVertex, int i_InVertex);
        

    };
}



