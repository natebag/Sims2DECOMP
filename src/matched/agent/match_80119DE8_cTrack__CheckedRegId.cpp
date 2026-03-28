// 0x80119DE8 (64 bytes)
// cTrack::CheckedRegId(int)

class cTrack { public: void CheckedRegId(int); };

__attribute__((naked))
void cTrack::CheckedRegId(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C601B78\n.long 0x2C040012\n.long 0x7C832378\n.long 0x40810018\n.long 0x3C80803E\n.long 0x7C030378\n.long 0x3884C45C\n.long 0x4BFFC651\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
