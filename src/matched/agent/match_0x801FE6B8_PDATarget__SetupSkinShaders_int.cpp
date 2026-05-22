// 0x801FE6B8 PDATarget::SetupSkinShaders(int, (856 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 30,0x10(1); stw 0,0x1c(1); stw 12,0xc(1); mr 30,5; mr 31,3; cmplwi 30,18; bgt 13f; cmpwi 4,4,0; bne cr4,0f; lis 3,-32704; mr 4,30; addi 3,3,-20320; bl _s801FE6B8_0; b 1f; 0:; lis 3,-32704; mr 4,30; addi 3,3,-20308; bl _s801FE6B8_1; 1:; bne cr4,7f; lis 11,-32700; lwz 10,0x0(31); addi 11,11,-25092; rlwinm 0,30,5,0,26; addi 11,11,4; lis 9,-32704; addi 4,9,-20464; lwzx 5,11,0; cmpwi 10,0; mr 30,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_2; 2:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,8; addi 4,11,-20452; lwzx 5,9,30; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_3; 3:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,12; addi 4,11,-20440; lwzx 5,9,30; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_4; 4:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,16; addi 4,11,-20428; lwzx 5,9,30; cmpwi 0,0; beq 5f; lwz 3,0x1c(31); cmpwi 3,0; beq 5f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_5; 5:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,20; addi 4,11,-20416; lwzx 5,9,30; cmpwi 0,0; beq 6f; lwz 3,0x1c(31); cmpwi 3,0; beq 6f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_6; 6:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,24; addi 4,11,-20404; lwzx 5,9,30; cmpwi 0,0; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_7; b 13f; 7:; lis 11,-32700; lwz 10,0x0(31); addi 11,11,-25092; rlwinm 0,30,5,0,26; addi 11,11,4; lis 9,-32704; addi 4,9,-20392; lwzx 5,11,0; cmpwi 10,0; mr 30,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_8; 8:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,8; addi 4,11,-20380; lwzx 5,9,30; cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_9; 9:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,12; addi 4,11,-20368; lwzx 5,9,30; cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_10; 10:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,16; addi 4,11,-20356; lwzx 5,9,30; cmpwi 0,0; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_11; 11:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,20; addi 4,11,-20344; lwzx 5,9,30; cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_12; 12:; lis 9,-32700; lwz 0,0x0(31); addi 9,9,-25092; lis 11,-32704; addi 9,9,24; addi 4,11,-20332; lwzx 5,9,30; cmpwi 0,0; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s801FE6B8_13; 13:; lwz 0,0x1c(1); lwz 12,0xc(1); mtspr 8,0; lmw 30,0x10(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s801FE6B8_0();
extern "C" void _s801FE6B8_1();
extern "C" void _s801FE6B8_2();
extern "C" void _s801FE6B8_3();
extern "C" void _s801FE6B8_4();
extern "C" void _s801FE6B8_5();
extern "C" void _s801FE6B8_6();
extern "C" void _s801FE6B8_7();
extern "C" void _s801FE6B8_8();
extern "C" void _s801FE6B8_9();
extern "C" void _s801FE6B8_10();
extern "C" void _s801FE6B8_11();
extern "C" void _s801FE6B8_12();
extern "C" void _s801FE6B8_13();
extern "C" void f_801FE6B8() {}
