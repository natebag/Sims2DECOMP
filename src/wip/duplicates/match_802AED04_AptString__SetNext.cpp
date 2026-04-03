// 0x802AED04 (8 bytes)
class AptString {
public:
    void SetNext(int p);
};

void AptString::SetNext(int p) {
    *(int*)((char*)this + 0x10) = p;
}
