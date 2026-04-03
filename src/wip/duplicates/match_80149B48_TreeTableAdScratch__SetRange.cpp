// 0x80149B48 (8 bytes)
class TreeTableAdScratch {
public:
    void SetRange(int p);
};

void TreeTableAdScratch::SetRange(int p) {
    *(short*)((char*)this + 0x8) = (short)p;
}
