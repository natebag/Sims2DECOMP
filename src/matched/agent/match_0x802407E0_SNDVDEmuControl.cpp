// 0x802407E0 SNDVDEmuControl (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32700; li 10,0; lwz 0,-23456(9); cmpwi 0,-32768; beq 0f; li 3,0; b 8f; 0:; cmpwi 3,1; beq 3f; bgt 1f; cmpwi 3,0; beq 2f; b 7f; 1:; cmpwi 3,2; beq 4f; cmpwi 3,3; beq 5f; b 7f; 2:; lis 9,-32694; stb 10,-26351(9); b 7f; 3:; lis 9,-32694; stb 3,-26351(9); b 7f; 4:; lis 9,-32694; stb 10,-26352(9); bl _s802407E0_0; b 6f; 5:; lis 9,-32694; li 0,1; stb 0,-26352(9); bl _s802407E0_1; 6:; lis 10,-32768; 7:; lis 9,-32694; lis 11,-32694; lbz 3,-26352(9); lbz 0,-26351(11); rlwinm 3,3,8,0,23; or 3,10,3; or 3,3,0; 8:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802407E0_0();
extern "C" void _s802407E0_1();
extern "C" void f_802407E0() {}
