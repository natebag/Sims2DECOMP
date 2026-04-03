// 0x80141BA0 (8 bytes)
class cSimulatorImpl {
public:
    int GetPassiveInfluenceSystem();
};

int cSimulatorImpl::GetPassiveInfluenceSystem() {
    return *(int*)((char*)this + 0x174);
}
