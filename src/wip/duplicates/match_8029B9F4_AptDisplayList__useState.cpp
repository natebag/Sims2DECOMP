// 0x8029B9F4 (8 bytes)
class AptDisplayList {
public:
    void useState(int p);
};

void AptDisplayList::useState(int p) {
    *(int*)((char*)this + 0x0) = p;
}
