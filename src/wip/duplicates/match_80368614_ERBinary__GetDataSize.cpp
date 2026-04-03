// 0x80368614 (8 bytes)
class ERBinary {
public:
    int GetDataSize();
};

int ERBinary::GetDataSize() {
    return *(int*)((char*)this + 0x18);
}
