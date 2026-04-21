// 0x80323610 (28B) EControllerManager::GetPlayerControllerIndex(unsigned int)
// Bounds-check + array index: if (player <= 3) return m_active[player]; else return -1.
// `cmplwi` (unsigned compare) + `bgt` skip-over keeps r0=-1.

class EControllerManager {
public:
    int m_active[4];  // offset 0..16 — read directly via lwzx r0,r3,r0
    int GetPlayerControllerIndex(unsigned int player);
};

int EControllerManager::GetPlayerControllerIndex(unsigned int player) {
    int r = -1;
    if (player <= 3) {
        r = m_active[player];
    }
    return r;
}
