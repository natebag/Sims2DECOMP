// 0x801E6570 WXFTarget::UpdateShaders(void) (1556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; lwz 0,0x8c(31); cmpwi 0,0; bne 1f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27076; cmpwi 0,0; beq 0f; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; lis 5,-2989; lwz 6,0x7c(31); ori 5,5,57060; li 7,0; bl _s801E6570_0; 0:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27092; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lis 5,-15404; lwz 6,0x7c(31); ori 5,5,4322; b 3f; 1:; cmpwi 0,1; bne 5f; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27076; cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lis 5,19504; lwz 6,0x7c(31); ori 5,5,55612; li 7,0; bl _s801E6570_1; 2:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27092; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lis 5,-12773; lwz 6,0x7c(31); ori 5,5,35895; 3:; li 7,0; bl _s801E6570_2; 4:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27108; cmpwi 0,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lis 5,7973; lwz 6,0x7c(31); ori 5,5,45297; li 7,0; bl _s801E6570_3; b 8f; 5:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27076; cmpwi 0,0; beq 6f; lwz 3,0x1c(31); cmpwi 3,0; beq 6f; lis 5,19504; lwz 6,0x7c(31); ori 5,5,55612; li 7,0; bl _s801E6570_4; 6:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27092; cmpwi 0,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lis 5,-15404; lwz 6,0x7c(31); ori 5,5,4322; li 7,0; bl _s801E6570_5; 7:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,27108; cmpwi 0,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lis 5,-19258; lwz 6,0x7c(31); ori 5,5,61345; li 7,0; bl _s801E6570_6; 8:; lwz 0,0x94(31); lis 9,-32697; addi 9,9,24012; lwz 29,-21476(13); rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 11,9,0; lwz 30,0x0(29); lwz 9,0x4(11); lha 0,0xb8(30); lha 3,0x1b0(9); addi 30,30,184; lwz 9,0x1b4(9); add 29,29,0; add 3,11,3; mtspr 8,9; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 28,3; lwz 30,0x198(28); mr 3,30; bl _s801E6570_7; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_8; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_9; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26424; cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_10; 9:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26436; cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_11; 10:; addi 9,28,408; lwz 30,0x4(9); mr 27,9; mr 3,30; bl _s801E6570_12; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_13; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_14; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26448; cmpwi 0,0; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_15; 11:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26460; cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_16; 12:; lwz 30,0x8(27); mr 3,30; bl _s801E6570_17; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_18; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_19; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26472; cmpwi 0,0; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_20; 13:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26484; cmpwi 0,0; beq 14f; lwz 3,0x1c(31); cmpwi 3,0; beq 14f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_21; 14:; lwz 30,0xc(27); mr 3,30; bl _s801E6570_22; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_23; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_24; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26496; cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_25; 15:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26508; cmpwi 0,0; beq 16f; lwz 3,0x1c(31); cmpwi 3,0; beq 16f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_26; 16:; lwz 30,0x10(27); mr 3,30; bl _s801E6570_27; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_28; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_29; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26520; cmpwi 0,0; beq 17f; lwz 3,0x1c(31); cmpwi 3,0; beq 17f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_30; 17:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26540; cmpwi 0,0; beq 18f; lwz 3,0x1c(31); cmpwi 3,0; beq 18f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_31; 18:; lwz 30,0x14(27); mr 3,30; bl _s801E6570_32; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_33; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_34; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26560; cmpwi 0,0; beq 19f; lwz 3,0x1c(31); cmpwi 3,0; beq 19f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_35; 19:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26580; cmpwi 0,0; beq 20f; lwz 3,0x1c(31); cmpwi 3,0; beq 20f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_36; 20:; lwz 30,0x18(27); mr 3,30; bl _s801E6570_37; mr 29,3; mr 4,28; mr 3,30; bl _s801E6570_38; mr 30,3; mr 4,29; mr 3,31; bl _s801E6570_39; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,26600; cmpwi 0,0; beq 21f; lwz 3,0x1c(31); cmpwi 3,0; beq 21f; lwz 6,0x7c(31); li 7,0; bl _s801E6570_40; 21:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,26620; cmpwi 0,0; beq 22f; lwz 3,0x1c(31); cmpwi 3,0; beq 22f; lwz 6,0x7c(31); mr 5,30; li 7,0; bl _s801E6570_41; 22:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801E6570_0();
extern "C" void _s801E6570_1();
extern "C" void _s801E6570_2();
extern "C" void _s801E6570_3();
extern "C" void _s801E6570_4();
extern "C" void _s801E6570_5();
extern "C" void _s801E6570_6();
extern "C" void _s801E6570_7();
extern "C" void _s801E6570_8();
extern "C" void _s801E6570_9();
extern "C" void _s801E6570_10();
extern "C" void _s801E6570_11();
extern "C" void _s801E6570_12();
extern "C" void _s801E6570_13();
extern "C" void _s801E6570_14();
extern "C" void _s801E6570_15();
extern "C" void _s801E6570_16();
extern "C" void _s801E6570_17();
extern "C" void _s801E6570_18();
extern "C" void _s801E6570_19();
extern "C" void _s801E6570_20();
extern "C" void _s801E6570_21();
extern "C" void _s801E6570_22();
extern "C" void _s801E6570_23();
extern "C" void _s801E6570_24();
extern "C" void _s801E6570_25();
extern "C" void _s801E6570_26();
extern "C" void _s801E6570_27();
extern "C" void _s801E6570_28();
extern "C" void _s801E6570_29();
extern "C" void _s801E6570_30();
extern "C" void _s801E6570_31();
extern "C" void _s801E6570_32();
extern "C" void _s801E6570_33();
extern "C" void _s801E6570_34();
extern "C" void _s801E6570_35();
extern "C" void _s801E6570_36();
extern "C" void _s801E6570_37();
extern "C" void _s801E6570_38();
extern "C" void _s801E6570_39();
extern "C" void _s801E6570_40();
extern "C" void _s801E6570_41();

struct WXFTarget {
    void UpdateShaders();
};

void WXFTarget::UpdateShaders() {
}
