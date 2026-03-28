// 0x80149E88 (8 bytes)
class TTabScratchEntry {
public:
    short GetCheckTreeID();
};

short TTabScratchEntry::GetCheckTreeID() {
    return *(short*)((char*)this + 0x4);
}
