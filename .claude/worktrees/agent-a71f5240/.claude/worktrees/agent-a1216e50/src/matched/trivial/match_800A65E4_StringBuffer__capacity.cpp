// 0x800A65E4 (8 bytes)
class StringBuffer {
public:
    int capacity();
};

int StringBuffer::capacity() {
    return *(int*)((char*)this + 0x4);
}
