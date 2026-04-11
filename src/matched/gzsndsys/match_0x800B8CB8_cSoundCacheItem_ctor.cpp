// 0x800B8CB8 cSoundCacheItem::cSoundCacheItem (8b)

struct cSoundCacheItem {
    unsigned int field_0;
    cSoundCacheItem(unsigned int);
};

cSoundCacheItem::cSoundCacheItem(unsigned int p2) {
    field_0 = p2;
}
