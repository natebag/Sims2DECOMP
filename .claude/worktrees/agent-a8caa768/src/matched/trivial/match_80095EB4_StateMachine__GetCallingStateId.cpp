// 0x80095EB4 (8 bytes)
class StateMachine {
public:
    int GetCallingStateId();
};

int StateMachine::GetCallingStateId() {
    return *(int*)((char*)(*(int*)((char*)this + 0x48)) + 0x0);
}
