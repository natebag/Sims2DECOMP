// 0x803C5198 (92 bytes)
// TArray<SimsLightInfo, TArrayERModelAllocator>::Copy(SimsLightInfo *, SimsLightInfo *, int)

class TArray<SimsLightInfo, TArrayERModelAllocator> { public: void Copy(SimsLightInfo *, SimsLightInfo *, int); };

__attribute__((naked))
void TArray<SimsLightInfo, TArrayERModelAllocator>::Copy(SimsLightInfo *, SimsLightInfo *, int) {
    asm volatile(".long 0x3905FFFF\n.long 0x2C050000\n.long 0x4D820020\n.long 0x81640004\n.long 0x2C080000\n.long 0x80040008\n.long 0x3908FFFF\n.long 0x8124000C\n.long 0x81440000\n.long 0x91630004\n.long 0x91430000\n.long 0x90030008\n.long 0x9123000C\n.long 0x80040010\n.long 0x81240014\n.long 0x81640018\n.long 0x90030010\n.long 0x3884001C\n.long 0x91230014\n.long 0x91630018\n.long 0x3863001C\n.long 0x4082FFB8\n.long 0x4E800020");
}
