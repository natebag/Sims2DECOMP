// 0x800569FC (8 bytes)
class ISimInstance {
public:
    int GetCursFlags();
};

int ISimInstance::GetCursFlags() {
    return *(int*)((char*)this + 0x32C);
}
