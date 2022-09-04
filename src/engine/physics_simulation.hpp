#include "src/math/matrix.hpp"
#include "src/math/vector.hpp"
#include "src/engine/object.hpp"


namespace deengine {
    class PhysicsWorld {
    private:
        std::vector<Object*> m_objects;
        vector2 m_gravity = vector2(0, -9.81f);
    
    public:
        void AddObject   (Object* object);
        void RemoveObject(Object* object);
    
        void Step(float dt);
    };
}