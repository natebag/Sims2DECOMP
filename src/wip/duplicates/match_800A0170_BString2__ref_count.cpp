// 0x800A0170 (8 bytes)
class BString2 {
public:
    int ref_count();
};

int BString2::ref_count() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0xC);
}
