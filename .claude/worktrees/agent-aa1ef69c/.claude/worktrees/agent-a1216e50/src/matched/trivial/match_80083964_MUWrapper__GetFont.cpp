// 0x80083964 (8 bytes)
class MUWrapper {
public:
    int GetFont();
};

int MUWrapper::GetFont() {
    return *(int*)((char*)this + 0xA4);
}
