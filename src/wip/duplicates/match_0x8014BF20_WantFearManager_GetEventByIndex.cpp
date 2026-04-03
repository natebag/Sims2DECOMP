/* WantFearManager::GetEventByIndex(int) const - 0x8014BF20 - 16 bytes */
/* mulli r4, r4, 0x24; lwz r3, 8(r3); add r3, r3, r4; blr */

class WantFearManager {
public:
    char _pad[0x8];
    char* m_events;

    void* GetEventByIndex(int index) const;
};

void* WantFearManager::GetEventByIndex(int index) const {
    return m_events + index * 0x24;
}
