// 0x800B43DC (8 bytes)
class Commander {
public:
    int GetType();
};

int Commander::GetType() {
    return *(int*)((char*)this + 0x4);
}
