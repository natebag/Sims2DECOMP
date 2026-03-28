// 0x80149E80 (8 bytes)
class TTabScratchEntry {
public:
    void SetActionTreeID(int p);
};

void TTabScratchEntry::SetActionTreeID(int p) {
    *(short*)((char*)this + 0x6) = (short)p;
}
