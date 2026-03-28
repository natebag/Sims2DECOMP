// 0x802AED0C (8 bytes)
class AptString {
public:
    int GetNext();
};

int AptString::GetNext() {
    return *(int*)((char*)this + 0x10);
}
