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

void CAdjListGraph::CreateLink(size_t _iVertFrom, size_t _iVertTo)
{
	// Add new connection to the adjacency list if it doesn't already exist
	std::vector<size_t>& vecAdjVerts = m_adjList.at(_iVertFrom);
	if (std::find(vecAdjVerts.begin(), vecAdjVerts.end(), _iVertTo) == vecAdjVerts.end())
	{
		m_adjList.at(_iVertFrom).push_back(_iVertTo);
	}
}

std::vector<size_t> CAdjListGraph::GetAdjacent(size_t _iVertFrom) const
{
	return m_adjList.at(_iVertFrom);
}

size_t CAdjListGraph::GetSize() const
{
	return m_adjList.size();
}
