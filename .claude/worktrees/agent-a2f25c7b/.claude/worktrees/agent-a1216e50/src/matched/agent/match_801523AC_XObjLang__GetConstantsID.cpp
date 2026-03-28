// 0x801523AC (116 bytes)
// XObjLang::GetConstantsID(short, short *, int *)

class XObjLang { public: void GetConstantsID(short, short *, int *); };

__attribute__((naked))
void XObjLang::GetConstantsID(short, short *, int *) {
    asm volatile(".long 0x54609F7E\n.long 0x2C000001\n.long 0x4182002C\n.long 0x41810010\n.long 0x2C000000\n.long 0x41820014\n.long 0x48000034\n.long 0x2C000002\n.long 0x41820020\n.long 0x48000028\n.long 0x38001000\n.long 0xB0040000\n.long 0x48000024\n.long 0x38002000\n.long 0xB0040000\n.long 0x48000018\n.long 0x38000100\n.long 0xB0040000\n.long 0x4800000C\n.long 0x38600000\n.long 0x4E800020\n.long 0xA0040000\n.long 0x5469CEBE\n.long 0x546B067E\n.long 0x7C004A14\n.long 0x38600001\n.long 0xB0040000\n.long 0x91650000\n.long 0x4E800020");
}
