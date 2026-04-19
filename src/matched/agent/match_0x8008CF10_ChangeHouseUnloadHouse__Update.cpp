/* ChangeHouseUnloadHouse::Update(float) at 0x8008CF10 (44B) */

struct StateMachine_CHUU {
    void SetNextState(int id, float delay);
};

struct StateMachineState_CHUU {
    char pad[0x08];
    StateMachine_CHUU* m_owner;
    void OwnerSetNextState(int id, float delay);
};

struct ChangeHouseUnloadHouse_U : public StateMachineState_CHUU {
    void Update(float dt);
};

void ChangeHouseUnloadHouse_U::Update(float) {
    OwnerSetNextState(3, 0.0f);
}
