// 0x8018FFE0 RepTitleSupport::GetRepTitleRaw(int, (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,5; cmplwi 4,1; ble 0f; li 4,0; 0:; lis 9,-32697; rlwinm 0,4,2,0,29; addi 27,9,24012; addi 11,27,188; lwzx 4,11,0; cmpwi 4,0; beq 4f; lwz 9,0x4(4); lwz 29,-21476(13); lha 3,0x1b0(9); lwz 9,0x1b4(9); lwz 30,0x0(29); add 3,4,3; mtspr 8,9; lha 0,0xb8(30); addi 30,30,184; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 4f; bl _s8018FFE0_0; mr 4,3; mr 3,27; bl _s8018FFE0_1; mr. 3,3; beq 4f; cmpwi 28,1; beq 1f; ble 5f; cmpwi 28,2; beq 2f; cmpwi 28,3; beq 3f; b 5f; 1:; lwz 0,0x10(3); stw 0,0x0(31); b 7f; 2:; lwz 0,0x18(3); stw 0,0x0(31); b 7f; 3:; lwz 0,0x4(3); stw 0,0x0(31); b 7f; 4:; lis 3,-32697; li 4,0; addi 3,3,24012; bl _s8018FFE0_2; mr. 3,3; beq 6f; 5:; lwz 0,0x8(3); stw 0,0x0(31); b 7f; 6:; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-17480; mr 3,31; crxor 6,6,6; bl _s8018FFE0_3; 7:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8018FFE0_0();
extern "C" void _s8018FFE0_1();
extern "C" void _s8018FFE0_2();
extern "C" void _s8018FFE0_3();
extern "C" void f_8018FFE0() {}
