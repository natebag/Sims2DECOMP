// 0x800A6D1C (8 bytes)
class StringBuffer2 {
public:
    int capacity();
};

int StringBuffer2::capacity() {
    return *(int*)((char*)this + 0x4);
}
