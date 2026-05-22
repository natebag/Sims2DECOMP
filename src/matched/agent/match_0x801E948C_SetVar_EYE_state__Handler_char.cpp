// 0x801E948C SetVar_EYE_state::Handler(char (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 3,4; bl _s801E948C_0; mr 0,3; cmpwi 0,3; beq 3f; bgt 0f; cmpwi 0,1; beq 1f; bgt 2f; b 9f; 0:; cmpwi 0,5; beq 5f; blt 4f; cmpwi 0,6; beq 6f; cmpwi 0,7; beq 7f; b 9f; 1:; lwz 9,-28712(13); li 3,-1; stw 0,0xac(9); bl _s801E948C_1; li 3,-1; bl _s801E948C_2; bl _s801E948C_3; b 9f; 2:; lwz 3,-28712(13); li 0,2; stw 0,0xac(3); bl _s801E948C_4; b 9f; 3:; lwz 9,-28712(13); li 0,6; stw 0,0xac(9); b 9f; 4:; lwz 9,-28712(13); li 0,4; stw 0,0xac(9); b 9f; 5:; bl _s801E948C_5; lwz 9,-28712(13); li 0,3; li 3,-1; stw 0,0xac(9); bl _s801E948C_6; b 9f; 6:; bl _s801E948C_7; lwz 9,-28712(13); li 0,5; stw 0,0xac(9); b 9f; 7:; lwz 9,-28712(13); lwz 0,0xb4(9); cmpwi 0,0; beq 8f; lwz 3,0x8c(9); bl _s801E948C_8; mr 30,3; addi 5,1,8; lwz 9,0x24(30); mr 6,5; li 4,0; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; lwz 9,-28712(13); add 3,30,3; lwz 29,0xb4(9); blrl; lhz 0,0x12(30); mr 4,3; lhz 5,0x10(30); mr 3,29; mullw 5,5,0; rlwinm 5,5,1,0,30; bl _s801E948C_9; 8:; lwz 9,-28712(13); lwz 3,0x8c(9); bl _s801E948C_10; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s801E948C_0();
extern "C" void _s801E948C_1();
extern "C" void _s801E948C_2();
extern "C" void _s801E948C_3();
extern "C" void _s801E948C_4();
extern "C" void _s801E948C_5();
extern "C" void _s801E948C_6();
extern "C" void _s801E948C_7();
extern "C" void _s801E948C_8();
extern "C" void _s801E948C_9();
extern "C" void _s801E948C_10();
extern "C" void f_801E948C() {}
