// 0x800569F4 (8 bytes)
class ISimInstance {
public:
    void SetCursFlags(int p);
};

void ISimInstance::SetCursFlags(int p) {
    *(int*)((char*)this + 0x32C) = p;
}
