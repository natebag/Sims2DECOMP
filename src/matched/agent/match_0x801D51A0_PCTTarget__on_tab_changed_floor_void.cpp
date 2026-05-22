// 0x801D51A0 PCTTarget::on_tab_changed_floor(void) (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32697; mr 29,3; lwz 3,0x5e94(9); cmpwi 3,0; beq 0f; bl _s801D51A0_0; b 1f; 0:; lis 9,-32705; addi 3,9,6640; 1:; lis 30,-32697; mr 4,3; addi 3,30,24012; li 31,0; bl _s801D51A0_1; addi 30,30,24012; li 0,0; lwz 27,0xd4(30); mr 26,3; stw 0,0xc0(29); lwz 30,0x0(27); b 4f; 2:; lwz 5,0x0(30); mr 3,31; mr 4,26; bl _s801D51A0_2; cmpwi 3,0; beq 3f; lwz 9,0xc0(29); addi 9,9,1; stw 9,0xc0(29); 3:; addi 30,30,4; addi 31,31,1; 4:; lwz 0,0x0(27); li 11,0; mr 9,0; cmpwi 0,0; beq 5f; lwz 11,-4(9); 5:; rlwinm 0,11,2,0,29; add 0,9,0; cmpw 30,0; bne 2b; lwz 30,0xc0(29); cmpwi 30,0; li 3,1; beq 16f; mulli 3,30,24; addi 31,30,-1; bl _s801D51A0_3; mr 28,3; cmpwi 30,0; mr 30,28; beq 7f; 6:; mr 3,30; bl _s801D51A0_4; addi 30,30,24; cmpwi 31,0; addi 31,31,-1; bne 6b; 7:; stw 28,0xbc(29); li 31,0; li 28,0; lwz 30,0x0(27); b 10f; 8:; lwz 5,0x0(30); mr 3,31; mr 4,26; bl _s801D51A0_5; cmpwi 3,0; beq 9f; lwz 3,0xbc(29); mr 4,31; lwz 5,0x0(30); add 3,3,28; bl _s801D51A0_6; addi 28,28,24; 9:; addi 30,30,4; addi 31,31,1; 10:; lwz 0,0x0(27); li 11,0; mr 9,0; cmpwi 0,0; beq 11f; lwz 11,-4(9); 11:; rlwinm 0,11,2,0,29; add 0,9,0; cmpw 30,0; bne 8b; lwz 0,0x9c(29); li 6,0; cmpwi 0,1; beq 12f; cmpwi 0,2; beq 13f; b 14f; 12:; lis 9,-32739; addi 6,9,7540; b 14f; 13:; lis 9,-32739; addi 6,9,7232; 14:; cmpwi 6,0; beq 15f; lwz 4,0xc0(29); li 5,24; lwz 3,0xbc(29); bl _s801D51A0_7; 15:; li 3,1; 16:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801D51A0_0();
extern "C" void _s801D51A0_1();
extern "C" void _s801D51A0_2();
extern "C" void _s801D51A0_3();
extern "C" void _s801D51A0_4();
extern "C" void _s801D51A0_5();
extern "C" void _s801D51A0_6();
extern "C" void _s801D51A0_7();
extern "C" void f_801D51A0() {}
