// 0x800A6720 (8 bytes)
class StringBuffer {
public:
    int buffer();
};

int StringBuffer::buffer() {
    return *(int*)((char*)this + 0x0);
}
