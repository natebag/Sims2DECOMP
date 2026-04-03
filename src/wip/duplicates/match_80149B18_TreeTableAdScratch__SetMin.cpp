// 0x80149B18 (8 bytes)
class TreeTableAdScratch {
public:
    void SetMin(int p);
};

void TreeTableAdScratch::SetMin(int p) {
    *(short*)((char*)this + 0x6) = (short)p;
}
