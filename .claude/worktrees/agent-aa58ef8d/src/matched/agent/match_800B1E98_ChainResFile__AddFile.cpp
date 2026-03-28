// 0x800B1E98 (64 bytes)
// ChainResFile::AddFile(iResFile *)

class ChainResFile { public: void AddFile(iResFile *); };

__attribute__((naked))
void ChainResFile::AddFile(iResFile *) {
    asm volatile(".long 0x38630014\n.long 0x39200000\n.long 0x39600001\n.long 0x8003FFFC\n.long 0x2C000000\n.long 0x40820018\n.long 0x80030000\n.long 0x9083FFFC\n.long 0x90030004\n.long 0x91630010\n.long 0x4E800020\n.long 0x39290001\n.long 0x38630018\n.long 0x2C090007\n.long 0x4081FFD4\n.long 0x4E800020");
}
