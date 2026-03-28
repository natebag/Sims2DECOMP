// 0x80149C98 (8 bytes)
class TTabScratchEntry {
public:
    void SetJoinIndex(int p);
};

void TTabScratchEntry::SetJoinIndex(int p) {
    *(short*)((char*)this + 0x116) = (short)p;
}
