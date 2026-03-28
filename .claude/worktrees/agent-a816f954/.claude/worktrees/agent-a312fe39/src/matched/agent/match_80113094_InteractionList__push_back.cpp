// 0x80113094 (100 bytes)
// InteractionList::push_back(Interaction &)

class InteractionList { public: void push_back(Interaction &); };

__attribute__((naked))
void InteractionList::push_back(Interaction &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x38600044\n.long 0x481BE101\n.long 0x7FC4F378\n.long 0x4BFAE119\n.long 0x38000000\n.long 0x90030000\n.long 0x813F0004\n.long 0x2C090000\n.long 0x41820010\n.long 0x90690000\n.long 0x907F0004\n.long 0x4800000C\n.long 0x907F0004\n.long 0x907F0000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
