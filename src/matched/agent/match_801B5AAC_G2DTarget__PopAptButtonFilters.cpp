// 0x801B5AAC (104 bytes)
// G2DTarget::PopAptButtonFilters(void)

class G2DTarget { public: void PopAptButtonFilters(void); };

__attribute__((naked))
void G2DTarget::PopAptButtonFilters(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x3D208047\n.long 0x3BE30120\n.long 0x3B895DCC\n.long 0x3BC00000\n.long 0x3BA0FFFF\n.long 0x801F0000\n.long 0x7FC4F378\n.long 0x3BDE0001\n.long 0x7C050378\n.long 0x2C00FFFF\n.long 0x41820010\n.long 0x807C00B4\n.long 0x4BE5C061\n.long 0x93BF0000\n.long 0x3BFF0004\n.long 0x2C1E0001\n.long 0x4081FFD4\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
