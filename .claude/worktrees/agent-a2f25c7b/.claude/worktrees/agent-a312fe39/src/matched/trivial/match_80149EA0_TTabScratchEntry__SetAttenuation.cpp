// 0x80149EA0 (8 bytes)
class TTabScratchEntry {
public:
    void SetAttenuation(int p);
};

void TTabScratchEntry::SetAttenuation(int p) {
    *(int*)((char*)this + 0x108) = p;
}
