// 0x80233824 ERLevel::AddInstanceToRoom(EInstance *) (164 B)

struct ENodeList { unsigned AddTail(unsigned item); };
struct EInstanceVtable { char pad[0xb8]; short off; void (*fn)(void*); };
struct EInstance {
    EInstanceVtable* vtable;
    char pad0[0x50];
    int roomIndex;
    char pad1[4];
    unsigned flags;
    char pad2[0x18];
    unsigned listNode;
};
struct ERLevel {
    int GetRoomIndex(EInstance* inst) const;
    void AddInstanceToRoom(EInstance* inst);
};

void ERLevel::AddInstanceToRoom(EInstance* inst) {
    int room = GetRoomIndex(inst);
    unsigned flags = inst->flags;
    inst->roomIndex = room;
    if (flags & 0x10000) {
        EInstance*** specialRoomsPtr = (EInstance***)((char*)this + 0x2A284);
        (*specialRoomsPtr)[room] = inst;
        inst->listNode = 0;
    } else {
        if (flags & 0x20000) {
            int base = *(int*)((char*)this + 0x2A280);
            ENodeList* list = (ENodeList*)(room * 12 + base);
            inst->listNode = list->AddTail((unsigned)inst);
        }
        flags = inst->flags;
        if (flags & 0x8000) {
            EInstanceVtable* vt = inst->vtable;
            void* self = (char*)inst + vt->off;
            vt->fn(self);
        }
    }
}
