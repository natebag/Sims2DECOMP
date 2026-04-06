// FLAGS: -msdata=eabi -G 8
// 0x802382B0 ERLevel::UpdateRooms (48b)
extern void SetRoomCount(void*, int);

struct ERLevel {
    char pad[0x2A2B4];
    int roomCount;
};

void UpdateRooms(ERLevel* self, int count) {
    if (count != self->roomCount) {
        SetRoomCount(self, count);
    }
}
