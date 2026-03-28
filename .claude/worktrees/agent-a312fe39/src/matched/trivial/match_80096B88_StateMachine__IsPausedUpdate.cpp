// 0x80096B88 (8 bytes)
class StateMachine {
public:
    int IsPausedUpdate();
};

int StateMachine::IsPausedUpdate() {
    return *(int*)((char*)this + 0x24);
}
