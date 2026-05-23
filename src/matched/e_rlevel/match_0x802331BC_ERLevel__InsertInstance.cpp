/* 0x802331BC (24 bytes) - ERLevel::InsertInstance(EInstance*, EInstance*) */
struct EInstance;

struct ERLevel {
    void AddInstanceToLevel(EInstance *);
    void PrepareInstance(EInstance *);
    void InsertInstance(EInstance *inst, EInstance *after);
};

void ERLevel::InsertInstance(EInstance *inst, EInstance *after) {
    AddInstanceToLevel(inst);
    PrepareInstance(inst);
}
