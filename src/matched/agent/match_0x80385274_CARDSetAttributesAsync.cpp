// 0x80385274 CARDSetAttributesAsync (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-112(1); stmw 27,0x5c(1); rlwinm 31,5,0,24,31; mr 29,5; addi 27,3,0; addi 28,4,0; addi 30,6,0; lbz 0,-25334(13); andc. 0,31,0; beq 0f; li 3,-10; b 9f; 0:; addi 3,27,0; addi 4,28,0; addi 5,1,24; bl _s80385274_0; cmpwi 3,0; bge 1f; b 9f; 1:; lbz 3,0x4c(1); rlwinm. 5,3,0,26,26; beq 2f; rlwinm. 0,31,0,26,26; beq 3f; 2:; rlwinm. 4,3,0,25,25; beq 4f; rlwinm. 0,31,0,25,25; bne 4f; 3:; li 3,-10; b 9f; 4:; rlwinm. 3,31,0,26,26; beq 5f; rlwinm. 0,31,0,25,25; bne 7f; 5:; cmplwi 3,0; beq 6f; cmplwi 4,0; bne 7f; 6:; rlwinm. 0,31,0,25,25; beq 8f; cmplwi 5,0; beq 8f; 7:; li 3,-10; b 9f; 8:; stb 29,0x4c(1); addi 3,27,0; addi 4,28,0; addi 6,30,0; addi 5,1,24; bl _s80385274_1; 9:; lmw 27,0x5c(1); lwz 0,0x74(1); addi 1,1,112; mtspr 8,0"
extern "C" void _s80385274_0();
extern "C" void _s80385274_1();
extern "C" void f_80385274() {}
