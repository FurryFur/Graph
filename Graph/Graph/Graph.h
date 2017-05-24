#pragma once

#include <vector>

class ABGraph
{
public:
	virtual ~ABGraph() {};

	virtual void AddVertex() = 0;
	virtual void CreateLink(size_t _szVertFrom, size_t _szVertTo) = 0;
	virtual std::vector<size_t> GetAdjacent(size_t _szVertFrom) const = 0;
	virtual size_t GetSize() const = 0;

	virtual void CreateLink(size_t _szVertFrom, std::initializer_list<size_t> _szVertsTo);
	virtual std::vector<size_t> DepthFirstTraversal(size_t _szVertStart) const;
	virtual std::vector<size_t> BreadthFirstTraversal(size_t _szVertStart) const;

protected:
	ABGraph() {};
};