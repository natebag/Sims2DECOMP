/* WantFearManager::GetEventByIndex - 0x8014BF20 (16 bytes) */

struct WantFearEvent;

class WantFearManager {
public:
    char pad[0x08];
    char *m_events;
    WantFearEvent *GetEventByIndex(int index) const;
};

WantFearEvent *WantFearManager::GetEventByIndex(int index) const {
    return (WantFearEvent *)(m_events + index * 36);
}
