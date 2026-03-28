// 0x80152FF0 (76 bytes)
// XRoute::ClearCurrentGoal(void)

class XRoute { public: void ClearCurrentGoal(void); };

__attribute__((naked))
void XRoute::ClearCurrentGoal(void) {
    asm volatile(".long 0x81230054\n.long 0x2C09FFFF\n.long 0x4D820020\n.long 0x2C090000\n.long 0x4180002C\n.long 0x80030004\n.long 0x81630000\n.long 0x7C0B0050\n.long 0x7C002670\n.long 0x7C090040\n.long 0x40800014\n.long 0x55292036\n.long 0x38000000\n.long 0x7D2B4A14\n.long 0x90090008\n.long 0x3800FFFF\n.long 0x90030058\n.long 0x90030054\n.long 0x4E800020");
}
