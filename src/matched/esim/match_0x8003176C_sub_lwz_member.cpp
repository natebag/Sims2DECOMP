// ESim::flushQueuedCostumeModels(void) @ 0x8003176C (36B)

extern void target_8003176C(void*);

struct ESim {
    char pad[1596];
    void *field;

    void flushQueuedCostumeModels();
};

void ESim::flushQueuedCostumeModels() {
    target_8003176C(field);
}
