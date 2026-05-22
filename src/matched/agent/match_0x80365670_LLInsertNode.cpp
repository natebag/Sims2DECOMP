// 0x80365670 LLInsertNode (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 9,0x84(31); lwz 0,0x88(31); addi 9,9,1; cmpwi 0,0; stw 9,0x84(31); bne 0f; stw 30,0x8c(31); stw 30,0x88(31); b 8f; 0:; cmpwi 5,1; bne 1f; stw 0,0x0(30); lwz 9,0x88(31); stw 30,0x4(9); stw 30,0x88(31); b 8f; 1:; cmpwi 5,2; bne 2f; lwz 0,0x8c(31); stw 0,0x4(30); lwz 9,0x8c(31); stw 30,0x0(9); stw 30,0x8c(31); b 8f; 2:; cmpwi 5,3; bne 8f; mr 3,31; bl _s80365670_0; lwz 0,0x88(31); b 4f; 3:; lwz 9,0x90(31); lwz 0,0x0(9); 4:; stw 0,0x90(31); mr. 11,0; beq 5f; lwz 9,0xc(30); lwz 0,0xc(11); rlwinm 9,9,8,25,30; rlwinm 0,0,8,25,30; cmpw 9,0; bge 3b; cmpwi 11,0; bne 6f; 5:; lwz 0,0x8c(31); stw 0,0x4(30); lwz 9,0x8c(31); stw 30,0x0(9); stw 30,0x8c(31); b 7f; 6:; stw 11,0x4(30); lwz 0,0x0(11); stw 0,0x0(30); stw 30,0x0(11); 7:; mr 3,31; bl _s80365670_1; 8:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80365670_0();
extern "C" void _s80365670_1();
extern "C" void f_80365670() {}
