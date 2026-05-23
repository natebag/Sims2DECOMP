// FLAGS: -msdata=eabi -G 8
/* 0x802382B0 (48 bytes) - ERLevel::UpdateRooms(int) */
extern void SetRoomCount(void*, int);

struct ERLevel {
    char pad[0x2A2B4];
    int m_roomCount;
    void UpdateRooms(int count);
};

void ERLevel::UpdateRooms(int count) {
    if (count != m_roomCount) {
        SetRoomCount(this, count);
    }
}
