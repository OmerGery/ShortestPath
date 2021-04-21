#pragma once
#define NO_PARENT -1
namespace AlgoGraph
{
	enum class Result
	{
		SUCCESS = 0,
		NEGATIVE_CYCLE = 1,
		INFINITY_PATH = 2,
	};
	struct Weight
	{
		float weight;
		bool infinity;
	};
	struct VertexDV
	{
		Weight VertexWeight;
		int Vertex;
	};
	
}