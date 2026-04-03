// 0x80119468 (8 bytes)
// cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent *)
// stw r4, 0(r3); blr
class ERSoundEvent;
class cTrackCacheHandle {
public:
    ERSoundEvent* m_event;
    cTrackCacheHandle(ERSoundEvent* event);
};

cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent* event) {
    m_event = event;
}
