// 0x800F6DDC (116 bytes)
// ObjectModuleImpl::ForceAllLocations(void)

class ObjectModuleImpl { public: void ForceAllLocations(void); };

__attribute__((naked))
void ObjectModuleImpl::ForceAllLocations(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x81230000\n.long 0xA8090098\n.long 0x8129009C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x48000030\n.long 0x813F0004\n.long 0x800901C4\n.long 0xA86901C0\n.long 0x7C0803A6\n.long 0x7C7F1A14\n.long 0x4E800021\n.long 0x813F0004\n.long 0xA8690490\n.long 0x80090494\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C7F1B79\n.long 0x4082FFCC\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
