// 0x80093BD4 (8 bytes)
class MUStateMachine {
public:
    int GetMUWrapper();
};

int MUStateMachine::GetMUWrapper() {
    return *(int*)((char*)this + 0x98);
}
