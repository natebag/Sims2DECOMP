// 0x8014BC6C (76 bytes)
// WantFearManager::WantFearManager(void)

class WantFearManager { public: void WantFearManager(void); };

__attribute__((naked))
void WantFearManager::WantFearManager(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000000\n.long 0x901E0018\n.long 0x901E0000\n.long 0x901E0004\n.long 0x901E0008\n.long 0x901E000C\n.long 0x901E0010\n.long 0x4800006D\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
