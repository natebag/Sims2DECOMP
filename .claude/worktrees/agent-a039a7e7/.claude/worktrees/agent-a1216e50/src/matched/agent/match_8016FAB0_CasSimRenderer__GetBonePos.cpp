// 0x8016FAB0 (80 bytes)
// CasSimRenderer::GetBonePos(unsigned int, EVec3 &)

class CasSimRenderer { public: void GetBonePos(unsigned int, EVec3 &); };

__attribute__((naked))
void CasSimRenderer::GetBonePos(unsigned int, EVec3 &) {
    asm volatile(".long 0x9421FFB0\n.long 0x7C0802A6\n.long 0xBFC10048\n.long 0x90010054\n.long 0x7CBE2B78\n.long 0x38630174\n.long 0x38A10008\n.long 0x48180D91\n.long 0x39210038\n.long 0x81410038\n.long 0x80090008\n.long 0x81690004\n.long 0x901E0008\n.long 0x915E0000\n.long 0x917E0004\n.long 0x80010054\n.long 0x7C0803A6\n.long 0xBBC10048\n.long 0x38210050\n.long 0x4E800020");
}
