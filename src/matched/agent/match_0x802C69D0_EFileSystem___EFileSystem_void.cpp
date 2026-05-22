// 0x802C69D0 EFileSystem::~EFileSystem(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-26876(13); lis 9,-32697; mr 31,3; addi 9,9,-24376; mr 30,4; stw 9,0x0(31); cmpwi 0,0; bne 0f; bl _s802C69D0_0; 0:; addi 3,31,4; li 4,2; bl _s802C69D0_1; lis 9,-32697; mr 3,31; addi 9,9,-24288; stw 9,0x0(31); bl _s802C69D0_2; andi. 0,30,1; beq 1f; mr 3,31; bl _s802C69D0_3; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C69D0_0();
extern "C" void _s802C69D0_1();
extern "C" void _s802C69D0_2();
extern "C" void _s802C69D0_3();
extern "C" void f_802C69D0() {}
