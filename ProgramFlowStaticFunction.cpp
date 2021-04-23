#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"

namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName)
	{
		ifstream inputFile;
		inputFile.open(i_inputFileName);
		//Continue to check if file is ok......

		return true; //just for now
	}

	bool CheckComandArguments(int argc)
	{
		return argc == 2;
	}

	string GetFileName(int argc, char* argv[])
	{
		string inputFileName;
		if (CheckComandArguments(argc))
		{
			inputFileName = argv[1];
		}
		else
		{
			cout << "Error with program command arguments";
			exit(2);
		}

		if (!CheckInputFileValidity(inputFileName))
		{
			cout << "Wrong Input";
			exit(3);
		}

		return inputFileName;
	}

	void GetOriginVariables(int& NumberOfVertices, int& OriginVertex, int& EndVertex, int& FileIndentation, string FileName)
	{
		ifstream inputFile;
		inputFile.open(FileName);

		// we know that the file is valid
		inputFile >> NumberOfVertices;
		inputFile >> OriginVertex;
		inputFile >> EndVertex;
		FileIndentation = (int)inputFile.tellg();
		inputFile.close();

	}

	void RunBelmanFord(AdjancencyListGraph& listImplementedGraph, AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestMatrixPath;
		float ShortestListPath;

		Result PathOfAdjancencyListGraph = GraphAlgorithms::BellmanFord(&listImplementedGraph, OriginVertex, EndVertex, ShortestListPath);
		Result PathOfAdjacencyMatrixGraph = GraphAlgorithms::BellmanFord(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath);

		if (PathOfAdjancencyListGraph == Result::SUCCESS)
		{
			cout << "List Path Length: " << ShortestListPath << endl;
			cout << "Matrix Path Length: " << ShortestMatrixPath << endl;
		}
		else if ((PathOfAdjancencyListGraph == Result::NEGATIVE_CYCLE))
		{
			cout << "There is a negative cycle in the graph" << endl;
		}
		else if (PathOfAdjancencyListGraph == Result::INFINITY_PATH)
		{
			cout << EndVertex << " Is inaccessible from " << OriginVertex << endl;
		}
	}

	void RunHeapImplementedDijkstra(AdjancencyListGraph& listImplementedGraph, AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestMatrixPath;
		float ShortestListPath;

		if (GraphAlgorithms::DijkstraHeap(&listImplementedGraph, OriginVertex, EndVertex, ShortestListPath))
		{
			cout << "dijkstraHeap algorithem returned: path is infinity => inaccessible";
		}
		else cout << "Dijkstra-Heap LIST Path Length " << ShortestListPath << endl;


		if (GraphAlgorithms::DijkstraHeap(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath))
		{
			cout << "dijkstraHeap algorithem returned: path is infinity => inaccessible";
		}
		else cout << "Dijkstra-Heap MATRIX Path Length " << ShortestMatrixPath << endl;
	}

	void RunArrayImplementedDijkstra(AdjancencyListGraph& listImplementedGraph, AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestMatrixPath;
		float ShortestListPath;

		if (GraphAlgorithms::DijkstraArray(&listImplementedGraph, OriginVertex, EndVertex, ShortestListPath))
		{
			cout << "Dijkstra-Array algorithem returned: path is infinity => inaccessible";
		}
		else cout << "Dijkstra-Array: LIST Path Length " << ShortestListPath << endl;

		if (GraphAlgorithms::DijkstraArray(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath))
		{
			cout << "Dijkstra-Array algorithem returned: path is infinity => inaccessible";
		}
		else cout << "Dijkstra-Array: MATRIX Path Length " << ShortestMatrixPath << endl;
	}
}


