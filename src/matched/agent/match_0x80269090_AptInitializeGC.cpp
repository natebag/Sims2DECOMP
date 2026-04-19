// 0x80269090 (32B) AptInitializeGC(void)
// Thunk to AptGC::Initialize(void)

extern void Initialize(void);

void AptInitializeGC(void) {
    Initialize();
}
