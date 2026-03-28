// 0x800A6E68 (8 bytes)
class StringBuffer2 {
public:
    int c_str();
};

int StringBuffer2::c_str() {
    return *(int*)((char*)this + 0x0);
}
