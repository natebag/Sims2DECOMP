// 0x80149B10 (8 bytes)
class TreeTableAdScratch {
public:
    short GetMin();
};

short TreeTableAdScratch::GetMin() {
    return *(short*)((char*)this + 0x6);
}
