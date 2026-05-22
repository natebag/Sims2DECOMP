// 0x801C2A24 M2MTarget::CalcNumItems(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x168(31); cmpwi 0,0; bne 0f; li 0,1; stw 0,0x188(31); b 1f; 0:; mr 3,31; addi 4,31,268; bl _s801C2A24_0; stw 3,0x188(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801C2A24_0();
extern "C" void f_801C2A24() {}
