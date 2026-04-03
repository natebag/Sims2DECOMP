// 0x80149B08 (8 bytes)
class TreeTableAdScratch {
public:
    void SetPersonalityAd(int p);
};

void TreeTableAdScratch::SetPersonalityAd(int p) {
    *(short*)((char*)this + 0x4) = (short)p;
}
