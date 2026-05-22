// 0x802D76B0 efgets (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; mr 29,5; mr 28,27; mr. 30,4; mr 31,28; bgt 0f; li 3,0; b 4f; 0:; addic. 30,30,-1; beq 2f; lwz 9,0x28(29); addi 4,1,8; li 5,1; lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; cmpw 31,27; bne 2f; li 28,0; b 3f; 1:; lbz 0,0x8(1); extsb 9,0; stb 0,0x0(31); cmpwi 9,10; addi 31,31,1; bne 0b; 2:; li 0,0; stb 0,0x0(31); 3:; mr 3,28; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void f_802D76B0() {}
