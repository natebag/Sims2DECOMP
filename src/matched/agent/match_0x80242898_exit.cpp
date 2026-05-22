// 0x80242898 exit (128B)
// ASMPROC_inject_before: before="blr" replace="bl f_80249640" lines="stwu 1,-24(1); mflr 0; stmw 28,8(1); stw 0,28(1); lwz 9,-27948(13); mr 28,3; lwz 29,328(9); cmpwi 29,0; beq 4f; 1:; lwz 31,4(29); addic. 31,31,-1; blt 3f; slwi 9,31,2; addi 9,9,8; add 30,9,29; 2:; lwz 9,0(30); addi 30,30,-4; mtlr 9; blrl; addic. 31,31,-1; bge 2b; 3:; lwz 29,0(29); cmpwi 29,0; bne 1b; 4:; lwz 3,-27948(13); lwz 0,60(3); cmpwi 0,0; beq 5f; mtlr 0; blrl; 5:; mr 3,28"
extern "C" void f_80249640();
extern "C" void f_80242898() {}
