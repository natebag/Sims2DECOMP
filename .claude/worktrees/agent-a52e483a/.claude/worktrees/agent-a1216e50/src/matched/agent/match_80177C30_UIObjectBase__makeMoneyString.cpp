// 0x80177C30 (120 bytes)
// UIObjectBase::makeMoneyString(int, unsigned wchar_t *, bool)

class UIObjectBase { public: void makeMoneyString(int, unsigned wchar_t *, bool); };

__attribute__((naked))
void UIObjectBase::makeMoneyString(int, unsigned wchar_t *, bool) {
    asm volatile(".long 0x9421FDE0\n.long 0x7C0802A6\n.long 0xBF810210\n.long 0x90010224\n.long 0x7C7D1B78\n.long 0x7CBF2B78\n.long 0x7C9C2379\n.long 0x41820044\n.long 0x3BC10008\n.long 0x38A00100\n.long 0x389E0008\n.long 0x7FC3F378\n.long 0x4BF2F085\n.long 0x7FE5FB78\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x4BF03985\n.long 0x7FC3F378\n.long 0x4BF2F1F1\n.long 0x7C641B78\n.long 0x7F83E378\n.long 0x4BF3024D\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x80010224\n.long 0x7C0803A6\n.long 0xBB810210\n.long 0x38210220\n.long 0x4E800020");
}
