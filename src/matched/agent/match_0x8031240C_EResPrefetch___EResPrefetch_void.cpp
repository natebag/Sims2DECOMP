// 0x8031240C EResPrefetch::~EResPrefetch(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; lis 11,-32697; lwz 0,0x3d8(31); addi 9,9,-19760; addi 11,11,-19728; mr 29,4; stw 9,0x340(31); stw 11,0x0(31); cmpwi 0,0; beq 0f; addi 3,31,908; bl _s8031240C_0; 0:; addi 30,31,8; mr 3,30; bl _s8031240C_1; addi 3,31,908; li 4,2; bl _s8031240C_2; addi 3,31,840; li 4,2; bl _s8031240C_3; mr 3,30; li 4,0; bl _s8031240C_4; lis 9,-32697; andi. 0,29,1; addi 9,9,-19680; stw 9,0x0(31); beq 1f; mr 3,31; bl _s8031240C_5; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031240C_0();
extern "C" void _s8031240C_1();
extern "C" void _s8031240C_2();
extern "C" void _s8031240C_3();
extern "C" void _s8031240C_4();
extern "C" void _s8031240C_5();
extern "C" void f_8031240C() {}
