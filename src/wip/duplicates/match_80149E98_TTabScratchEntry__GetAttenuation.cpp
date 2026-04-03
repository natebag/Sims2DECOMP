// 0x80149E98 (8 bytes)
class TTabScratchEntry {
public:
    int GetAttenuation();
};

int TTabScratchEntry::GetAttenuation() {
    return *(int*)((char*)this + 0x108);
}
