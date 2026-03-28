// 0x800BB234 (68 bytes)
// cGZMusic::getPanSetting(void)

class cGZMusic { public: void getPanSetting(void); };

__attribute__((naked))
void cGZMusic::getPanSetting(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x81230018\n.long 0x3C004330\n.long 0x3D60803E\n.long 0x3929FE00\n.long 0xC80B9D68\n.long 0x6D298000\n.long 0x3D60803E\n.long 0x9121000C\n.long 0xC1AB9D70\n.long 0x90010008\n.long 0xC8210008\n.long 0xFC210028\n.long 0xFC200818\n.long 0xEC210372\n.long 0x38210010\n.long 0x4E800020");
}
