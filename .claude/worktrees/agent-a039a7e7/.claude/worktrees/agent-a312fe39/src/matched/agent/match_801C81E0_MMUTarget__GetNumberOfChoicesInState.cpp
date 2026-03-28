// 0x801C81E0 (72 bytes)
// MMUTarget::GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE)

class MMUTarget { public: void GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE); };

__attribute__((naked))
void MMUTarget::GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE) {
    asm volatile(".long 0x800300B0\n.long 0x38600000\n.long 0x2C000001\n.long 0x4082000C\n.long 0x38600003\n.long 0x4E800020\n.long 0x2C000002\n.long 0x4D820020\n.long 0x2C000003\n.long 0x4D820020\n.long 0x2C000004\n.long 0x4082000C\n.long 0x38600002\n.long 0x4E800020\n.long 0x2C000000\n.long 0x4C820020\n.long 0x38600002\n.long 0x4E800020");
}
