#include <GLM/glm.hpp>
#include <GLM/gtx/hash.hpp>
#include <vector>
#include <functional>
#include <unordered_set>

struct SVertex
{
	glm::vec3 Pos;
	bool operator==(const SVertex& vVertex) const
	{
		return (std::abs(this->Pos.x - vVertex.Pos.x) < 0.000001) && (std::abs(this->Pos.y - vVertex.Pos.y) < 0.000001) && (std::abs(this->Pos.z - vVertex.Pos.z) < 0.000001);
	}
	bool operator<(const SVertex & vVertex) const
	{
		return std::hash<glm::vec3>()(Pos) < std::hash<glm::vec3>()(vVertex.Pos);
	}

	SVertex() = default;
	SVertex(const glm::vec3 & vPos) : Pos(vPos)
	{ }
};

struct SVertexHash : std::unary_function<const SVertex&, size_t>
{
	std::size_t operator()(const SVertex& vVertex) const {
		size_t hash = std::hash<uint32_t>()(vVertex.Pos.x);
		hash = hash * 37 + std::hash<uint32_t>()(vVertex.Pos.y);
		hash = hash * 37 + std::hash<uint32_t>()(vVertex.Pos.z);
		return hash;
	}
};

int main()
{
	std::vector<SVertex> VerticesSet = {
		SVertex(glm::vec3(-4.11088991, 3.61059999, -0.667829990)),
		SVertex(glm::vec3(-4.70743990, 3.43816996, -0.552455008)),
		SVertex(glm::vec3(-4.20061016, 3.46117997,  0.371235013)),
		SVertex(glm::vec3(-3.50048995, 3.42499995,  1.08023000 )),
		SVertex(glm::vec3(-4.11088991, 3.61059999, -0.667829990)),
		SVertex(glm::vec3(-4.70743990, 3.43816996, -0.552455008)),
		SVertex(glm::vec3(-4.74750996, 3.39103007, -1.00347996 )),
		SVertex(glm::vec3(-3.45859003, 3.57664990,  0.534942985))
	};
	std::unordered_set<SVertex, SVertexHash> VerticesInSidesSet;

	for (auto& Item : VerticesSet)
		VerticesInSidesSet.insert(Item);


	return 0;
}