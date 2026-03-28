// 0x80166088 (72 bytes)
// CasScene::SetSceneLighting(int, bool)

class CasScene { public: void SetSceneLighting(int, bool); };

__attribute__((naked))
void CasScene::SetSceneLighting(int, bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CBE2B78\n.long 0x4BFFFE65\n.long 0x2C1E0000\n.long 0x41820014\n.long 0x3C608048\n.long 0x389F0008\n.long 0x38637870\n.long 0x4800F249\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
