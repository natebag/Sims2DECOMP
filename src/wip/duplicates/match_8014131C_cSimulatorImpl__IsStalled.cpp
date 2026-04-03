// 0x8014131C (8 bytes)
class cSimulatorImpl {
public:
    int IsStalled();
};

int cSimulatorImpl::IsStalled() {
    return *(int*)((char*)this + 0x9C);
}
