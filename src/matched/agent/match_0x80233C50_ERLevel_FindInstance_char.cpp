typedef unsigned int uint32;

struct EInstance;

uint32 EChecksum_ComputeSymbol(char *, uint32);

struct ERLevel {
    EInstance *FindInstance(uint32 id);
    EInstance *FindInstance(char *name);
};

EInstance *ERLevel::FindInstance(char *name) {
    uint32 id = EChecksum_ComputeSymbol(name, 0);
    return FindInstance(id);
}
