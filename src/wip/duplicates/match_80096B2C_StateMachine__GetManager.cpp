// 0x80096B2C (8 bytes)
class StateMachine {
public:
    int GetManager();
};

int StateMachine::GetManager() {
    return *(int*)((char*)this + 0x20);
}
