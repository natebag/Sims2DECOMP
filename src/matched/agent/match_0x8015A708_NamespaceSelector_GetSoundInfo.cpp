/* NamespaceSelector::GetSoundInfo(short) - 0x8015A708 - 48 bytes */

struct QuickDataSoundInfo;

void SomeLookup(void*, int);

struct NamespaceSelector {
    QuickDataSoundInfo* GetSoundInfo(short idx);
};

QuickDataSoundInfo* NamespaceSelector::GetSoundInfo(short idx) {
    SomeLookup(this, idx + 8);
    return (QuickDataSoundInfo*)this;
}
