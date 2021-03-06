// This is a Graph data structrue implented by Adjancency List , it inherits from the abstract graph class.
#pragma once
#include "DynamicList.h"
#include "DynamicArray.h"
#include "GraphEdge.h"
#include "AbstractGraph.h"

namespace AlgoGraph
{

    class AdjancencyListGraph: public AbstractGraph
    {
    
        private:
            DynamicArray<DynamicList<GraphEdge>> m_AdjancencyList;

        public:
            void IsSelfLoop(int i_OutVertex, int i_InVertex);
            AdjancencyListGraph(int i_NumberOfVertex);
            AdjancencyListGraph(string i_InputFileName, int i_NumberOfVertex, int i_fileIndentation, int amountOfEdges);
            static AdjancencyListGraph MakeEmptyGraph(int i_NumberOfVertex);
            bool isAdjacent(int i_OutVertex, int i_InVertex);
            DynamicList<GraphEdge> GetAdjList(int i_OutVertex);
            void IsEdgeInRange(int i_OutVertex, int i_InVertex);
            void AddEdgeToGraph(int i_OutVertex, int i_InVertex,  float i_WeightOfEdge); 
            void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
            GraphEdge* FindEdgeInGraph(int i_OutVertex, int i_InVertex);
            AdjancencyListGraph& operator=(const AdjancencyListGraph& other) = delete;
    };
}



