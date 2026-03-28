// 0x8011A90C (120 bytes)
// cXPersonImpl::CleanupStaticMemory(void)

class cXPersonImpl { public: void CleanupStaticMemory(void); };

__attribute__((naked))
void cXPersonImpl::CleanupStaticMemory(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x800D8424\n.long 0x2C000000\n.long 0x4182004C\n.long 0x3D208048\n.long 0x3BE00000\n.long 0x3BA966BC\n.long 0x801D0004\n.long 0x7C1F0000\n.long 0x4080002C\n.long 0x3BC00000\n.long 0x807D0000\n.long 0x38800000\n.long 0x3BFF0001\n.long 0x7C63F214\n.long 0x48012301\n.long 0x3BDE0014\n.long 0x801D0004\n.long 0x7C1F0000\n.long 0x4180FFE0\n.long 0x38000000\n.long 0x900D8424\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
