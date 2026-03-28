// 0x80344598 (88 bytes)
// ENgcRenderer::EnableGeometryModes(EDLEntry *)

class ENgcRenderer { public: void EnableGeometryModes(EDLEntry *); };

__attribute__((naked))
void ENgcRenderer::EnableGeometryModes(EDLEntry *) {
    asm volatile(".long 0x812304D8\n.long 0x81440004\n.long 0x800906CC\n.long 0x64008000\n.long 0x900906CC\n.long 0x816304D8\n.long 0x800B06E8\n.long 0x7C005378\n.long 0x900B06E8\n.long 0x812304D8\n.long 0x800906E8\n.long 0x700B0004\n.long 0x4182000C\n.long 0x38000001\n.long 0x48000010\n.long 0x70000002\n.long 0x41820008\n.long 0x38000002\n.long 0x9009079C\n.long 0x38000001\n.long 0x90030510\n.long 0x4E800020");
}
