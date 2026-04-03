// 0x80141B58 (8 bytes)
class cSimulatorImpl {
public:
    int GetObjectsValue();
};

int cSimulatorImpl::GetObjectsValue() {
    return *(int*)((char*)this + 0x88);
}
