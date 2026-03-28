// 0x80095B10 (8 bytes)
class StateMachineState {
public:
    int OwnerGetReturnVal();
};

int StateMachineState::OwnerGetReturnVal() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x90);
}
