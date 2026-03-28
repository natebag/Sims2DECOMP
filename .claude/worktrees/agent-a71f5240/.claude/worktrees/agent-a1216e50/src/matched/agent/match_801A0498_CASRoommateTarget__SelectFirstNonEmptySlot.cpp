// 0x801A0498 (124 bytes)
// CASRoommateTarget::SelectFirstNonEmptySlot(void)

class CASRoommateTarget { public: void SelectFirstNonEmptySlot(void); };

__attribute__((naked))
void CASRoommateTarget::SelectFirstNonEmptySlot(void) {
    asm volatile(".long 0x38000004\n.long 0x81630090\n.long 0x7C0903A6\n.long 0x39000000\n.long 0x39400000\n.long 0x7D6B5214\n.long 0x7D605B78\n.long 0x2C0B0000\n.long 0x40800008\n.long 0x380B0003\n.long 0x5400003A\n.long 0x81230084\n.long 0x7D605850\n.long 0x8129001C\n.long 0x7D605B78\n.long 0x2C0B0000\n.long 0x40800008\n.long 0x380B0003\n.long 0x81291348\n.long 0x5400003A\n.long 0x7C005850\n.long 0x7D290430\n.long 0x71200001\n.long 0x4182000C\n.long 0x39000001\n.long 0x4800000C\n.long 0x394A0001\n.long 0x4200FFA8\n.long 0x91630090\n.long 0x7D034378\n.long 0x4E800020");
}
