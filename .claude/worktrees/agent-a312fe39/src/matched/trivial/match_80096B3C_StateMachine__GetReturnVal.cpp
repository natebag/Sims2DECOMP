// 0x80096B3C (8 bytes)
class StateMachine {
public:
    int GetReturnVal();
};

int StateMachine::GetReturnVal() {
    return *(int*)((char*)this + 0x90);
}
