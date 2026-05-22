// 0x8021D364 InteractorModule::SimInteractor::~SimInteractor(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 9,9,-31264; mr 28,4; stw 9,0x5c(30); addi 3,30,416; li 4,2; bl _s8021D364_0; addic. 0,30,100; beq 1f; addi 31,30,380; cmpw 0,31; beq 1f; mr 29,0; 0:; addi 31,31,-28; li 4,0; mr 3,31; bl _s8021D364_1; cmpw 29,31; bne 0b; 1:; lis 9,-32697; andi. 0,28,1; addi 9,9,-32144; stw 9,0x5c(30); beq 2f; mr 3,30; bl _s8021D364_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8021D364_0();
extern "C" void _s8021D364_1();
extern "C" void _s8021D364_2();
extern "C" void f_8021D364() {}
