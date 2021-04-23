#include <iostream>
#include <fstream>
#include "AbstractGraph.h"
#include "ConstTypes.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphAlgorithms.h"
#include "FileValidity.h"
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
			inputFileName = argv[1];
		else
			PrintWrongInput();
		if (!CheckInputFileValidity(inputFileName))
			PrintWrongInput();
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

	void RunBelmanFordMatrix(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestMatrixPath;

		Result PathOfAdjacencyMatrixGraph = GraphAlgorithms::BellmanFord(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath);

		if (PathOfAdjacencyMatrixGraph == Result::SUCCESS)
			cout << "Matrix Bellman Ford " << ShortestMatrixPath << endl;
		else if ((PathOfAdjacencyMatrixGraph == Result::NEGATIVE_CYCLE))
			cout << "Matrix Bellman Ford: There is a Negative Cycle in the graph" << endl;
		else 
			cout << "Matrix Bellman Ford: No route from " << OriginVertex << " to " << EndVertex << endl;
	}
	void RunBelmanFordList(AdjancencyListGraph& listImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestListPath;
		Result PathOfListGraph = GraphAlgorithms::BellmanFord(&listImplementedGraph, OriginVertex, EndVertex, ShortestListPath);
		if (PathOfListGraph == Result::SUCCESS)
			cout << "Adjacency Bellman Ford " << ShortestListPath << endl;
		else if ((PathOfListGraph == Result::NEGATIVE_CYCLE))
			cout << "Adjacency Bellman Ford: There is a Negative Cycle in the graph" << endl;
		else
			cout << "Adjacency Bellman Ford: No route from " << OriginVertex << " to " << EndVertex << endl;
	}
	void RunHeapMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestMatrixPath;

		if (GraphAlgorithms::DijkstraHeap(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath))
		{
			cout << "Matrix Dijkstra heap: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Matrix Dijkstra heap " << ShortestMatrixPath << endl;
	}
	void RunHeapListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestListPath;

		if (GraphAlgorithms::DijkstraHeap(&ListImplementedGraph, OriginVertex, EndVertex, ShortestListPath))
		{
			cout << "Adjacency Dijkstra heap: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Adjacency Dijkstra heap " << ShortestListPath << endl;
	}

	void RunArrayMatrixDijkstra(AdjacencyMatrixGraph& MatrixImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestMatrixPath;

		if (GraphAlgorithms::DijkstraArray(&MatrixImplementedGraph, OriginVertex, EndVertex, ShortestMatrixPath))
		{
			cout << "Matrix Dijkstra array: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Matrix Dijkstra array " << ShortestMatrixPath << endl;
	}
	void RunArrayListDijkstra(AdjancencyListGraph& ListImplementedGraph, int& OriginVertex, int& EndVertex)
	{
		float ShortestListPath;

		if (GraphAlgorithms::DijkstraArray(&ListImplementedGraph, OriginVertex, EndVertex, ShortestListPath))
		{
			cout << "Adjacency Dijkstra array: No Route from " << OriginVertex << " to " << EndVertex << endl;
		}
		else cout << "Adjacency Dijkstra array " << ShortestListPath << endl;
	}
}


