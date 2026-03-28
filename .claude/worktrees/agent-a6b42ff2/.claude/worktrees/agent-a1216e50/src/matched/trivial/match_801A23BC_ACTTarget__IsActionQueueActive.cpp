// 0x801A23BC (8 bytes)
class ACTTarget {
public:
    int IsActionQueueActive();
};

int ACTTarget::IsActionQueueActive() {
    return *(int*)((char*)this + 0xD0);
}
