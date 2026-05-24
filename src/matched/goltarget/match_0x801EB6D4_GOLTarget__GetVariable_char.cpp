// 0x801EB6D4 GOLTarget::GetVariable(char (844 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 31,4; li 3,32; bl _s801EB6D4_0; mr 30,3; li 0,0; stb 0,0x0(30); lbz 9,0x0(31); lwz 29,0x8c(28); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-29180; bl _s801EB6D4_1; cmpwi 3,0; bne 1f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 20f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-29168; li 5,15; bl _s801EB6D4_2; cmpwi 3,0; bne 3f; addi 3,31,15; bl _s801EB6D4_3; mr 4,3; mr 5,29; lwz 3,0x98(28); bl _s801EB6D4_4; cmpwi 3,0; beq 2f; lis 9,-32704; lhz 0,-30820(9); sth 0,0x0(30); b 20f; 2:; lis 9,-32704; lhz 0,-30824(9); sth 0,0x0(30); b 20f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-29152; li 5,15; bl _s801EB6D4_5; cmpwi 3,0; bne 7f; addi 3,31,15; bl _s801EB6D4_6; addi 9,3,-1; li 0,0; cmplwi 9,11; bgt 6f; addi 3,3,-10; cmplwi 3,2; bgt 4f; mr 4,29; bl _s801EB6D4_7; b 5f; 4:; mr 3,9; mr 4,29; bl _s801EB6D4_8; 5:; mr 0,3; 6:; cmpwi 0,0; bne 11f; b 12f; 7:; lis 3,-32704; mr 4,31; addi 3,3,-29136; li 5,14; bl _s801EB6D4_9; cmpwi 3,0; bne 8f; addi 3,31,14; bl _s801EB6D4_10; mr 5,29; addi 3,3,-1; li 4,14; bl _s801EB6D4_11; cmpwi 3,0; bne 11f; b 12f; 8:; lis 3,-32704; mr 4,31; addi 3,3,-29120; li 5,18; bl _s801EB6D4_12; cmpwi 3,0; bne 9f; addi 3,31,18; bl _s801EB6D4_13; addi 3,3,-1; cmplwi 3,4; ble 11f; b 12f; 9:; lis 3,-32704; mr 4,31; addi 3,3,-29100; li 5,15; bl _s801EB6D4_14; cmpwi 3,0; bne 14f; addi 3,31,15; bl _s801EB6D4_15; addi 3,3,-1; li 0,0; cmplwi 3,2; bgt 10f; addi 3,3,-1; mr 4,29; bl _s801EB6D4_16; mr 0,3; 10:; cmpwi 0,0; beq 12f; 11:; lis 9,-32704; addi 4,9,-30820; b 13f; 12:; lis 9,-32704; addi 4,9,-30824; 13:; mr 3,30; bl _s801EB6D4_17; b 20f; 14:; lis 3,-32704; mr 4,31; addi 3,3,-29084; bl _s801EB6D4_18; cmpwi 3,0; bne 15f; lis 9,-32697; rlwinm 0,29,2,0,29; addi 9,9,24012; li 4,18; b 17f; 15:; lis 3,-32704; mr 4,31; addi 3,3,-29064; bl _s801EB6D4_19; cmpwi 3,0; bne 16f; lis 9,-32697; rlwinm 0,29,2,0,29; addi 9,9,24012; li 4,17; b 17f; 16:; lis 3,-32704; mr 4,31; addi 3,3,-29044; bl _s801EB6D4_20; cmpwi 3,0; bne 18f; lis 9,-32697; rlwinm 0,29,2,0,29; addi 9,9,24012; li 4,15; 17:; addi 9,9,188; lwzx 10,9,0; lwz 11,0x4(10); lha 3,0x138(11); lwz 0,0x13c(11); add 3,10,3; mtspr 8,0; blrl; mr 5,3; lis 4,-32704; addi 4,4,-30836; mr 3,30; crxor 6,6,6; bl _s801EB6D4_21; b 20f; 18:; lis 3,-32704; mr 4,31; addi 3,3,-29024; bl _s801EB6D4_22; cmpwi 3,0; bne 20f; lis 9,-32697; lwz 9,0x5e94(9); cmpwi 9,0; beq 19f; lwz 5,0x54(9); lis 4,-32704; addi 4,4,-30836; mr 3,30; addi 5,5,-1; crxor 6,6,6; bl _s801EB6D4_23; b 20f; 19:; li 0,48; stb 9,0x1(30); stb 0,0x0(30); 20:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s801EB6D4_0();
extern "C" void _s801EB6D4_1();
extern "C" void _s801EB6D4_2();
extern "C" void _s801EB6D4_3();
extern "C" void _s801EB6D4_4();
extern "C" void _s801EB6D4_5();
extern "C" void _s801EB6D4_6();
extern "C" void _s801EB6D4_7();
extern "C" void _s801EB6D4_8();
extern "C" void _s801EB6D4_9();
extern "C" void _s801EB6D4_10();
extern "C" void _s801EB6D4_11();
extern "C" void _s801EB6D4_12();
extern "C" void _s801EB6D4_13();
extern "C" void _s801EB6D4_14();
extern "C" void _s801EB6D4_15();
extern "C" void _s801EB6D4_16();
extern "C" void _s801EB6D4_17();
extern "C" void _s801EB6D4_18();
extern "C" void _s801EB6D4_19();
extern "C" void _s801EB6D4_20();
extern "C" void _s801EB6D4_21();
extern "C" void _s801EB6D4_22();
extern "C" void _s801EB6D4_23();

struct GOLTarget {
    void GetVariable();
};

void GOLTarget::GetVariable() {
}
