// cSimulator::CreateInstance(void)
// Address: 0x801401E4 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* cSimulator_Alloc(int);
void* cSimulator_Init(void*);

void* cSimulator__CreateInstance(void) {
    void* p = cSimulator_Alloc(384);
    return cSimulator_Init(p);
}
