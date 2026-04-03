struct StateMachineStatus {
    char pad[0x14];
    float m_secondsInCurState;

    void AddToSecondsInCurState(float dt);
};

void StateMachineStatus::AddToSecondsInCurState(float dt) {
    m_secondsInCurState += dt;
}
