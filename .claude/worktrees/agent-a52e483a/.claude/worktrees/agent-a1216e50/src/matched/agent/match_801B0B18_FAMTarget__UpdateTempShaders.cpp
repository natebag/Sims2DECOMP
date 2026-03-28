// 0x801B0B18 (96 bytes)
// FAMTarget::UpdateTempShaders(void)

class FAMTarget { public: void UpdateTempShaders(void); };

__attribute__((naked))
void FAMTarget::UpdateTempShaders(void) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBFC10020\n.long 0x9001002C\n.long 0x83C3014C\n.long 0x38610008\n.long 0x1FDE0050\n.long 0x3BDE0064\n.long 0x4BFCC6FD\n.long 0x3C80803F\n.long 0x38610008\n.long 0x38840490\n.long 0x7FC6F378\n.long 0x38A00064\n.long 0x38E00000\n.long 0x4BFCC94D\n.long 0x38610008\n.long 0x38800002\n.long 0x4BFCC6F5\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBBC10020\n.long 0x38210028\n.long 0x4E800020");
}
