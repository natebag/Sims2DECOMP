// 0x800B43E4 (8 bytes)
class Commander {
public:
    int GetNext();
};

int Commander::GetNext() {
    return *(int*)((char*)this + 0x0);
}
