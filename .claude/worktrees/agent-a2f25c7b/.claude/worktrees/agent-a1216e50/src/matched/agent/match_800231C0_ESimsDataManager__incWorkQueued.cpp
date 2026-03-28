// 0x800231C0 (112 bytes)
// ESimsDataManager::incWorkQueued(void)

class ESimsDataManager { public: void incWorkQueued(void); };

__attribute__((naked))
void ESimsDataManager::incWorkQueued(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x3880FFFF\n.long 0x93C10008\n.long 0x813E0000\n.long 0x80090014\n.long 0xA8690010\n.long 0x7C0803A6\n.long 0x7C7E1A14\n.long 0x4E800021\n.long 0x813E0D2C\n.long 0x81410008\n.long 0x39290001\n.long 0x913E0D2C\n.long 0x816A0000\n.long 0xA86B0018\n.long 0x800B001C\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
