// Cpt S 223 - Directed Graph Homework
// Source.cpp
// DO NOT MODIFY THIS FILE

#include <iostream>
#include <fstream>
#include <string>
#include "DirectedGraph.h"

using namespace std;

void ProcessLine(string line, DirectedGraph& graph)
{
	if (line.substr(0, 5) == "node:")
	{
		int secondColonIndex = line.find(':', 5);
		string name = line.substr(5, secondColonIndex - 5);
		string data = line.substr(secondColonIndex + 1);
        while (name.substr(name.length()-1,1) == "\r" ||
            name.substr(name.length()-1,1) == "\n")
        {
            name = name.substr(0, name.length() - 1);
        }
		if (graph.AddNode(name, data))
		{
			cout << "Added node: " << name << endl;
		}
		else
		{
			cout << "Failed to add node: " << name << endl;
		}
	}
	else if (line.substr(0, 5) == "edge:")
	{
		int commaIndex = line.find(',', 5);
		string start = line.substr(5, commaIndex - 5);
		string end = line.substr(commaIndex + 1);
        if (end.substr(end.length()-1,1) == "\r")
        {
            end = end.substr(0, end.length() - 1);
        }
		if (graph.AddEdge(start, end))
		{
			cout << "Added edge from " << start;
			cout << " to " << end << endl;
		}
		else
		{
			cout << "Failed to add edge" << endl;
		}
	}
	else if (line.substr(0, 6) == "edge2:")
	{
		int commaIndex = line.find(',', 6);
		string start = line.substr(6, commaIndex - 6);
		string end = line.substr(commaIndex + 1);
        if (end.substr(end.length()-1,1) == "\r")
        {
            end = end.substr(0, end.length() - 1);
        }
		if (graph.AddEdge(start, end))
		{
			cout << "Added edge from " << start;
			cout << " to " << end << endl;
		}
		else
		{
			cout << "Failed to add edge from " << start;
            cout << " to " << end << endl;
		}
		if (graph.AddEdge(end, start))
		{
			cout << "Added edge from " << end;
			cout << " to " << start << endl;
		}
		else
		{
			cout << "Failed to add edge" << endl;
		}
	}
	else if (line.substr(0, 11) == "get_degree:")
	{
		string state = line.substr(11);
		cout << "Degree of " << state << " is ";
		cout << graph.GetDegree(state);
		cout << endl;
	}
	else if (line.substr(0, 22) == "display_shortest_path:")
	{
		int commaIndex = line.find(',', 22);
		string start = line.substr(22, commaIndex - 22);
		string end = line.substr(commaIndex + 1);

		cout << "Shortest path from " << start << " to " << end << ":" << endl;

		vector<string> traversal;
		if (graph.GetShortestPath(start, end, false, traversal))
		{
			int i;
			for (i = 0; i < traversal.size() - 1; i++)
			{
				cout << traversal[i] << " -> ";
			}
			cout << traversal[i] << endl;
		}
		else
		{
			cout << "No such path exists" << endl;
		}
	}
	else if (line.substr(0, 31) == "display_shortest_path_capitals:")
	{
		int commaIndex = line.find(',', 31);
		string start = line.substr(31, commaIndex - 31);
		string end = line.substr(commaIndex + 1);

		cout << "Shortest path (capitals) from " << start << " to " << end << ":" << endl;

		vector<string> traversal;
		if (graph.GetShortestPath(start, end, true, traversal))
		{
			int i;
			for (i = 0; i < traversal.size() - 1; i++)
			{
				cout << traversal[i] << " -> ";
			}
			cout << traversal[i] << endl;
		}
		else
		{
			cout << "No such path exists" << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	DirectedGraph graph;

	if (argc > 1)
	{
		cout << "Opening file " << argv[1] << endl;
		ifstream ifs;
		ifs.open(argv[1], ifstream::in);
        if (!ifs.is_open())
        {
            cout << "Couldn't open " << argv[1] << endl;
            return -2;
        }

		string line;
		while (true)
		{
			getline(ifs, line);
			ProcessLine(line, graph);
			if (line.empty() || ifs.eof())
			{
				break;
			}
		}

		cout << "Closing input file" << endl;
		ifs.close();
		cout << "Done" << endl;
		return 0;
	}

	cout << "Missing input file name" << endl;
	return -1;
}