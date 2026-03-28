// 0x801B2EC0 (104 bytes)
// FAMTarget::GetSelectedLotDescription(unsigned wchar_t *)

class FAMTarget { public: void GetSelectedLotDescription(unsigned wchar_t *); };

__attribute__((naked))
void FAMTarget::GetSelectedLotDescription(unsigned wchar_t *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0x93E10014\n.long 0x9001001C\n.long 0x7C9F2378\n.long 0x8083014C\n.long 0x4BFFFB19\n.long 0x4BE707ED\n.long 0x7C651B78\n.long 0x3C808047\n.long 0x38845DCC\n.long 0x38610008\n.long 0x4CC63182\n.long 0x4BE8CC89\n.long 0x81210008\n.long 0x38800000\n.long 0x2C090000\n.long 0x41820008\n.long 0x80890000\n.long 0x7FE3FB78\n.long 0x4BEF4FC1\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0x83E10014\n.long 0x38210018\n.long 0x4E800020");
}
