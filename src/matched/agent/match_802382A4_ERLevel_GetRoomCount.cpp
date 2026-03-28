// 0x802382A4 (12 bytes) - ERLevel::GetRoomCount(void)
// addis r3, r3, 3; lwz r3, -23884(r3); blr  =>  return m_roomCount; (offset 0x2A2B4)

class ERLevel;

struct ERLevel_GRC {
    char pad[0x2A2B4];
    int m_roomCount;
    int GetRoomCount();
};
int ERLevel_GRC::GetRoomCount() {
    return m_roomCount;
}
