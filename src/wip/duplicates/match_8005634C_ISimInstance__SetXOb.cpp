// 0x8005634C (8 bytes)
class ISimInstance {
public:
    void SetXOb(int p);
};

void ISimInstance::SetXOb(int p) {
    *(int*)((char*)this + 0x328) = p;
}
