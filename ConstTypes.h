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

	enum class QueueType
	{
		MinHeap = 0,
		Array = 1,
	};

	struct Weight
	{
		float weight;
		bool infinity;

		bool operator <(const Weight& other)
		{
			if(this->infinity && other.infinity) //both inf
			{
			return false;
			}
			else if (this->infinity && !other.infinity) // inf < not inf ---> false cause bigger
			{
				return false;
			}
			else if (!this->infinity && other.infinity) // not inf < inf ---> true cause smaller
			{
				return true;
			}
			
			else
			{
				return this->weight < other.weight;
			}
		}

	};

	struct VertexDV
	{
		Weight VertexWeight;
		int Vertex;

		bool operator <(const VertexDV& other)
		{
			return this->VertexWeight < other.VertexWeight;
		}
		
	};
	
}