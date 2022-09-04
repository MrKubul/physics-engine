#include "src/math/matrix.hpp"
#include "src/math/vector.hpp"

namespace deengine {
    struct Object {
	Vector2<double> position; 
	vector2<double> velocity;
	vector2<double> force;
	double mass;
    };
}