// 0x80232F84 ERLevel::DestroyInstancesOriginallyReadByLevel(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addis 9,3,3; lwz 0,-15688(9); addic. 31,0,-1; blt 2f; rlwinm 9,31,2,0,29; addis 9,9,3; addi 9,9,-23880; add 30,9,3; 0:; lwz 11,0x0(30); addi 30,30,-4; lwz 0,0x5c(11); rlwinm 0,0,0,17,18; cmpwi 0,8192; bne 1f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; addic. 31,31,-1; bge 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80232F84() {}
