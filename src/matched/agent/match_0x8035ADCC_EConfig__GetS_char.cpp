// 0x8035ADCC EConfig::GetS(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,3; mr 29,5; mr 31,28; mr. 30,4; bgt 2f; 0:; li 3,0; b 4f; 1:; lbz 9,0x8(1); extsb 0,9; cmpwi 0,13; beq 2f; cmpwi 0,10; beq 3f; stb 9,0x0(31); addi 31,31,1; 2:; addic. 30,30,-1; beq 3f; lwz 9,0x28(29); addi 4,1,8; li 5,1; lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1b; cmpw 31,28; beq 0b; 3:; li 0,0; mr 3,28; stb 0,0x0(31); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void f_8035ADCC() {}
