// 0x80233964 ERLevel::GetRoomIndex(EInstance *) const (120 B)

struct EInstance {
    char pad0[0x1c];
    void (*getRoom)(void*, int, short*, short*);
    char pad1[0x8];
    void* obj;
};
struct ERLevel {
    char pad0[0x2A2B4];
    int maxRoomIndex;
    int GetRoomIndex(EInstance* inst) const;
};

int ERLevel::GetRoomIndex(EInstance* inst) const {
    short a;
    short b;
    void (*fn)(void*, int, short*, short*) = inst->getRoom;
    short* pa = &a;
    short* pb = &b;
    if (fn != 0) {
        void* obj = inst->obj;
        fn(obj, 0, pa, pb);
    } else {
        b = 0;
        a = 0;
    }
    int room = b;
    if (room < 0 || room >= maxRoomIndex) {
        room = maxRoomIndex;
    }
    return room;
}
