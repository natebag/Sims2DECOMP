// 0x801F119C (88 bytes)
// INVTarget::ClearAllObjRelatedCheatStrings(void)

class INVTarget { public: void ClearAllObjRelatedCheatStrings(void); };

__attribute__((naked))
void INVTarget::ClearAllObjRelatedCheatStrings(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800000\n.long 0x38A00800\n.long 0x387E118B\n.long 0x48052429\n.long 0x38800000\n.long 0x38A00800\n.long 0x387E198B\n.long 0x48052419\n.long 0x387E218B\n.long 0x38800000\n.long 0x38A00800\n.long 0x48052409\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
