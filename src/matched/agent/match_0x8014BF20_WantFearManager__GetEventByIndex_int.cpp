// FLAGS: -fno-schedule-insns
// 0x8014BF20 WantFearManager::GetEventByIndex(int) (16B)
// mulli r4,r4,36; lwz r3,0x8(r3); add r3,r3,r4; blr
struct WantFearEvent {};
struct WantFearManager {
    char pad[8];
    WantFearEvent* m_events;  // offset 8
    WantFearEvent* GetEventByIndex(int idx) const;
};
WantFearEvent* WantFearManager::GetEventByIndex(int idx) const {
    return (WantFearEvent*)((char*)m_events + idx * 36);
}
