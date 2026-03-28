// 0x80149E78 (8 bytes)
class TTabScratchEntry {
public:
    short GetActionTreeID();
};

short TTabScratchEntry::GetActionTreeID() {
    return *(short*)((char*)this + 0x6);
}
