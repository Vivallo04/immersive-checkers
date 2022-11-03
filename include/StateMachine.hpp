//
// Created by vivallo on 02/11/22.
//

#ifndef IMMERSIVE_CHECKERS_STATEMACHINE_HPP
#define IMMERSIVE_CHECKERS_STATEMACHINE_HPP

enum State
{
    PlayState,
    BeginGameState,
    GameOverState,
    StartState
};

class StateMachine
{
public:
    void Init();

    template<typename T>
    void Change(State state, T enterParameters);
    void Update(float delta);
    void Render();

};


#endif //IMMERSIVE_CHECKERS_STATEMACHINE_HPP
