// 0x80144FA4 (112 bytes)
// IFFSlotDescList::QueryInterface(unsigned int, void **)

class IFFSlotDescList { public: void QueryInterface(unsigned int, void **); };

__attribute__((naked))
void IFFSlotDescList::QueryInterface(unsigned int, void **) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CBE2B79\n.long 0x41820040\n.long 0x2C040001\n.long 0x41820014\n.long 0x3C002C03\n.long 0x60000753\n.long 0x7C040000\n.long 0x40820028\n.long 0x813F0000\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x93FE0000\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
