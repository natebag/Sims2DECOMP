// 0x80161D18 (108 bytes)
// CasMediator::AddListener(CasListener &)

class CasMediator { public: void AddListener(CasListener &); };

__attribute__((naked))
void CasMediator::AddListener(CasListener &) {
    asm volatile(".long 0x9421FFD0\n.long 0x7C0802A6\n.long 0xBFA10024\n.long 0x90010034\n.long 0x7C9E2378\n.long 0x7C7D1B78\n.long 0x38610010\n.long 0x7FA4EB78\n.long 0x93C10018\n.long 0x38A10018\n.long 0x4824EEE1\n.long 0x80010014\n.long 0x7FA4EB78\n.long 0x81210010\n.long 0x9001000C\n.long 0x91210008\n.long 0x813E0004\n.long 0xA8690018\n.long 0x8009001C\n.long 0x7C7E1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010034\n.long 0x7C0803A6\n.long 0xBBA10024\n.long 0x38210030\n.long 0x4E800020");
}
