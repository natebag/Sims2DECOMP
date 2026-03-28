// 0x80095E28 (8 bytes)
class StateMachine {
public:
    int GetCurStateStage();
};

int StateMachine::GetCurStateStage() {
    return *(int*)((char*)(*(int*)((char*)this + 0x3C)) + 0xC);
}
