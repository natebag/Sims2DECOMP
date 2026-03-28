// 0x80118DD4 (84 bytes)
// cTrack::UpdateVolPan(void)

class cTrack { public: void UpdateVolPan(void); };

__attribute__((naked))
void cTrack::UpdateVolPan(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x83DF0050\n.long 0x2C1E0000\n.long 0x41820020\n.long 0x4BFFFE81\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x48000311\n.long 0x809F0078\n.long 0x807F0050\n.long 0x4800040D\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
