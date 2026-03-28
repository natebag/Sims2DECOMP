// 0x801F6BA0 (84 bytes)
// INVTarget::GetOnLocMsgInvMotiveText(unsigned wchar_t *)

class INVTarget { public: void GetOnLocMsgInvMotiveText(unsigned wchar_t *); };

__attribute__((naked))
void INVTarget::GetOnLocMsgInvMotiveText(unsigned wchar_t *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x7C842379\n.long 0x41820030\n.long 0x38000000\n.long 0x394900D8\n.long 0xB0040000\n.long 0x396D8FE4\n.long 0x7C852378\n.long 0x80090084\n.long 0x5400103A\n.long 0x7D2B002E\n.long 0x5529103A\n.long 0x7C8A482E\n.long 0x4BFFED29\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
