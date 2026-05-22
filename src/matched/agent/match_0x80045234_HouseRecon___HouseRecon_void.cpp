// 0x80045234 HouseRecon::~HouseRecon(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; addis 3,29,1; addic. 0,3,-32764; beq 1f; addi 31,3,24580; cmpw 0,31; beq 1f; mr 30,0; 0:; addi 31,31,-28; li 4,2; addi 3,31,16; bl _s80045234_0; cmpw 30,31; bne 0b; 1:; andi. 0,28,1; beq 2f; mr 3,29; bl _s80045234_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80045234_0();
extern "C" void _s80045234_1();
extern "C" void f_80045234() {}
