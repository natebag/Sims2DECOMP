// 0x8009C070 (8 bytes)
class BString {
public:
    int len();
};

int BString::len() {
    return (int)((char*)(*(int*)((char*)this + 0x0)) + 0x4);
}
