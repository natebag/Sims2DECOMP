// 0x8009C014 (8 bytes)
class BString {
public:
    int ref_count();
};

int BString::ref_count() {
    return *(int*)((char*)(*(int*)((char*)this + 0x0)) + 0xC);
}
