// 0x80056354 (8 bytes)
class ISimInstance {
public:
    int GetXOb();
};

int ISimInstance::GetXOb() {
    return *(int*)((char*)this + 0x328);
}
