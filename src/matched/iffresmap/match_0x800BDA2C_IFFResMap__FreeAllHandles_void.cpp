// 0x800BDA2C IFFResMap::FreeAllHandles(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; lwz 29,0x0(27); lwz 0,0x4(27); cmpw 29,0; beq 5f; 0:; lwz 30,0x0(29); addi 28,29,24; lwz 0,0x4(29); cmpw 30,0; beq 4f; 1:; lwz 31,0xc(30); cmpwi 31,0; beq 3f; lwz 0,0x8(31); cmpwi 0,0; beq 2f; bl _s800BDA2C_0; lwz 4,0x4(31); bl _s800BDA2C_1; 2:; bl _s800BDA2C_2; mr 4,31; bl _s800BDA2C_3; 3:; lwz 0,0x4(29); addi 30,30,88; cmpw 30,0; bne 1b; 4:; lwz 0,0x4(27); mr 29,28; cmpw 29,0; bne 0b; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800BDA2C_0();
extern "C" void _s800BDA2C_1();
extern "C" void _s800BDA2C_2();
extern "C" void _s800BDA2C_3();

struct IFFResMap {
    void FreeAllHandles();
};

void IFFResMap::FreeAllHandles() {
}
