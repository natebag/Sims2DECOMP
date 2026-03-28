// 0x80119428 (64 bytes)
// cTrackCacheHandle::GetTrackObject(void)

class cTrackCacheHandle { public: void GetTrackObject(void); };

__attribute__((naked))
void cTrackCacheHandle::GetTrackObject(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80830000\n.long 0x2C040000\n.long 0x41820018\n.long 0x812DA1B8\n.long 0x38A00001\n.long 0x80690050\n.long 0x480007D5\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
