// Cpt S 223 - Directed Graph Homework
// DirectedGraph.cpp
// (put student name here)
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{
	// No initialization needed
}

DirectedGraph::~DirectedGraph()
{
	// Free all nodes and edges
	for (int i = 0; i < m_nodes.size(); i++)
	{
		delete m_nodes[i];
	}
	m_nodes.clear();
	for (int i = 0; i < m_edges.size(); i++)
	{
		delete m_edges[i];
	}
	m_edges.clear();

	// Make sure the node map is cleared too
	m_nodeMap.clear();
}

bool DirectedGraph::AddNode(const string& nodeName, const string& nodeData)
{
	// check if node exists
	if (NodeExists(nodeName))
		return false;
	else
	{
		// if node doesn't exist, then push it onto vector
		Node *newNode = new Node(nodeName, nodeData);
		m_nodes.push_back(newNode);
		return true;
	}
}
	
// Adds an edge to the graph that starts at the source node, 
// and goes to the target node.
// If the graph already contains an edge going from the specified 
// source to target node then false is returned and no modification 
// occurs.
// If either or both of the two nodes don't exist in the graph then 
// false is returned and no modification occurs.
// Otherwise the edge will be added. Note that an edge from N1 (source) 
// to N2 (target) is different than an edge from N2 (source) to N1 (target).
bool DirectedGraph::AddEdge(const string& sourceNodeName,
	const string& targetNodeName)
{
	int srcI = 0, tarI = 0;


	//check if source and target nodes exist
	if (!NodeExists(sourceNodeName) || !NodeExists(targetNodeName))
		return false;
	//check if this edge already exists
	else if (EdgeExists(sourceNodeName, targetNodeName))
		return false;
	else
	{
		// find the indices of the source and target
		for (int i = 0; i < m_nodes.size(); i++)
		{
			if (m_nodes[i]->Name == sourceNodeName)
				srcI = i;
			if (m_nodes[i]->Name == targetNodeName)
				tarI = i;
		}

		//create the new edge and update the nodes
		Edge *newEdge = new Edge(srcI, tarI);

		m_nodes[tarI]->In.push_back(newEdge);
		m_nodes[srcI]->Out.push_back(newEdge);

		m_edges.push_back(newEdge);
	}
}

// Gets the degree of the node with the specified name. -1 is returned 
// if no such node exists in the graph.
int DirectedGraph::GetDegree(const string& nodeName) const
{
	// returns the sum of edges coming in and out
	int curIndex, curDegree = -1;

	if (NodeExists(nodeName))
	{
		for (int i = 0; i < m_nodes.size(); i++)
		{
			if (m_nodes[i]->Name == nodeName)
				curIndex = i;			
		}

		curDegree = m_nodes[curIndex]->In.size() + m_nodes[curIndex]->Out.size();
	}

	return curDegree;
}

int DirectedGraph::GetNodeIndex(const string& nodeName) const
{
	// Get the index of the node from the hash map
	unordered_map<string, int>::const_iterator it = m_nodeMap.find(nodeName);
	if (it == m_nodeMap.end()) { return -1; }
	return it->second;
}

// Gets the shortest path from the specified start to end nodes. If no path exists 
// from the start to end nodes then false is returned and the traversalList object 
// is not modified. Otherwise the traversalList is filled with strings representing 
// the sequence of nodes for the shortest path from start to end. These strings 
// will be the node names if nodeDataInsteadOfName is false, otherwise they will be 
// the node data values (which are strings).
bool DirectedGraph::GetShortestPath(
	const string& startNode, const string& endNode, 
	bool nodeDataInsteadOfName, vector<string>& traversalList) const
{
	int startI = -1;
	int endI = -1;
	int curI = -1;
	int cost = 0;
	int i;

	// temporary list
	vector<string> tempList;

	// "table" for method
	vector<bool> visited;
	vector<int> distances;

	// find the start and end indices
	for (i = 0; i < m_nodes.size(); i++)
	{
		if (m_nodes[i]->Name == startNode)
			startI = i;
		if (m_nodes[i]->Name == endNode)
			endI = i;
	}

	// make sure they exist
	if (startI == -1 || endI == -1)
	{
		return false;
	}

	// update all values to common value
	for (i = 0; i < m_nodes.size(); i++)
	{
		visited.push_back(false);
		distances.push_back(1000);
	}

	curI = startI;
	distances[startI] = 0;

	// go until you reach the end
	while (m_nodes[curI] != m_nodes[endI])
	{
		// use every outgoing edge
		for (i = 0; i < m_nodes[curI]->Out.size(); i++)
		{
			cost = distances[curI] + 1;
			if (cost < distances[m_nodes[curI]->Out[i]->targetI])
				distances[m_nodes[curI]->Out[i]->targetI] = cost;
		}

		//update current node to visited
		visited[curI] = true;
		cost = 1000;

		// move to the node with the lowest cost
		for (i = 0; i < m_nodes.size(); i++)
		{
			if (distances[i] < cost && !visited[i])
			{
				cost = distances[i];
				curI = i;
			}
		}

		// make sure it's not a dead end or still at the start node
		if (distances[curI] == 1000 || distances[curI] == 0)
			return false;
	}

	// make sure it's not a dead end or still at the start node
	if (distances[curI] == 1000)
		return false;

	// create current edge index
	int curEdge = -1;

	//work backwards to find path
	do
	{
		// look at all edges coming in
		for (i = 0; i < m_nodes[curI]->In.size(); i++)
		{
			// find the one that has a cost of current -1
			if (distances[m_nodes[curI]->In[i]->srcI] + 1 == distances[curI])
			{
				// if node data is true then push the nodes data. else push the name
				if (nodeDataInsteadOfName)
					tempList.push_back(m_nodes[curI]->Data);
				else
					tempList.push_back(m_nodes[curI]->Name);
				curI = m_nodes[curI]->In[i]->srcI;
			}
		}
	} while (m_nodes[curI] != m_nodes[startI]);

	// if node data is true then push the nodes data. else push the name
	if (nodeDataInsteadOfName)
		tempList.push_back(m_nodes[curI]->Data);
	else
		tempList.push_back(m_nodes[curI]->Name);

	// reverse the list and push to output
	for (i = tempList.size() -1; i >= 0; i--)
	{
		traversalList.push_back(tempList[i]);
	}

	return true;
}

bool DirectedGraph::NodeExists(const string& nodeName) const
{

	// return true once you find the node
	for (int i = 0; i < m_nodes.size(); i++)
	{
		if (m_nodes[i]->Name == nodeName)
			return true;
	}

	return false;
}

bool DirectedGraph::EdgeExists(const string& snn, const string& tnn)
{
	// checks to see if the edge already exists
	for (int i = 0; i < m_edges.size(); i++)
	{
		if ((m_nodes[m_edges[i]->srcI]->Name == snn) &&
			(m_nodes[m_edges[i]->targetI]->Name == snn))
			return true;
	}

	return false;
}