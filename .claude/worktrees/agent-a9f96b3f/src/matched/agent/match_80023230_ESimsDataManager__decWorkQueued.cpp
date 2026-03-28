// 0x80023230 (124 bytes)
// ESimsDataManager::decWorkQueued(void)

class ESimsDataManager { public: void decWorkQueued(void); };

__attribute__((naked))
void ESimsDataManager::decWorkQueued(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0x93E10014\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x3880FFFF\n.long 0x93E10008\n.long 0x813F0000\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x813F0D2C\n.long 0x3929FFFF\n.long 0x913F0D2C\n.long 0x2C090000\n.long 0x40820008\n.long 0x913F0D20\n.long 0x80610008\n.long 0x81230000\n.long 0xA8090018\n.long 0x8129001C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0x83E10014\n.long 0x38210018\n.long 0x4E800020");
}
