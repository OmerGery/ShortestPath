#include "minHeap.h"
#include <iostream>

namespace AlgoGraph
{
	minHeap::minHeap(int capacity)
	{
		heapArray = new VertexDV[capacity];
		maxSize = capacity;
		heapSize = 0;
		allocated = 1; //allocation has been made here- only give is size of array from user
	}

	//Building minimum heap with floyd algorithem
	minHeap::minHeap(Weight Degrees[], int size)
	{
		heapSize = size;
		maxSize = size;
		for (int i = 1; i <= size; i++)
		{
			heapArray[i].VertexWeight= Degrees[i];
			heapArray[i].Vertex = i;
		}
		allocated = 0; //no allocation made- array is given from outer data
		int n = (size / 2) - 1;
		for (int i = n; i >= 0; i--)
			FixHeap(i);
	}
	minHeap::~minHeap()
	{
		if (allocated)
			delete[] heapArray;
		heapArray = nullptr;
	}
	int minHeap::Left(int i)
	{
		return(2 * i + 1);
	}
	int minHeap::Right(int i)
	{
		return(2 * i + 2);
	}
	int minHeap::Parent(int i)
	{
		return ((i - 1) / 2);
	}

	void Swap(VertexDV* a, VertexDV* b)
	{
		VertexDV temp = *a;
		*a = *b;
		*b = temp;
	}

	void minHeap::FixHeap(int i)
	{
		int min =i;
		int left = Left(i);
		int right = Right(i);

		if (left < heapSize && heapArray[left].VertexWeight.weight < heapArray[i].VertexWeight.weight)
			min = left;
		else min = i;
		if (right < heapSize && heapArray[right].VertexWeight.weight < heapArray[min].VertexWeight.weight)
			min = right;

		if (min != i)
		{
			Swap(heapArray+i, heapArray+min);
			FixHeap(min);
		}
	}
	VertexDV minHeap::Min()
	{
		return heapArray[0];
	}
	VertexDV minHeap::DeleteMin()
	{
		if (heapSize < 1)
			throw "There is no min to return because the heap is empty";
		else
		{
			VertexDV min = heapArray[0];
			heapSize--;
			heapArray[0] = heapArray[heapSize];
			FixHeap(0);
			return min;
		}
	}

	void minHeap::Insert(VertexDV item)
	{
		if (heapSize == maxSize)
			throw "The heap is full, cant insert more";
		if (item.VertexWeight.infinity)
		{
			heapArray[heapSize] = item;
			heapSize++;
		}
		else
		{
			int i = heapSize;
			heapSize++;
			while ((i > 0) && (heapArray[Parent(i)].VertexWeight.weight > item.VertexWeight.weight))
			{
				heapArray[i] = heapArray[Parent(i)];
				i = Parent(i);
			}
			heapArray[i] = item;
		}

	}

	bool minHeap::isEmpty()
	{
		return !heapSize; //if heapsize>0 will return false- not empty, otherwise will return true- empty
	}

	void minHeap::make_empty()
	{
		heapSize = 0;
	}
}