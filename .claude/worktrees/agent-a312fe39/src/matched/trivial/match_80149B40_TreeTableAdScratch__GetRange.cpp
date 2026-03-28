// 0x80149B40 (8 bytes)
class TreeTableAdScratch {
public:
    short GetRange();
};

short TreeTableAdScratch::GetRange() {
    return *(short*)((char*)this + 0x8);
}
