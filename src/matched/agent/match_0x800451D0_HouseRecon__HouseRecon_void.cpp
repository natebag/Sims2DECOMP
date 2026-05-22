// 0x800451D0 HouseRecon::HouseRecon(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 0,0; addis 9,29,1; li 30,2047; stw 0,-32768(9); addi 31,9,-32764; 0:; addi 3,31,16; bl _s800451D0_0; addi 31,31,28; cmpwi 30,0; addi 30,30,-1; bne 0b; addis 9,29,1; li 0,0; stw 0,0x6004(9); mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800451D0_0();
extern "C" void f_800451D0() {}
