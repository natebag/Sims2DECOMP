// 0x800A6E70 (8 bytes)
class StringBuffer2 {
public:
    int buffer();
};

int StringBuffer2::buffer() {
    return *(int*)((char*)this + 0x0);
}
