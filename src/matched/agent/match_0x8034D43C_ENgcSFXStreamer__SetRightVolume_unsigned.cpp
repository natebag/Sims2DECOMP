// 0x8034D43C ENgcSFXStreamer::SetRightVolume(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,5; cmpwi 31,-1; beq 1f; bl _s8034D43C_0; mulli 11,31,68; lis 9,-32690; addi 9,9,-19244; add 11,11,9; lwz 3,0x38(11); cmpwi 3,0; beq 0f; mulli 0,30,904; lis 4,26843; ori 4,4,35757; lwz 3,0x0(3); mulhw 4,0,4; srawi 0,0,31; srawi 4,4,12; subf 4,0,4; bl _s8034D43C_1; 0:; bl _s8034D43C_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034D43C_0();
extern "C" void _s8034D43C_1();
extern "C" void _s8034D43C_2();
extern "C" void f_8034D43C() {}
