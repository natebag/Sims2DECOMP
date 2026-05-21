// 0x80119D48 cSoundCache::IsInMemory(cTrack*) const (36B)
// Dereferences cTrack->m_event, calls IsInMemory(ERSoundEvent*)

struct ERSoundEvent_IIM2;

struct cTrack_IIM2 {
    ERSoundEvent_IIM2* m_event;
};

struct cSoundCacheIIM2 {
    char m_entries[256];
    bool IsInMemory(ERSoundEvent_IIM2* evt) const;
    bool IsInMemory(cTrack_IIM2* track) const;
};

bool cSoundCacheIIM2::IsInMemory(cTrack_IIM2* track) const {
    return IsInMemory(track->m_event);
}
