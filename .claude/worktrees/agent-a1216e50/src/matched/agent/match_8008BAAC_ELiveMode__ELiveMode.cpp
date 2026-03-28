// 0x8008BAAC (92 bytes)
// ELiveMode::ELiveMode(void)

class ELiveMode { public: void ELiveMode(void); };

__attribute__((naked))
void ELiveMode::ELiveMode(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x3D40803D\n.long 0x3D608046\n.long 0xC00A7D3C\n.long 0x7C691B78\n.long 0x38000000\n.long 0x39400001\n.long 0x396BD840\n.long 0x91490034\n.long 0x91690008\n.long 0x3D008047\n.long 0x9009000C\n.long 0x3960FFFF\n.long 0xD0090010\n.long 0x91490000\n.long 0x90090044\n.long 0x90090030\n.long 0x91285C48\n.long 0x91690054\n.long 0x90010008\n.long 0x91410010\n.long 0x38210018\n.long 0x4E800020");
}
