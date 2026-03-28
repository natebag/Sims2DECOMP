// 0x803C3988 (124 bytes)
// TArray<ESMSStrip, TArrayERModelAllocator>::Copy(ESMSStrip *, ESMSStrip *, int)

class TArray<ESMSStrip, TArrayERModelAllocator> { public: void Copy(ESMSStrip *, ESMSStrip *, int); };

__attribute__((naked))
void TArray<ESMSStrip, TArrayERModelAllocator>::Copy(ESMSStrip *, ESMSStrip *, int) {
    asm volatile(".long 0x3965FFFF\n.long 0x2C050000\n.long 0x4D820020\n.long 0x7C691B78\n.long 0x38ABFFFF\n.long 0x39440034\n.long 0x38690034\n.long 0x39600030\n.long 0x80040000\n.long 0x356BFFE8\n.long 0x90090000\n.long 0x80040004\n.long 0x90090004\n.long 0x80040008\n.long 0x90090008\n.long 0x8004000C\n.long 0x9009000C\n.long 0x80040010\n.long 0x90090010\n.long 0x80040014\n.long 0x38840018\n.long 0x90090014\n.long 0x39290018\n.long 0x4082FFC4\n.long 0x80040000\n.long 0x7CAB2B78\n.long 0x7D445378\n.long 0x2C0BFFFF\n.long 0x90090000\n.long 0x4082FF98\n.long 0x4E800020");
}
