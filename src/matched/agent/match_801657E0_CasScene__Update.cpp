// 0x801657E0 (68 bytes)
// CasScene::Update(float)

class CasScene { public: void Update(float); };

__attribute__((naked))
void CasScene::Update(float) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x48000DB5\n.long 0x807E0AC0\n.long 0x4BF429DD\n.long 0x807E0A80\n.long 0x2C030000\n.long 0x41820008\n.long 0x480CEB95\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
