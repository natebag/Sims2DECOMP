// 0x8034D330 ENgcSFXStreamer::SetLeftVolume(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,5; cmpwi 30,-1; beq 1f; bl _s8034D330_0; mulli 11,31,904; lis 0,26843; ori 0,0,35757; mulli 10,30,68; lis 9,-32690; addi 9,9,-19244; mulhw 0,11,0; srawi 11,11,31; lwzx 3,10,9; srawi 0,0,12; cmpwi 3,0; subf 4,11,0; beq 0f; bl _s8034D330_1; 0:; bl _s8034D330_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034D330_0();
extern "C" void _s8034D330_1();
extern "C" void _s8034D330_2();
extern "C" void f_8034D330() {}
