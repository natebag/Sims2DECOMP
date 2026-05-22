// 0x801851F8 ActionQueueHUD::RemoveAction(Interaction (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 28,4; lwz 0,0x150(30); li 5,0; lwz 10,0x38(28); cmplw 5,0; bge 1f; mr 9,0; addi 11,30,168; 0:; lwz 0,0x0(11); addi 11,11,20; cmpw 0,10; beq 6f; addi 5,5,1; cmplw 5,9; blt 0b; 1:; lwz 31,0x150(30); mr 0,31; 2:; cmplw 31,0; blt 7f; lbz 4,0x308(30); li 31,0; cmplw 31,4; bge 11f; addi 29,30,704; mr 27,29; 3:; lwz 9,0x38(28); lwz 0,0x0(29); cmpw 0,9; bne 4f; addi 3,30,344; mr 5,31; li 6,1; bl _s801851F8_0; lbz 4,0x308(30); mr 3,27; mr 5,31; li 6,1; bl _s801851F8_1; lbz 9,0x308(30); addi 9,9,-1; stb 9,0x308(30); b 5f; 4:; addi 29,29,4; addi 31,31,1; 5:; lbz 4,0x308(30); cmplw 31,4; blt 3b; b 11f; 6:; mr 31,5; lwz 0,0x150(30); b 2b; 7:; lbz 0,0x308(30); cmplwi 0,17; ble 8f; mr 3,30; bl _s801851F8_2; lbz 0,0x308(30); cmplwi 0,17; bgt 11f; 8:; lwz 0,0x150(30); li 8,2; cmplw 31,0; bge 10f; mulli 9,31,20; li 11,1; add 9,9,30; lbz 0,0xad(9); cmpwi 0,0; bne 9f; li 11,0; 9:; cmpwi 11,0; beq 10f; li 8,3; 10:; lbz 9,0x308(30); addi 10,30,704; mulli 9,9,20; add 9,30,9; stb 8,0x168(9); lbz 0,0x308(30); lwz 11,0x38(28); rlwinm 0,0,2,0,29; stwx 11,10,0; lbz 9,0x308(30); lbz 0,0x30a(30); addi 9,9,1; stb 9,0x308(30); cmpwi 0,0; bne 11f; mr 3,30; bl _s801851F8_3; 11:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801851F8_0();
extern "C" void _s801851F8_1();
extern "C" void _s801851F8_2();
extern "C" void _s801851F8_3();
extern "C" void f_801851F8() {}
