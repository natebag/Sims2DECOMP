// 0x8029C920 _getCharacterGridPosition(EAStringC (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 3,0x0(3); lis 9,-32700; addi 9,9,-6476; mr 29,4; mr 30,5; cmpw 3,9; beq 2f; lhz 9,0x2(3); addi 10,3,8; lis 11,-32704; addi 9,9,-1; addi 11,11,-935; lbzx 0,10,9; add 31,10,9; extsb 0,0; lbzx 9,11,0; andi. 0,9,4; beq 2f; cmpwi 7,30,0; 0:; lbzu 0,-1(31); extsb 0,0; lbzx 9,11,0; andi. 0,9,4; bne 0b; beq cr7,1f; addi 3,31,1; bl _s8029C920_0; stw 3,0x0(30); 1:; lbz 0,0x0(31); addi 31,31,-1; cmpwi 0,95; bne 2f; lbz 0,0x0(31); lis 9,-32704; addi 11,9,-935; extsb 0,0; lbzx 9,11,0; andi. 0,9,4; bne 3f; 2:; li 3,0; b 6f; 3:; cmpwi 7,29,0; 4:; lbzu 0,-1(31); extsb 0,0; lbzx 9,11,0; andi. 0,9,4; bne 4b; beq cr7,5f; addi 3,31,1; bl _s8029C920_1; stw 3,0x0(29); 5:; li 3,1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8029C920_0();
extern "C" void _s8029C920_1();
extern "C" void f_8029C920() {}
