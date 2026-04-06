// FLAGS: -msdata=eabi -G 8
// 0x802382F8 ERLevel::RefreshRoomAssignment (60b)
extern void RemoveInstanceFromRoom(void*, void*);
extern void AddInstanceToRoom(void*, void*);

void RefreshRoomAssignment(void* self, void* instance) {
    RemoveInstanceFromRoom(self, instance);
    AddInstanceToRoom(self, instance);
}
