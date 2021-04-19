

namespace AlgoGraph
{
	class AbstractGraph
	{
		public:
            //list
            AdjancencyListGraph(int i_NumberOfVertex);
            AdjancencyListGraph(ifstream& i_InputFile, int i_NumberOfVertex, int i_fileIndentation);
            static AdjancencyListGraph MakeEmptyGraph(int i_NumberOfVertex);
            bool isAdjacent(int i_OutVertex, int i_InVertex);
            DynamicList<EdgeInAdjacencyList> GetAdjList(int i_OutVertex);
            void IsEdgeInRange(int i_OutVertex, int i_InVertex);
            ~AdjancencyListGraph();
            void AddEdgeToGraph(int i_OutVertex, int i_InVertex, int i_WeightOfEdge);
            void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
            EdgeInAdjacencyList* FindEdgeInGraph(int i_OutVertex, int i_InVertex);

			//matrix
			AdjacencyMatrixGraph(int i_NumberOfVertex);
			AdjacencyMatrixGraph(ifstream& i_InputFile, int i_NumberOfVertex, int i_fileIndentation);
			~AdjacencyMatrixGraph();
			void MakeEmptyGraph(int i_NumberOfVertex);
			bool isAdjacent(int i_OutVertex, int i_InVertex);
			void IsEdgeInRange(int i_OutVertex, int i_InVertex);
			DynamicList<int> GetAdjList(int i_OutVertex);
			void AddEdgeToGraph(int i_OutVertex, int i_InVertex, int i_WeightOfEdge);
			void RemoveEdgeFromGraph(int i_OutVertex, int i_InVertex);
	};
}