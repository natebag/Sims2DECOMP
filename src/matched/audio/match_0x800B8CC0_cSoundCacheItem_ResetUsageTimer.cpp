// 0x800B8CC0 cSoundCacheItem::ResetUsageTimer (48b)
extern int getTimerValue(void);

struct cSoundCacheItem {
    char pad[8];
    int m_usageTimer;
    void ResetUsageTimer();
};

void cSoundCacheItem::ResetUsageTimer() {
    m_usageTimer = getTimerValue();
}
