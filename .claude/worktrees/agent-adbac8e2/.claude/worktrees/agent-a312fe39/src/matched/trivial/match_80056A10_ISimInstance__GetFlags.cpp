// 0x80056A10 (8 bytes)
class ISimInstance {
public:
    int GetFlags();
};

int ISimInstance::GetFlags() {
    return *(int*)((char*)this + 0x32C);
}
