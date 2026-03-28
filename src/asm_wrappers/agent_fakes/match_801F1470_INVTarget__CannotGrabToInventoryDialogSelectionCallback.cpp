// 0x801F1470 (76 bytes)
// INVTarget::CannotGrabToInventoryDialogSelectionCallback(int)

class INVTarget { public: void CannotGrabToInventoryDialogSelectionCallback(int); };

__attribute__((naked))
void INVTarget::CannotGrabToInventoryDialogSelectionCallback(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x2C040000\n.long 0x40820020\n.long 0x4801A1C9\n.long 0x809F0084\n.long 0x38A00002\n.long 0x4801A10D\n.long 0x7C631B79\n.long 0x41820008\n.long 0x48029069\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
