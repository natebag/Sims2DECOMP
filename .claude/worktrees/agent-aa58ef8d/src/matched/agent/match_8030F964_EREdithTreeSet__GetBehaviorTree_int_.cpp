// 0x8030F964 (108 bytes)
// EREdithTreeSet::GetBehaviorTree(int)

class EREdithTreeSet { public: void GetBehaviorTree(int); };

__attribute__((naked))
void EREdithTreeSet::GetBehaviorTree(int) {
    asm volatile(".long 0x81230018\n.long 0x2C090000\n.long 0x40820014\n.long 0x38600000\n.long 0x4E800020\n.long 0x80670008\n.long 0x4E800020\n.long 0x3949FFFF\n.long 0x39000000\n.long 0x7C085040\n.long 0x4181003C\n.long 0x8063001C\n.long 0x7C085214\n.long 0x540BF87E\n.long 0x1D2B000C\n.long 0x7C09182E\n.long 0x7CE91A14\n.long 0x7C040000\n.long 0x4182FFCC\n.long 0x4080000C\n.long 0x394BFFFF\n.long 0x48000008\n.long 0x390B0001\n.long 0x7C085040\n.long 0x4081FFD0\n.long 0x38600000\n.long 0x4E800020");
}
