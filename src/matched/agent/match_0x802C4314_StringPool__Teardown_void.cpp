// 0x802C4314 StringPool::Teardown(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 0,-26896(13); li 29,0; mr 5,0; cmpw 29,0; bge 4f; li 26,0; 0:; lwz 9,-26900(13); li 27,0; lwzx 30,26,9; cmpwi 30,0; beq 2f; lis 28,-32702; lis 31,-32702; li 27,1; 1:; lwz 9,0x8(30); addi 4,28,-15580; addi 5,31,-15544; li 6,311; lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; lwz 30,0x10(30); blrl; mr. 30,30; bne 1b; 2:; cmpwi 27,0; beq 3f; lwz 3,-27600(13); bl _s802C4314_0; 3:; lwz 0,-26896(13); addi 29,29,1; addi 26,26,4; mr 5,0; cmpw 29,0; blt 0b; 4:; lwz 3,-23020(13); rlwinm 5,5,2,0,29; lwz 4,-26900(13); lis 28,-32700; addi 27,28,-6476; li 30,0; bl _s802C4314_1; li 29,178; li 0,0; lis 9,-32694; stw 0,-26896(13); addi 31,9,-11332; 5:; lwzx 4,30,31; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802C4314_2; 6:; lhz 9,-6476(28); addic. 29,29,-1; stwx 27,30,31; addi 9,9,1; addi 30,30,4; sth 9,-6476(28); bne 5b; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802C4314_0();
extern "C" void _s802C4314_1();
extern "C" void _s802C4314_2();
extern "C" void f_802C4314() {}
