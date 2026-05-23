// FLAGS: -msdata=eabi -G 8
/* 0x802382F8 (60 bytes) - ERLevel::RefreshRoomAssignment(EInstance*) */
extern void RemoveInstanceFromRoom(void*, void*);
extern void AddInstanceToRoom(void*, void*);

struct EInstance;

struct ERLevel {
    void RefreshRoomAssignment(EInstance* instance);
};

void ERLevel::RefreshRoomAssignment(EInstance* instance) {
    RemoveInstanceFromRoom(this, instance);
    AddInstanceToRoom(this, instance);
}
