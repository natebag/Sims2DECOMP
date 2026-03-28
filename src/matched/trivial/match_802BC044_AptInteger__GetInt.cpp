// 0x802BC044 (8 bytes)
class AptInteger {
public:
    int GetInt();
};

int AptInteger::GetInt() {
    return *(int*)((char*)this + 0xC);
}
