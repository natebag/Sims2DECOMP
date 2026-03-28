// 0x8014BCB8 (76 bytes)
// WantFearManager::~WantFearManager(void)

class WantFearManager { public: void ~WantFearManager(void); };

__attribute__((naked))
void WantFearManager::~WantFearManager(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x807F0000\n.long 0x2C030000\n.long 0x41820008\n.long 0x481C6295\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x48185535\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
