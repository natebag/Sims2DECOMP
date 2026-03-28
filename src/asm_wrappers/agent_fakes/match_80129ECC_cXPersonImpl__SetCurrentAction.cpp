// 0x80129ECC (68 bytes)
// cXPersonImpl::SetCurrentAction(Interaction &)

class cXPersonImpl { public: void SetCurrentAction(Interaction &); };

__attribute__((naked))
void cXPersonImpl::SetCurrentAction(Interaction &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000001\n.long 0x901E0534\n.long 0x387E0130\n.long 0x38A00000\n.long 0x4BFF0509\n.long 0x7FC3F378\n.long 0x48000019\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
