struct StateMachine {
    void Update(float dt);
};

struct LoadingScreenStateMachine : public StateMachine {
    void Update(float dt);
};

void LoadingScreenStateMachine::Update(float dt) {
    StateMachine::Update(dt);
}
