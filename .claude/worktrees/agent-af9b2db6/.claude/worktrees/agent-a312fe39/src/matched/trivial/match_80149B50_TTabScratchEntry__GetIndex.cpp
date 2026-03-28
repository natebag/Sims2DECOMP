// 0x80149B50 (8 bytes)
class TTabScratchEntry {
public:
    short GetIndex();
};

short TTabScratchEntry::GetIndex() {
    return *(short*)((char*)this + 0x112);
}
