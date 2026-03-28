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
