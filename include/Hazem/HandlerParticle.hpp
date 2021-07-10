#ifndef HAZEM_HANDLER_PARTICLE
#define HAZEM_HANDLER_PARTICLE

#include <Hazem/WrapperParticle.hpp>
#include <vector>
#include <mutex>


class HandlerParticle
{
    std::vector<WrapperParticle> handler;
    std::vector<Arrow> efield;
    sf::RenderTarget* target;
    
    void startField(const uint32_t&, const sf::Vector2u& size);
    void clearField();
    void updateField(Arrow*, Arrow*) const;
    static std::mutex mutex;

public:
    HandlerParticle() {}
    HandlerParticle(const uint32_t&, const sf::Vector2u&);
    ~HandlerParticle();
    
    /// add a particle by wrapper
    void insertParticle(const WrapperParticle&);

    void bindRender(sf::RenderTarget*);
    
    void createParticle(const WrapperParticle&);
    
    void clear();
    
    const WrapperParticle& getWrapper(const unsigned int&) const;
    const Particle& getParticle(const unsigned int&) const;
    size_t size() const;
    hz::Vector2 calcE_Force_fake(const Particle&) const;
    hz::Vector2 calcEForce(const Particle&) const;
    // void update();
    //first     -> update particle?
    //secon     -> update arrow?
    //third     -> update field?
    void update(const bool&, const bool&,
        const float&, const bool&);
    void draw(const bool&);

    /// Operators
    WrapperParticle& operator[](const size_t&);
};

#endif //!HAZEM_HANDLER_PARTICLE
