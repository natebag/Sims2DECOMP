// 0x80149E90 (8 bytes)
class TTabScratchEntry {
public:
    void SetCheckTreeID(int p);
};

void TTabScratchEntry::SetCheckTreeID(int p) {
    *(short*)((char*)this + 0x4) = (short)p;
}
