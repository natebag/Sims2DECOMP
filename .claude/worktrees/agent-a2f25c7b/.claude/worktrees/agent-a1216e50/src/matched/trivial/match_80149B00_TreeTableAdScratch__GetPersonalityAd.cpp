// 0x80149B00 (8 bytes)
class TreeTableAdScratch {
public:
    short GetPersonalityAd();
};

short TreeTableAdScratch::GetPersonalityAd() {
    return *(short*)((char*)this + 0x4);
}
