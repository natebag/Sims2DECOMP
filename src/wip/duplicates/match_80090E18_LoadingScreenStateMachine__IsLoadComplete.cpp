// 0x80090E18 (8 bytes)
class LoadingScreenStateMachine {
public:
    int IsLoadComplete();
};

int LoadingScreenStateMachine::IsLoadComplete() {
    return *(int*)((char*)this + 0xA4);
}
