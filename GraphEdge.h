#pragma once
#include "ConstTypes.h"

namespace AlgoGraph {
	class GraphEdge
	{
		private:
			Weight m_Weight;
			int m_InVertex;
			int m_OutVertex;

		public:
			GraphEdge();
			GraphEdge(int o_OutVertex,int o_InVertex, float o_edgeWeight);
			GraphEdge(int o_OutVertex, int o_InVertex);
			bool GetEdgeWeight(float& o_weight);
			Weight GetEdgeWeight();
			bool IsWeightInfinity();
			void SetEdgeWeight(float o_weight);
			void SetInfinityWeight();

			int GetInVertex();
			void SetInVertex(int o_InVertex);
			int GetOutVertex();
			void SetOutVertex(int o_OutVertex);

			bool operator==(const GraphEdge& other);
		

	};
}