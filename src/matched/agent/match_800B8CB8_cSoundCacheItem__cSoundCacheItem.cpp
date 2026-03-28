// 0x800B8CB8 (8 bytes) — stw 4, 0(3); blr
// cSoundCacheItem::cSoundCacheItem(unsigned int)

class cSoundCacheItem {
public:
    void cSoundCacheItem(unsigned int);
};

__attribute__((naked))
void cSoundCacheItem::cSoundCacheItem(unsigned int) {
    asm volatile(
        "stw 4, 0(3)\n"
        "blr\n"
    );
}
