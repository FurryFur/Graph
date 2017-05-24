#pragma once
#include "Graph.h"
class CAdjListGraph : public ABGraph
{
public:
	CAdjListGraph();
	virtual ~CAdjListGraph();

	// Inherited via IGraph
	virtual void AddVertex() override;
	virtual void CreateLink(size_t _szVertFrom, size_t _szVertTo) override;
	virtual std::vector<size_t> GetAdjacent(size_t _szVertFrom) const override;
	virtual size_t GetSize() const override;

private:
	std::vector<std::vector<size_t>> m_adjList;
};

