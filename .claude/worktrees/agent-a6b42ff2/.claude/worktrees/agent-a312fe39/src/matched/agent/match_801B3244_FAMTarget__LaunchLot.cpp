// 0x801B3244 (64 bytes)
// FAMTarget::LaunchLot(void)

class FAMTarget { public: void LaunchLot(void); };

__attribute__((naked))
void FAMTarget::LaunchLot(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x8083014C\n.long 0x4BFFF79D\n.long 0x7C641B78\n.long 0x3C608047\n.long 0x3863E208\n.long 0x4BE50D81\n.long 0x3C60803F\n.long 0x38630794\n.long 0x4BFC4A9D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
