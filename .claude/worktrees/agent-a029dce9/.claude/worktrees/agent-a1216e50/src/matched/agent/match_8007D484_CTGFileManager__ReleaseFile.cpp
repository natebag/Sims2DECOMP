// 0x8007D484 (64 bytes)
// CTGFileManager::ReleaseFile(CTGFile *)

class CTGFileManager { public: void ReleaseFile(CTGFile *); };

__attribute__((naked))
void CTGFileManager::ReleaseFile(CTGFile *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C8B2379\n.long 0x41820020\n.long 0x812B0000\n.long 0x38800003\n.long 0xA8690008\n.long 0x8009000C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
