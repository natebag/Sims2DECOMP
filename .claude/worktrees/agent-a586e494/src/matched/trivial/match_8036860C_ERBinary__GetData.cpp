// 0x8036860C (8 bytes)
class ERBinary {
public:
    int GetData();
};

int ERBinary::GetData() {
    return *(int*)((char*)this + 0x14);
}
