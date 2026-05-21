// 0x80149E30 (72B) TTabScratchEntry::SetAd(int, ITreeTableAd &)
// Technique: uint_cast+i-first to flip add operand canonicalization

class ITreeTableAd;
class TTabScratchEntry {
public:
    void SetAd(int idx, ITreeTableAd& ad);
};

void TTabScratchEntry::SetAd(int idx, ITreeTableAd& ad) {
    int off = idx * 16;
    char* entry = (char*)((unsigned int)off + (unsigned int)(char*)this);
    char* vt = *(char**)(entry + 8);
    off += 8;
    char* iface_loc = (char*)this + off;
    short adj = *(short*)(vt + 32);
    void* fn = *(void**)(vt + 36);
    char* adj_this = iface_loc + adj;
    ((void (*)(void*, void*))fn)(adj_this, &ad);
}
