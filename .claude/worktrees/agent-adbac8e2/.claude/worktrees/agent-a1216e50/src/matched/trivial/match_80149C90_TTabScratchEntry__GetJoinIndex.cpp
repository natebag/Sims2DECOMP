// 0x80149C90 (8 bytes)
class TTabScratchEntry {
public:
    short GetJoinIndex();
};

short TTabScratchEntry::GetJoinIndex() {
    return *(short*)((char*)this + 0x116);
}
