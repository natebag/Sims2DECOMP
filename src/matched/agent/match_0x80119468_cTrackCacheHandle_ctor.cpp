/* cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent*) - 0x80119468 - 8 bytes */
/* stw r4, 0(r3); blr */

struct ERSoundEvent;

class cTrackCacheHandle {
public:
    ERSoundEvent* m_event;

    cTrackCacheHandle(ERSoundEvent* event);
};

cTrackCacheHandle::cTrackCacheHandle(ERSoundEvent* event) {
    m_event = event;
}
