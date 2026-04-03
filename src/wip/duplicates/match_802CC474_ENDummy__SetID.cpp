// 0x802CC474 (8 bytes)
class ENDummy {
public:
    void SetID(int p);
};

void ENDummy::SetID(int p) {
    *(int*)((char*)this + 0x40) = p;
}
