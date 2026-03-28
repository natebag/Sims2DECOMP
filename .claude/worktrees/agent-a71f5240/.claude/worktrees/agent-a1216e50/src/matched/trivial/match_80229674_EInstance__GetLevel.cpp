// 0x80229674 (8 bytes)
class EInstance {
public:
    int GetLevel();
};

int EInstance::GetLevel() {
    return *(int*)((char*)this + 0x4);
}
