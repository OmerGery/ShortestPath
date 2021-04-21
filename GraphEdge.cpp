#include "GraphEdge.h"

namespace AlgoGraph
{

	GraphEdge::GraphEdge() : GraphEdge(0, 0) {}


	GraphEdge::GraphEdge(int o_OutVertex, int o_InVertex, float o_edgeWeight)
	{
		m_Weight.weight = o_edgeWeight;
		m_Weight.infinity = false;
		m_OutVertex = o_OutVertex;
		m_InVertex = o_InVertex;
	}

	GraphEdge::GraphEdge(int o_OutVertex, int o_InVertex)
	{
		m_Weight.weight = 1;
		m_Weight.infinity = true;
		m_OutVertex = o_OutVertex;
		m_InVertex = o_InVertex;
	}

	/*get edge weight is a bool function ->
	if weight is infinity returns true,
	if not the weight returns as refrenced value and function returns false*/
	bool GraphEdge::GetEdgeWeight(float& o_weight)
	{
		if (m_Weight.infinity == false)
		{
			o_weight = m_Weight.weight;
			return false;
		}
		else return true;
	}
	EdgeWeight GraphEdge::GetEdgeWeight()
	{
		return m_Weight;
	}

	bool GraphEdge::IsWeightInfinity()
	{
		return m_Weight.infinity;
	}


	//o_inf default value for set is false, because set means setting actual value and not infinity
	void GraphEdge::SetEdgeWeight(float o_weight)
	{
		m_Weight.weight = o_weight;
		m_Weight.infinity = false;
	}

	void GraphEdge::SetInfinityWeight()
	{
		m_Weight.infinity = true;
	}

	void GraphEdge::SetInVertex(int o_InVertex)
	{
		m_InVertex = o_InVertex;
	}
	void GraphEdge::SetOutVertex(int o_OutVertex)
	{
		m_OutVertex = o_OutVertex;
	}


	int GraphEdge::GetInVertex()
	{
		return m_InVertex;
	}

	int GraphEdge::GetOutVertex()
	{
		return m_OutVertex;
	}

	bool GraphEdge::operator==(const GraphEdge& other)
	{
		if (m_InVertex == other.m_InVertex && m_OutVertex == other.m_OutVertex)
			return true;
		else return false;
	}
}