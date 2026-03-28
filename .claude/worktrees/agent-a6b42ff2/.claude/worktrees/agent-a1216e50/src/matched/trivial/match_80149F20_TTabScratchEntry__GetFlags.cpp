// 0x80149F20 (8 bytes)
class TTabScratchEntry {
public:
    short GetFlags();
};

short TTabScratchEntry::GetFlags() {
    return *(short*)((char*)this + 0x110);
}
