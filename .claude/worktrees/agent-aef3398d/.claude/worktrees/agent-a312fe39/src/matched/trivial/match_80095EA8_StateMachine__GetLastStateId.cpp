// 0x80095EA8 (8 bytes)
class StateMachine {
public:
    int GetLastStateId();
};

int StateMachine::GetLastStateId() {
    return *(int*)((char*)(*(int*)((char*)this + 0x44)) + 0x0);
}
