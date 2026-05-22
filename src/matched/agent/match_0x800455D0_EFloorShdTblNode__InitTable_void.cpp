// 0x800455D0 EFloorShdTblNode::InitTable(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 0,-32500(13); cmpwi 0,0; bne 5f; lis 30,-32697; li 0,1; addi 30,30,24012; stw 0,-32500(13); lwz 3,0xc8(30); li 27,0; bl _s800455D0_0; mr 4,3; mr 3,30; bl _s800455D0_1; lwz 28,0xd4(30); stw 3,-32492(13); lwz 9,0x0(28); cmpwi 9,0; beq 0f; lwz 27,-4(9); 0:; lis 3,-32693; lis 4,-32707; addi 3,3,24536; addi 4,4,11708; li 5,0; li 6,0; bl _s800455D0_2; li 30,0; cmpw 30,27; bge 4f; lis 9,-32696; lis 26,-32692; addi 29,9,-29672; li 31,0; 1:; cmpwi 30,0; bne 2f; lwz 4,-32492(13); b 3f; 2:; lwz 9,0x0(28); lwzx 11,9,31; lwz 4,0xc(11); 3:; addi 3,26,-17444; li 5,0; li 6,0; addi 30,30,1; bl _s800455D0_3; addi 31,31,4; stw 3,0x0(29); cmpw 30,27; addi 29,29,16; blt 1b; 4:; lis 3,-32693; lis 4,-32707; addi 3,3,24536; addi 4,4,11708; li 5,0; bl _s800455D0_4; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800455D0_0();
extern "C" void _s800455D0_1();
extern "C" void _s800455D0_2();
extern "C" void _s800455D0_3();
extern "C" void _s800455D0_4();
extern "C" void f_800455D0() {}
