// 0x800B6068 FamilyImpl::~FamilyImpl(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-5024; addi 11,31,36; stw 9,0x0(31); mr 30,4; lwz 9,0x24(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,4; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s800B6068_0; b 3f; 2:; bl _s800B6068_1; 3:; addi 3,31,4; li 4,2; bl _s800B6068_2; mr 3,31; mr 4,30; bl _s800B6068_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B6068_0();
extern "C" void _s800B6068_1();
extern "C" void _s800B6068_2();
extern "C" void _s800B6068_3();
extern "C" void f_800B6068() {}
