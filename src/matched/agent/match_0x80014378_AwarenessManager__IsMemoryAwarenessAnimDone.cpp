// 0x80014378 (104B) AwarenessManager::IsMemoryAwarenessAnimDone(void)

class EAnimController {
public:
    int IsTrackAnimComplete(int flags);
};

struct AwarenessManager {
    unsigned int m_flags;     // 0x00
    char pad_4[4];            // 0x04
    EAnimController* m_inner; // 0x08
    char pad_c[12];           // 0x0C-0x17
    int m_state;              // 0x18 = 24
    int IsMemoryAwarenessAnimDone();
};

int AwarenessManager::IsMemoryAwarenessAnimDone() {
    int state = m_state;
    int track = 1024;
    int result = 0;
    if (state == 3) track = 128;
    if (state <= 1) goto done;
    if (m_flags & 16) goto done;
    if (m_inner->IsTrackAnimComplete(track))
        result = 1;
done:
    return result;
}
