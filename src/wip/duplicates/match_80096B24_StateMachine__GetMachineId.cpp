// 0x80096B24 (8 bytes)
class StateMachine {
public:
    int GetMachineId();
};

int StateMachine::GetMachineId() {
    return *(int*)((char*)this + 0x1C);
}
