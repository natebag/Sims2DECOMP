// 0x8012D038 (112 bytes)
// PlayerFamilyImpl::ClearFamily(void)

class PlayerFamilyImpl { public: void ClearFamily(void); };

__attribute__((naked))
void PlayerFamilyImpl::ClearFamily(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x4BF894E5\n.long 0x387E0CDC\n.long 0x4BF8B4BD\n.long 0x813E0000\n.long 0x80090144\n.long 0xA8690140\n.long 0x7C0803A6\n.long 0x7C7E1A14\n.long 0x4E800021\n.long 0x4BF1D6B1\n.long 0x387E00C8\n.long 0x48032001\n.long 0x387E0CA8\n.long 0x38800000\n.long 0x38A00032\n.long 0x4811655D\n.long 0x38000000\n.long 0x901E0D60\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
