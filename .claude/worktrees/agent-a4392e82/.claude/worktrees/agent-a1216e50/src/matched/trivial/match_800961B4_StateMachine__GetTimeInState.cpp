// 0x800961B4 (8 bytes)
class StateMachine {
public:
    float GetTimeInState();
};

float StateMachine::GetTimeInState() {
    return *(float*)((char*)this + 0x50);
}
