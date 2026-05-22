// 0x80122A14 IsAskedToMove(cXPersonImpl (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,1; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 2f; 0:; lwz 3,0x4(30); addi 31,31,-1; mr 4,31; li 5,1; lwz 9,0x4(3); lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; bl _s80122A14_0; cmpwi 3,0; beq 1f; li 3,1; b 3f; 1:; cmpwi 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80122A14_0();
extern "C" void f_80122A14() {}
