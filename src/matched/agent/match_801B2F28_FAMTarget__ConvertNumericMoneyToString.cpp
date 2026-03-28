// 0x801B2F28 (100 bytes)
// FAMTarget::ConvertNumericMoneyToString(int, unsigned wchar_t *)

class FAMTarget { public: void ConvertNumericMoneyToString(int, unsigned wchar_t *); };

__attribute__((naked))
void FAMTarget::ConvertNumericMoneyToString(int, unsigned wchar_t *) {
    asm volatile(".long 0x9421FDE0\n.long 0x7C0802A6\n.long 0xBF810210\n.long 0x90010224\n.long 0x3BC10008\n.long 0x7C9D2378\n.long 0x7CBC2B78\n.long 0x389E0008\n.long 0x38A00100\n.long 0x7FC3F378\n.long 0x4BEF3D95\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x38A00001\n.long 0x4BEC8695\n.long 0x7FC3F378\n.long 0x4BEF3F01\n.long 0x7C641B78\n.long 0x7F83E378\n.long 0x4BEF4F5D\n.long 0x80010224\n.long 0x7C0803A6\n.long 0xBB810210\n.long 0x38210220\n.long 0x4E800020");
}
