// 0x80119D6C (56B) cSoundCache::IsInMemory(ERSoundEvent*) const
// Linear scan of 64-entry pointer array; matches when entry->m_evt == evt.

struct ERSoundEvent;
struct cSoundCacheEntry { ERSoundEvent* m_evt; };

class cSoundCache {
public:
    cSoundCacheEntry* m_entries[64];
    bool IsInMemory(ERSoundEvent* evt) const;
};

bool cSoundCache::IsInMemory(ERSoundEvent* evt) const
{
    const cSoundCacheEntry* const* p = m_entries;
    for (int i = 0; i < 64; i++) {
        const cSoundCacheEntry* e = *p++;
        if (e && e->m_evt == evt) return true;
    }
    return false;
}
