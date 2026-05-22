// 0x8034EAC0 dvd_callback(long, (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32690; mr 3,4; addi 9,9,-14028; li 11,0; cmpw 9,3; beq 1f; 0:; addi 11,11,1; addi 9,9,120; cmplwi 11,1; bgt 1f; cmpw 9,3; bne 0b; 1:; mulli 30,11,120; lis 9,-32690; addi 29,9,-14064; add 31,30,29; lbz 0,0x75(31); andi. 0,0,239; stb 0,0x75(31); lbz 9,0x75(31); andi. 0,9,8; beq 2f; lbz 0,0x75(31); addi 3,31,36; andi. 0,0,247; stb 0,0x75(31); bl _s8034EAC0_0; li 0,0; stwx 0,30,29; b 15f; 2:; bl _s8034EAC0_1; cmpwi 3,0; bne 11f; lwzx 0,30,29; cmpwi 0,2; beq 3f; cmpwi 0,5; beq 8f; b 15f; 3:; lwz 3,0x8(31); cmpwi 3,0; beq 5f; lwz 0,0x0(3); cmpwi 0,3; beq 4f; li 0,3; stwx 0,30,29; b 15f; 4:; bl _s8034EAC0_2; mr. 3,3; bne 5f; stw 3,0x8(31); 5:; lwz 3,0xc(31); cmpwi 3,0; beq 7f; lwz 0,0x0(3); cmpwi 0,3; beq 6f; li 0,3; stw 0,0x0(31); b 15f; 6:; bl _s8034EAC0_3; mr. 3,3; bne 7f; stw 3,0xc(31); 7:; mr 3,31; bl _s8034EAC0_4; mr. 0,3; bne 15f; lwz 9,0x8(31); b 13f; 8:; lbz 0,0x74(31); cmpwi 0,0; bne 9f; lwz 0,0x6c(31); mr 5,0; rlwinm 0,0,31,1,31; b 10f; 9:; lwz 5,0x6c(31); li 0,0; 10:; lwz 4,0x18(31); rlwinm 5,5,31,1,31; lwz 3,0x68(31); li 6,0; add 4,4,0; li 7,0; add 3,3,0; bl _s8034EAC0_5; b 15f; 11:; lwzx 0,30,29; cmpwi 0,5; bne 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; li 4,-904; bl _s8034EAC0_6; lwz 3,0x1c(31); li 4,0; bl _s8034EAC0_7; 12:; addi 3,31,36; bl _s8034EAC0_8; lwz 9,0x8(31); li 0,0; stw 0,0x0(31); 13:; cmpwi 9,0; beq 14f; stw 0,0xc(9); 14:; lwz 3,0xc(31); cmpwi 3,0; beq 15f; stw 0,0x8(3); 15:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8034EAC0_0();
extern "C" void _s8034EAC0_1();
extern "C" void _s8034EAC0_2();
extern "C" void _s8034EAC0_3();
extern "C" void _s8034EAC0_4();
extern "C" void _s8034EAC0_5();
extern "C" void _s8034EAC0_6();
extern "C" void _s8034EAC0_7();
extern "C" void _s8034EAC0_8();
extern "C" void f_8034EAC0() {}
