extern "C" int getTimerValue(void);
struct cSoundCacheItem { char pad[8]; int m_timer; };
void cSoundCacheItem_ResetUsageTimer(cSoundCacheItem* self) {
    self->m_timer = getTimerValue();
}
