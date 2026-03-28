struct StateMachine {
    void Update(float dt);
};

struct MUStateMachine : public StateMachine {
    void Update(float dt);
};

void MUStateMachine::Update(float dt) {
    StateMachine::Update(dt);
}
