#include "Vector2.hpp"
#include <vector>

class Graph {
	private:
		std::vector<const Vector2*> points;
		const int _width;
		const int _height;

	public:
		Graph();
		Graph(const int height, const int width);
		void	addPoint(const Vector2* point);
};
