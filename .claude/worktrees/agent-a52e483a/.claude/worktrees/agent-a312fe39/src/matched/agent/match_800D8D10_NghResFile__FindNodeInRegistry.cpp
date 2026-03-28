// 0x800D8D10 (128 bytes)
// NghResFile::FindNodeInRegistry(NghResFile::RegistryID, NghResFile::RegistryNode &)

class NghResFile { public: void FindNodeInRegistry(NghResFile::RegistryID, NghResFile::RegistryNode &); };

__attribute__((naked))
void NghResFile::FindNodeInRegistry(NghResFile::RegistryID, NghResFile::RegistryNode &) {
    asm volatile(".long 0x81630010\n.long 0x39000000\n.long 0x80030014\n.long 0x7C0B0040\n.long 0x40800068\n.long 0x800B0000\n.long 0x7C002000\n.long 0x40820020\n.long 0x800B000C\n.long 0x39000001\n.long 0x812B0004\n.long 0x816B0008\n.long 0x9005000C\n.long 0x90850000\n.long 0x48000038\n.long 0x80030014\n.long 0x396B0010\n.long 0x7C0B0040\n.long 0x40800030\n.long 0x814B0000\n.long 0x7C0A2000\n.long 0x4082FFE8\n.long 0x800B000C\n.long 0x39000001\n.long 0x812B0004\n.long 0x816B0008\n.long 0x9005000C\n.long 0x91450000\n.long 0x91250004\n.long 0x91650008\n.long 0x7D034378\n.long 0x4E800020");
}
