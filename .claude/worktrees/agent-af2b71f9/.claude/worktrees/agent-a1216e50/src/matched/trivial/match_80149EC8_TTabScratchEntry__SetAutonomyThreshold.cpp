// 0x80149EC8 (8 bytes)
class TTabScratchEntry {
public:
    void SetAutonomyThreshold(int p);
};

void TTabScratchEntry::SetAutonomyThreshold(int p) {
    *(short*)((char*)this + 0x114) = (short)p;
}
