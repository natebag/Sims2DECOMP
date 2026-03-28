struct ERC;

struct StateMachine {
    void Draw(ERC *rc);
};

struct LiveModeChangeHouseStateMachine : public StateMachine {
    void Draw(ERC *rc);
};

void LiveModeChangeHouseStateMachine::Draw(ERC *rc) {
    StateMachine::Draw(rc);
}
