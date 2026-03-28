// 0x800939DC (84 bytes)
// MUStateMachine::SetupQuitToMainMenu(void)

class MUStateMachine { public: void SetupQuitToMainMenu(void); };

__attribute__((naked))
void MUStateMachine::SetupQuitToMainMenu(void) {
    asm volatile(".long 0x3D208048\n.long 0x3D608047\n.long 0x394B5B84\n.long 0x390958D8\n.long 0x81680030\n.long 0x38E00001\n.long 0x81280004\n.long 0x38000000\n.long 0x900A00A4\n.long 0x2C0B0002\n.long 0x912A00A0\n.long 0x90EA009C\n.long 0x40820008\n.long 0x90EA00A4\n.long 0x80080034\n.long 0x2C000002\n.long 0x4C820020\n.long 0x800A00A4\n.long 0x60000002\n.long 0x900A00A4\n.long 0x4E800020");
}
