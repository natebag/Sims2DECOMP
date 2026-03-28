// 0x800A6718 (8 bytes)
class StringBuffer {
public:
    int c_str();
};

int StringBuffer::c_str() {
    return *(int*)((char*)this + 0x0);
}
