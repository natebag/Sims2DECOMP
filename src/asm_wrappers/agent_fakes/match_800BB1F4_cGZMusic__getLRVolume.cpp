// 0x800BB1F4 (64 bytes)
// cGZMusic::getLRVolume(void)

class cGZMusic { public: void getLRVolume(void); };

__attribute__((naked))
void cGZMusic::getLRVolume(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x80030014\n.long 0x3D404330\n.long 0x3D20803E\n.long 0x6C008000\n.long 0xC8099D58\n.long 0x9001000C\n.long 0x3D20803E\n.long 0xC1A99D60\n.long 0x91410008\n.long 0xC8210008\n.long 0xFC210028\n.long 0xFC200818\n.long 0xEC210372\n.long 0x38210010\n.long 0x4E800020");
}
