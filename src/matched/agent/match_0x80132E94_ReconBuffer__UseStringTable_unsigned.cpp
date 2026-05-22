// 0x80132E94 ReconBuffer::UseStringTable(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 0,1; lwz 9,0xc(31); mr 30,4; mr 28,5; mr 29,6; stw 0,0x14(31); cmpwi 9,2; beq 0f; bl _s80132E94_0; stw 3,0x1c(31); mr 4,30; mr 5,29; mr 6,28; lwz 9,0x0(3); li 7,0; li 8,-1; lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(31); cmpwi 0,0; bne 0f; lwz 3,0x1c(31); li 4,0; li 5,1; lwz 9,0x0(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80132E94_0();
extern "C" void f_80132E94() {}
