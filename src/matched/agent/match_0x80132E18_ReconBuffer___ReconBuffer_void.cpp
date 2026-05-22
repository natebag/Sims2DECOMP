// 0x80132E18 ReconBuffer::~ReconBuffer(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0xc(31); cmpwi 0,1; bne 0f; lwz 11,0x1c(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x108(9); lwz 0,0x10c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 3,0x1c(31); bl _s80132E18_0; li 0,0; andi. 9,30,1; stw 0,0x1c(31); beq 1f; mr 3,31; bl _s80132E18_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80132E18_0();
extern "C" void _s80132E18_1();
extern "C" void f_80132E18() {}
