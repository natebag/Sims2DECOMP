// 0x801558F4 Stuck(vector<PenaltyRect, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); lwz 9,0x4(4); mr. 31,3; lwz 10,0x0(4); addi 11,9,1; stw 9,0x8(1); addi 0,10,1; stw 11,0x10(1); stw 0,0x14(1); stw 10,0xc(1); beq 0f; addi 3,1,8; mr 4,31; bl _s801558F4_0; cmpwi 3,-1; beq 0f; mulli 10,3,20; lwz 9,0x0(31); lis 11,32767; ori 11,11,65535; li 3,1; add 9,9,10; lwz 0,0x10(9); cmpw 0,11; beq 1f; 0:; li 3,0; 1:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801558F4_0();
extern "C" void f_801558F4() {}
