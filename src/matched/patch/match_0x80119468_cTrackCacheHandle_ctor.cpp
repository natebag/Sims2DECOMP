// 0x80119468 cTrackCacheHandle::cTrackCacheHandle (8b)

class ERSoundEvent;

struct cTrackCacheHandle {
    ERSoundEvent* field_0;
    cTrackCacheHandle(ERSoundEvent*);
};

cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent* p2) {
    field_0 = p2;
}
