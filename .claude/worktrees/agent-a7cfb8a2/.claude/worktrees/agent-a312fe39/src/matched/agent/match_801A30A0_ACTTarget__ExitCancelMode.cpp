// 0x801A30A0 (124 bytes)
// ACTTarget::ExitCancelMode(void)

class ACTTarget { public: void ExitCancelMode(void); };

__attribute__((naked))
void ACTTarget::ExitCancelMode(void) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBFC10020\n.long 0x9001002C\n.long 0x7C7E1B78\n.long 0x39200000\n.long 0x801E0648\n.long 0x913E0648\n.long 0x901E064C\n.long 0x913E0644\n.long 0x4BFFFED1\n.long 0x38610008\n.long 0x4BFDA165\n.long 0x80DE00DC\n.long 0x3C80803F\n.long 0x38610008\n.long 0x38A00000\n.long 0x3884DDB0\n.long 0x4BFDA675\n.long 0x3D208047\n.long 0x809E00DC\n.long 0x80695BCC\n.long 0x48015BA1\n.long 0x38610008\n.long 0x38800002\n.long 0x4BFDA151\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBBC10020\n.long 0x38210028\n.long 0x4E800020");
}
