// 0x80118A90 (124 bytes)
// cTrack::NoteOn(void)

class cTrack { public: void NoteOn(void); };

__attribute__((naked))
void cTrack::NoteOn(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0050\n.long 0x2C030000\n.long 0x40820014\n.long 0x3C80803E\n.long 0x7FE3FB78\n.long 0x3884C6B8\n.long 0x48000034\n.long 0x801F000C\n.long 0x2C000000\n.long 0x4182001C\n.long 0x480007B9\n.long 0x7C7E1B78\n.long 0x7FE3FB78\n.long 0x480002FD\n.long 0x7FC3F378\n.long 0x48000018\n.long 0x3C80803E\n.long 0x7FE3FB78\n.long 0x3884C6E0\n.long 0x4BFFD971\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
