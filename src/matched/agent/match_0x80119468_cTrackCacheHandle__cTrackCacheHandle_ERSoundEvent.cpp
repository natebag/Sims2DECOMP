// 0x80119468 cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent (8 B)
struct cTrackCacheHandle { unsigned m_event; cTrackCacheHandle(unsigned); };
cTrackCacheHandle::cTrackCacheHandle(unsigned event) { m_event = event; }
