// 0x801DDD8C RCPTarget::SetVariable(char (1116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 31,3; mr 30,4; lis 3,-32705; mr 29,5; addi 3,3,20800; bl _s801DDD8C_0; cmpwi 3,0; bne 0f; lwz 0,0x118(31); cmpwi 0,0; bne 16f; lwz 11,0x120(31); li 0,1; stw 0,0x148(31); cmpwi 11,0; beq 16f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; b 16f; 0:; lis 3,-32705; mr 4,30; addi 3,3,20732; bl _s801DDD8C_1; cmpwi 3,0; beq 16f; lis 3,-32705; mr 4,30; addi 3,3,20748; bl _s801DDD8C_2; cmpwi 3,0; bne 2f; lwz 0,0x12c(31); cmpwi 0,0; beq 16f; mr 3,29; bl _s801DDD8C_3; lwz 9,0x12c(31); cmplw 3,9; blt 1f; addi 3,9,-1; 1:; rlwinm 0,3,1,0,30; stw 3,0x130(31); add 0,0,3; stw 0,0x134(31); mr 3,31; bl _s801DDD8C_4; mr 3,31; bl _s801DDD8C_5; mr 3,31; bl _s801DDD8C_6; b 15f; 2:; lis 3,-32705; mr 4,30; addi 3,3,20764; bl _s801DDD8C_7; cmpwi 3,0; bne 4f; lwz 0,0x128(31); cmpwi 0,0; beq 16f; mr 3,29; bl _s801DDD8C_8; cmplwi 3,2; stw 3,0x138(31); ble 3f; li 0,2; stw 0,0x138(31); 3:; lwz 0,0x138(31); lwz 9,0x134(31); lwz 11,0x128(31); add 5,0,9; cmplw 5,11; bge 15f; mulli 0,5,20; lwz 9,0x124(31); add 9,0,9; lwz 11,0x8(9); cmpwi 11,0; bne 15f; lwz 0,0xc(9); cmpwi 0,0; beq 15f; lwz 11,0x13c(31); cmpwi 11,0; beq 15f; lwz 9,0x0(11); addi 5,5,1; extsh 5,5; li 4,0; lha 3,0x48(9); li 6,0; lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; b 15f; 4:; lis 3,-32705; mr 4,30; addi 3,3,20788; bl _s801DDD8C_9; cmpwi 3,0; bne 14f; lwz 0,0x134(31); lwz 9,0x138(31); lwz 11,0x128(31); add 0,0,9; cmplw 0,11; bge 16f; mulli 9,0,20; lwz 0,0x124(31); add 30,0,9; lwz 0,0x8(30); cmpwi 0,0; beq 6f; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s801DDD8C_10; bl _s801DDD8C_11; stw 3,-31536(13); 5:; lis 4,14340; lwz 3,-31536(13); ori 4,4,8607; bl _s801DDD8C_12; b 16f; 6:; stw 0,0x94(31); mr 3,30; bl _s801DDD8C_13; addi 29,31,192; addi 0,31,188; mr 4,3; mr 3,0; bl _s801DDD8C_14; mr 4,30; addi 5,31,184; mr 3,31; bl _s801DDD8C_15; li 0,1; lis 4,-32697; lis 5,-32705; addi 4,4,24012; stw 0,0x90(31); addi 5,5,-1988; stw 0,0xa4(31); addi 3,1,24; crxor 6,6,6; bl _s801DDD8C_16; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,29; bl _s801DDD8C_17; lis 9,-32705; addi 0,31,144; addi 9,9,15504; addi 4,1,32; lwz 11,0x0(9); lwz 12,0x4(9); mr 30,0; lis 9,-32708; stw 0,0x10(1); addi 29,9,-28780; stw 11,0x20(1); stw 12,0x24(1); cmpwi 0,0; beq 8f; addi 3,1,8; li 5,8; bl _s801DDD8C_18; b 9f; 8:; stw 30,0x8(1); 9:; stw 29,0x14(1); lis 9,-32705; addi 11,1,8; lwz 5,0x8(1); addi 9,9,6448; lwz 4,0x4(11); lwz 6,0x8(11); addi 10,31,224; lwz 0,0xc(11); mr 29,11; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 30,0; stw 5,0xe0(31); lis 9,-32709; stw 0,0xc(10); addi 28,9,4004; stw 4,0x4(10); addi 9,1,40; stw 6,0x8(10); stw 7,0x28(1); stw 8,0x2c(1); stw 30,0x10(1); beq 10f; mr 4,9; mr 3,29; li 5,8; bl _s801DDD8C_19; b 11f; 10:; stw 30,0x8(1); 11:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-1960; lwz 5,0x8(29); addi 11,31,240; lwz 10,0x4(29); addi 4,1,48; lwz 0,0xc(29); cmpwi 30,0; stw 6,0xf0(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,4004; stw 5,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 30,0x10(1); beq 12f; mr 3,29; li 5,8; bl _s801DDD8C_20; b 13f; 12:; stw 30,0x8(1); 13:; stw 28,0x14(1); addi 9,31,256; lwz 8,0x8(1); li 7,0; lwz 10,0xc(29); mr 3,30; lwz 0,0x4(29); lwz 11,0x8(29); stw 8,0x100(31); stw 10,0xc(9); stw 0,0x4(9); stw 11,0x8(9); stw 7,0xb4(31); bl _s801DDD8C_21; b 15f; 14:; lis 3,-32705; mr 4,30; addi 3,3,20812; bl _s801DDD8C_22; cmpwi 3,0; bne 16f; lwz 0,0x148(31); cmpwi 0,0; bne 15f; lis 5,-32705; lwz 4,0x84(31); addi 5,5,21088; addi 3,31,144; li 6,0; li 7,0; li 8,0; bl _s801DDD8C_23; 15:; lis 9,-32705; lfs f0,0x5270(9); stfs f0,0x140(31); 16:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"

extern "C" void _s801DDD8C_0();
extern "C" void _s801DDD8C_1();
extern "C" void _s801DDD8C_2();
extern "C" void _s801DDD8C_3();
extern "C" void _s801DDD8C_4();
extern "C" void _s801DDD8C_5();
extern "C" void _s801DDD8C_6();
extern "C" void _s801DDD8C_7();
extern "C" void _s801DDD8C_8();
extern "C" void _s801DDD8C_9();
extern "C" void _s801DDD8C_10();
extern "C" void _s801DDD8C_11();
extern "C" void _s801DDD8C_12();
extern "C" void _s801DDD8C_13();
extern "C" void _s801DDD8C_14();
extern "C" void _s801DDD8C_15();
extern "C" void _s801DDD8C_16();
extern "C" void _s801DDD8C_17();
extern "C" void _s801DDD8C_18();
extern "C" void _s801DDD8C_19();
extern "C" void _s801DDD8C_20();
extern "C" void _s801DDD8C_21();
extern "C" void _s801DDD8C_22();
extern "C" void _s801DDD8C_23();

struct RCPTarget {
    void SetVariable();
};

void RCPTarget::SetVariable() {
}
