// 0x80096B34 (8 bytes)
class StateMachine {
public:
    float GetFrameDeltaTime();
};

float StateMachine::GetFrameDeltaTime() {
    return *(float*)((char*)this + 0x28);
}
