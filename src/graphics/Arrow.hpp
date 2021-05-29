#include "ShapeBase.hpp"

class Arrow : public ShapeBase {

private:
   

protected:
    float length;
    float tickness;

public:
    Arrow();
    Arrow(sf::Vector2f origin, float lenght, float tickness);
    void fillArea();
    virtual unsigned int getPointCount() const;
    virtual sf::Vector2f getPoint(unsigned int index) const;
    

};