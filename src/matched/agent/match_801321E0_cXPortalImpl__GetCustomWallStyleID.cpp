// 0x801321E0 (68 bytes)
// cXPortalImpl::GetCustomWallStyleID(void)

class cXPortalImpl { public: void GetCustomWallStyleID(void); };

__attribute__((naked))
void cXPortalImpl::GetCustomWallStyleID(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0x81690000\n.long 0x814B0004\n.long 0x812A0004\n.long 0xA8690310\n.long 0x80090314\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0xA86300A2\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
