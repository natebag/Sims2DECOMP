// 0x80344648 (80 bytes)
// ENgcRenderer::SetGeometryModes(EDLEntry *)

class ENgcRenderer { public: void SetGeometryModes(EDLEntry *); };

__attribute__((naked))
void ENgcRenderer::SetGeometryModes(EDLEntry *) {
    asm volatile(".long 0x816304D8\n.long 0x81440004\n.long 0x800B06CC\n.long 0x64008000\n.long 0x900B06CC\n.long 0x812304D8\n.long 0x914906E8\n.long 0x812304D8\n.long 0x800906E8\n.long 0x700B0004\n.long 0x4182000C\n.long 0x38000002\n.long 0x48000010\n.long 0x70000002\n.long 0x41820008\n.long 0x38000001\n.long 0x9009079C\n.long 0x38000001\n.long 0x90030510\n.long 0x4E800020");
}
