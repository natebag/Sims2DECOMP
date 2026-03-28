// 0x801D6DEC (124 bytes)
// PCTTarget::delete_dialog_selection_callback(int)

class PCTTarget { public: void delete_dialog_selection_callback(int); };

__attribute__((naked))
void PCTTarget::delete_dialog_selection_callback(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x38000000\n.long 0x901F00F0\n.long 0x2C040000\n.long 0x40820048\n.long 0x48034845\n.long 0x809F0084\n.long 0x38A00002\n.long 0x48034789\n.long 0x7C631B79\n.long 0x41820008\n.long 0x480436E5\n.long 0x807F0214\n.long 0x2C030000\n.long 0x41820018\n.long 0x38800000\n.long 0x4BFCD179\n.long 0x807F0214\n.long 0x38800000\n.long 0x4BFCCFE9\n.long 0x38600001\n.long 0x4BE6B959\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
