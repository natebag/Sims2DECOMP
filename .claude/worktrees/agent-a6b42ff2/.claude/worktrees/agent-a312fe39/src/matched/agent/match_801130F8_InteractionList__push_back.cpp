// 0x801130F8 (124 bytes)
// InteractionList::push_back(cXPerson *, cXObject *, int, int)

class InteractionList { public: void push_back(cXPerson *, cXObject *, int, int); };

__attribute__((naked))
void InteractionList::push_back(cXPerson *, cXObject *, int, int) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x7CBD2B78\n.long 0x7CDC3378\n.long 0x7CFB3B78\n.long 0x38600044\n.long 0x481BE091\n.long 0x7FC4F378\n.long 0x7FA5EB78\n.long 0x7F86E378\n.long 0x7F67DB78\n.long 0x4BFAE441\n.long 0x38000000\n.long 0x90030000\n.long 0x813F0004\n.long 0x2C090000\n.long 0x41820010\n.long 0x90690000\n.long 0x907F0004\n.long 0x4800000C\n.long 0x907F0004\n.long 0x907F0000\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
