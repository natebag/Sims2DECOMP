// 0x8017B980 (8 bytes)
class FlowGotoTarget {
public:
    int GetStateRequest();
};

int FlowGotoTarget::GetStateRequest() {
    return *(int*)((char*)this + 0x84);
}
