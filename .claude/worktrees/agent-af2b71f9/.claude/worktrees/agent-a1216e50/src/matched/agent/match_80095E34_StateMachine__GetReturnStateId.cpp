// 0x80095E34 (116 bytes)
// StateMachine::GetReturnStateId(void) const

class StateMachine { public: void GetReturnStateId(void) const; };

__attribute__((naked))
void StateMachine::GetReturnStateId(void) const {
    asm volatile(".long 0x9421FFE8\n.long 0x39230064\n.long 0x81630064\n.long 0x81490004\n.long 0x38E10008\n.long 0x8109000C\n.long 0x80090008\n.long 0x7C0B5000\n.long 0x91610008\n.long 0x90010010\n.long 0x9141000C\n.long 0x91010014\n.long 0x40820024\n.long 0x3808FFFC\n.long 0x90010014\n.long 0x8128FFFC\n.long 0x39690080\n.long 0x9121000C\n.long 0x91610010\n.long 0x80070008\n.long 0x90010008\n.long 0x81410008\n.long 0x380AFFFC\n.long 0x90010008\n.long 0x812AFFFC\n.long 0x81690000\n.long 0x806B0000\n.long 0x38210018\n.long 0x4E800020");
}
