// 0x800A0188 (8 bytes)
class BString2 {
public:
    int len();
};

int BString2::len() {
    return (int)((char*)(*(int*)((char*)this + 0x0)) + 0x4);
}
