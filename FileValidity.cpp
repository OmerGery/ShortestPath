#include "FileValidity.h"
#include <iostream>
using namespace std;
namespace AlgoGraph
{
	bool CheckInputFileValidity(string i_inputFileName, int& endLocation)
	{
		ifstream inputFile;
		inputFile.open(i_inputFileName);
		string line;
		char currentChar;
		endLocation = 0;
		for (int i = 0; i < 3; i++)
		{
			currentChar = inputFile.get();
			endLocation++;
			if (currentChar > '9' || currentChar < '1')
				return false;
			while (currentChar != '\n')
			{
				if (currentChar > '9' || currentChar < '0')
				{
					return false;
				}
				currentChar = inputFile.get();
				endLocation++;
			}
		}
		int numbers = 0;
		bool lastWasSpace = false;
		bool optionForPoint = false;
		bool onlySpaces = false;
		int placeInLine = 0;
		while (!inputFile.eof())
		{
			getline(inputFile, line);
			currentChar = line[placeInLine];
			placeInLine++;
			endLocation++;
			if (currentChar > '9' || currentChar < '1')
				return false;
			while (currentChar != '\n')
			{
				if (currentChar == ' ')
				{
					if (lastWasSpace)
						return false;
					lastWasSpace = true;
					numbers++;
					if (numbers == 2)
						optionForPoint = true;
				}
				else if (currentChar > '9' || currentChar < '0')
				{
					return false;
				}
				else
				{
					lastWasSpace = false;
				}

				if (numbers == 2)
				{
					if (optionForPoint)
					{
						optionForPoint = false;
						if (currentChar > '9' || currentChar < '0')
						{
							if (currentChar != '.')
								return false;
						}
					}
					numbers++;
				}
				if (numbers == 3)
				{
					if (currentChar != '\t' && currentChar != ' ' && currentChar)
						if (currentChar != '\n')
							return false;
				}
			}
		}
		inputFile.close();
		return true;
	}
	bool firstThreeSelectionAreValid(int numberOfVertex, int pathStartingVertex, int pathEndVertex)
	{
		if (numberOfVertex < 0)
			return false;
		if (pathStartingVertex > numberOfVertex || pathStartingVertex < 1)
			return false;
		if (pathEndVertex > numberOfVertex || pathEndVertex < 1)
			return false;
		return true;
	}

	void PrintWrongInput()
	{
		cout << "invalid input";
		exit(1);
	}


}