// 0x8029E270 AptFileNameCompare(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr. 29,3; beq 0f; cmpwi 30,0; beq 0f; mr 3,29; bl _s8029E270_0; mr 31,3; mr 3,30; bl _s8029E270_1; cmpw 31,3; beq 1f; 0:; li 3,0; b 9f; 1:; li 8,0; cmpw 8,31; bge 8f; 2:; lbzx 0,29,8; lbzx 9,30,8; extsb 0,0; extsb 9,9; cmpw 0,9; beq 7f; mr 11,0; mr 10,9; addi 0,11,-97; cmplwi 0,25; bgt 3f; addi 0,11,-32; extsb 11,0; b 4f; 3:; cmpwi 11,92; bne 4f; li 11,47; 4:; cmpw 11,9; beq 7f; addi 0,9,-97; cmplwi 0,25; bgt 5f; addi 0,9,-32; extsb 10,0; b 6f; 5:; cmpwi 9,92; bne 6f; li 10,47; 6:; cmpw 11,10; bne 0b; 7:; addi 8,8,1; cmpw 8,31; blt 2b; 8:; li 3,1; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8029E270_0();
extern "C" void _s8029E270_1();
extern "C" void f_8029E270() {}
