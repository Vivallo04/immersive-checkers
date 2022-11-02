#ifndef IMMERSIVE_CHECKERS_BASESTATE_HPP
#define IMMERSIVE_CHECKERS_BASESTATE_HPP


class BaseState
{
public:
    virtual void Init(){};
    virtual void Enter(){};
    virtual void Exit(){};
    virtual void Update(float delta){};
    virtual void Render(){};
};


#endif //IMMERSIVE_CHECKERS_BASESTATE_HPP
