#include <algorithm>

#include "AdjListGraph.h"

CAdjListGraph::CAdjListGraph()
{
}


CAdjListGraph::~CAdjListGraph()
{
}

void CAdjListGraph::AddVertex()
{
	m_adjList.emplace_back();
}

void CAdjListGraph::CreateLink(size_t _szVertFrom, size_t _szVertTo)
{
	// Add new connection to the adjacency list if it doesn't already exist
	std::vector<size_t>& vecAdjVerts = m_adjList.at(_szVertFrom);
	if (std::find(vecAdjVerts.begin(), vecAdjVerts.end(), _szVertTo) == vecAdjVerts.end())
	{
		m_adjList.at(_szVertFrom).push_back(_szVertTo);
	}
}

std::vector<size_t> CAdjListGraph::GetAdjacent(size_t _szVertFrom) const
{
	return m_adjList.at(_szVertFrom);
}

size_t CAdjListGraph::GetSize() const
{
	return m_adjList.size();
}

