// 0x80149EC0 (8 bytes)
class TTabScratchEntry {
public:
    short GetAutonomyThreshold();
};

short TTabScratchEntry::GetAutonomyThreshold() {
    return *(short*)((char*)this + 0x114);
}
