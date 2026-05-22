// 0x802F1690 EGraphics::Destroy(ETexture (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr. 29,4; beq 3f; lwz 0,-26312(13); cmpwi 0,0; beq 3f; li 31,0; b 1f; 0:; addi 31,31,1; 1:; cmpwi 31,1; bgt 2f; lwz 3,-26312(13); mr 4,31; lwz 9,0x338(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,29; bne 0b; lwz 9,0x0(30); lha 3,0x178(9); lwz 0,0x17c(9); add 3,30,3; mtspr 8,0; blrl; 2:; lwz 9,0x0(30); mr 4,29; lha 3,0x1f0(9); lwz 0,0x1f4(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,0x34(30); addi 9,9,-1; stw 9,0x34(30); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F1690() {}
