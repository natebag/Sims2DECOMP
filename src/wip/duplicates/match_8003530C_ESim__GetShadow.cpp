// 0x8003530C (8 bytes)
class ESim {
public:
    int GetShadow();
};

int ESim::GetShadow() {
    return *(int*)((char*)this + 0x3E0);
}
