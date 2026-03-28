// 0x80096504 (16 bytes)
class StateMachineStatus {
public:
    char pad[20];
    float m_secondsInCurState;

    void AddToSecondsInCurState(float dt);
};

void StateMachineStatus::AddToSecondsInCurState(float dt) {
    m_secondsInCurState += dt;
}
