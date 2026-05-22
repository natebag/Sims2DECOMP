// 0x800BD474 IFFResMap::GetNode(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,5; mr 29,6; li 5,0; bl _s800BD474_0; lwz 0,0x4(30); mr 31,3; cmpw 31,0; bne 1f; b 5f; 0:; mr 3,30; b 6f; 1:; cmpwi 29,0; beq 2f; stw 29,0x14(31); 2:; lwz 30,0x0(31); lwz 0,0x4(31); cmpw 30,0; beq 5f; 3:; lwz 0,0x4(30); cmpw 0,28; bne 4f; lha 3,0x8(30); bl _s800BD474_1; cmpwi 3,0; beq 0b; 4:; lwz 0,0x4(31); addi 30,30,88; cmpw 30,0; bne 3b; 5:; li 3,0; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800BD474_0();
extern "C" void _s800BD474_1();
extern "C" void f_800BD474() {}
