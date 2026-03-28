// 0x800AC9E8 (80 bytes)
// ResourceBehavior::CountTrees(short)

class ResourceBehavior { public: void CountTrees(short); };

__attribute__((naked))
void ResourceBehavior::CountTrees(short) {
    asm volatile(".long 0x2C040002\n.long 0x39200000\n.long 0x41820028\n.long 0x41810010\n.long 0x2C040001\n.long 0x41820014\n.long 0x48000024\n.long 0x2C040003\n.long 0x41820018\n.long 0x48000018\n.long 0x81230018\n.long 0x48000010\n.long 0x81230010\n.long 0x48000008\n.long 0x81230014\n.long 0x2C090000\n.long 0x38600000\n.long 0x4D820020\n.long 0x80690018\n.long 0x4E800020");
}
