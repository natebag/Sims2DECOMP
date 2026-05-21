// 0x800958D4 TheSimsStartScreenStateMachine::Update(float) (72B)

class StartScreenVars {
public:
    void Update(float dt);
};

class StateMachine {
public:
    void Update(float dt);
};

class TheSimsStartScreenStateMachine : public StateMachine {
public:
    void Update(float dt);
};

extern StartScreenVars* g_startScreenVars;  // SDA -24644

void TheSimsStartScreenStateMachine::Update(float dt) {
    g_startScreenVars->Update(dt);
    StateMachine::Update(dt);
}
