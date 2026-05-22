// 0x80157FB8 SetDirectionForGoalSearch(cXObject (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lbz 0,0x1f(6); mr 11,3; cmpwi 0,0; bne 0f; addi 0,4,4; b 3f; 0:; lwz 0,0x34(6); cmpwi 0,-1; bne 1f; mr 4,5; b 4f; 1:; cmpwi 0,-2; bne 2f; addi 0,5,4; b 3f; 2:; cmpwi 0,-3; beq 6f; add 0,4,0; 3:; extsh 4,0; 4:; mr 5,4; cmpwi 4,0; bge 5f; addi 5,4,7; 5:; lwz 9,0x4(11); rlwinm 5,5,0,0,28; subf 5,5,4; lha 3,0x1e8(9); li 4,1; lwz 0,0x1ec(9); extsh 5,5; add 3,11,3; mtspr 8,0; blrl; 6:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80157FB8() {}
