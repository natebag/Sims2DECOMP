struct StateMachine {
    void Update(float dt);
};

struct LiveModeChangeHouseStateMachine : public StateMachine {
    void Update(float dt);
};

void LiveModeChangeHouseStateMachine::Update(float dt) {
    StateMachine::Update(dt);
}
