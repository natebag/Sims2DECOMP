// 0x8014941C (124 bytes)
// TTabScratchEntry::TTabScratchEntry(void)

class TTabScratchEntry { public: void TTabScratchEntry(void); };

__attribute__((naked))
void TTabScratchEntry::TTabScratchEntry(void) {
    asm volatile(".long 0x3D208046\n.long 0x38E00010\n.long 0x7C681B78\n.long 0x392950F8\n.long 0x7CE903A6\n.long 0x3D608046\n.long 0x91280000\n.long 0x396B52F0\n.long 0x39280008\n.long 0x38000000\n.long 0x39400000\n.long 0x91690000\n.long 0xB0090004\n.long 0xB0090006\n.long 0xB0090008\n.long 0x9149000C\n.long 0x39290010\n.long 0x4200FFE8\n.long 0x38000000\n.long 0x39200032\n.long 0x3960FFFF\n.long 0x39400003\n.long 0xB0080006\n.long 0x7D034378\n.long 0xB1280114\n.long 0xB1680116\n.long 0x91480108\n.long 0x90080118\n.long 0xB0080110\n.long 0xB0080004\n.long 0x4E800020");
}
