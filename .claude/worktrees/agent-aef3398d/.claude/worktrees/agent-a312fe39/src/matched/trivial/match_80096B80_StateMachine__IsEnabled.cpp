// 0x80096B80 (8 bytes)
class StateMachine {
public:
    int IsEnabled();
};

int StateMachine::IsEnabled() {
    return *(int*)((char*)this + 0x94);
}
