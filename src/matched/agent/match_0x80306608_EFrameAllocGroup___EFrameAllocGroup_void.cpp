// 0x80306608 EFrameAllocGroup::~EFrameAllocGroup(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 0,-26876(13); lis 9,-32697; mr 30,3; addi 9,9,-20760; mr 28,4; stw 9,0x0(30); cmpwi 0,0; bne 0f; bl _s80306608_0; 0:; addic. 0,30,4; mr 29,0; beq 2f; addi 31,30,52; cmpw 29,31; beq 2f; 1:; addi 31,31,-24; mr 3,31; bl _s80306608_1; mr 3,31; bl _s80306608_2; cmpw 29,31; bne 1b; 2:; lis 9,-32697; mr 3,30; addi 9,9,-24288; stw 9,0x0(30); bl _s80306608_3; andi. 0,28,1; beq 3f; mr 3,30; bl _s80306608_4; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80306608_0();
extern "C" void _s80306608_1();
extern "C" void _s80306608_2();
extern "C" void _s80306608_3();
extern "C" void _s80306608_4();
extern "C" void f_80306608() {}
