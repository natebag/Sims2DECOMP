// 0x80233454 ERLevel::AddInstanceToLevel(EInstance *) (232 B)

struct ENodeList { unsigned AddTail(unsigned item); };
struct ERedBlackTree { unsigned Insert(unsigned key, unsigned value, bool replace); };
struct EInstanceVtable { char pad[0xb0]; short keyOff; unsigned (*key)(void*); };
struct EInstance {
    EInstanceVtable* vtable;
    void* level;
    char pad8[8];
    int wallData;
    char pad14[0x20];
    unsigned treeNode;
    char pad38[0x24];
    unsigned flags;
    char pad60[0x18];
    unsigned listNode;
};
struct ERLevel {
    void ValidateInstanceInLevel(EInstance* inst);
    void AddInstanceToRoom(EInstance* inst);
    void AddWallInstanceToLevel(EInstance* inst);
    void AddInstanceToLevel(EInstance* inst);
};

void ERLevel::AddInstanceToLevel(EInstance* inst) {
    ValidateInstanceInLevel(inst);
    inst->level = this;
    AddInstanceToRoom(inst);
    unsigned flags = inst->flags;
    if (flags & 0x40000) {
        ENodeList* list = (ENodeList*)((char*)this + 0x2A2A4);
        inst->listNode = list->AddTail((unsigned)inst);
    } else {
        if (!(flags & 0x10000)) {
            if (inst->wallData != 0) {
                AddWallInstanceToLevel(inst);
            } else {
                int* count = (int*)((char*)this + 0x2C2B8);
                EInstance** arr = (EInstance**)((char*)this + 0x2A2B8);
                arr[*count] = inst;
                (*count)++;
            }
        }
    }
    flags = inst->flags;
    if (flags & 0x100) {
        EInstanceVtable* vt = inst->vtable;
        unsigned key = vt->key((char*)inst + vt->keyOff);
        ERedBlackTree* tree = (ERedBlackTree*)((char*)this + 0x2A274);
        inst->treeNode = tree->Insert(key, (unsigned)inst, true);
    }
}
