// 0x8032144C ArcCopier::~ArcCopier(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x4(31); cmpwi 0,0; beq 0f; lis 3,-32694; addi 4,31,4; addi 3,3,-10620; bl _s8032144C_0; li 0,0; stw 0,0x4(31); 0:; li 0,0; andi. 9,30,1; stw 0,0xc(31); stw 0,0x0(31); stw 0,0x8(31); beq 1f; mr 3,31; bl _s8032144C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032144C_0();
extern "C" void _s8032144C_1();
extern "C" void f_8032144C() {}
