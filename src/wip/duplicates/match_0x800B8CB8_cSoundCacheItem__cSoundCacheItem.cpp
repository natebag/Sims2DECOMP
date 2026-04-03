/* cSoundCacheItem::cSoundCacheItem(unsigned int) at 0x800B8CB8 (8B) */

struct cSoundCacheItem {
    unsigned int m_id;

    cSoundCacheItem(unsigned int id);
};

cSoundCacheItem::cSoundCacheItem(unsigned int id) {
    m_id = id;
}
