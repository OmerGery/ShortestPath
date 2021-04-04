#include "DynamicList.h"
#include "DynamicArray.h"

namespace AlgoGraph
{
    struct EdgeInAdjacencyList
    {
        int m_NeighboorVertex;
        int m_EdgeWeight;

        bool operator==(const EdgeInAdjacencyList& other)
        {
            if(m_NeighboorVertex == other.m_NeighboorVertex)
                return true;
            else return false;
        }
    };

    class AdjancencyListGraph
    {
    
        private:
    

        DynamicArray<DynamicList<EdgeInAdjacencyList>> m_AdjancencyList;

        public:

        AdjancencyListGraph(int i_NumberOfVertex);
        AdjancencyListGraph(ifstream& i_InputFile, int i_NumberOfVertex);
        ~AdjancencyListGraph();
        void AddEdgeToGraph(int i_OutVertex, int i_InVertex,  int i_WeightOfEdge); 
        void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
        EdgeInAdjacencyList* FindEdgeInGraph(int i_OutVertex, int i_InVertex);
        

    };
}



