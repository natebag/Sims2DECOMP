// 0x801ADE54 E2ETarget::GetText(char (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-528(1); mfspr 0,8; stmw 30,0x208(1); stw 0,0x214(1); mr 30,4; lis 3,-32705; addi 3,3,-3420; bl _s801ADE54_0; cmpwi 3,0; bne 0f; lis 4,-32705; addi 3,1,8; addi 4,4,-1728; bl _s801ADE54_1; b 9f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-3404; bl _s801ADE54_2; cmpwi 3,0; bne 1f; lis 4,-32705; addi 3,1,8; addi 4,4,-1700; bl _s801ADE54_3; b 9f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-3388; bl _s801ADE54_4; cmpwi 3,0; bne 2f; lis 4,-32705; addi 3,1,8; addi 4,4,-1672; bl _s801ADE54_5; b 9f; 2:; lis 3,-32705; mr 4,30; addi 3,3,-3372; bl _s801ADE54_6; cmpwi 3,0; bne 3f; lis 4,-32705; addi 3,1,8; addi 4,4,-1652; bl _s801ADE54_7; b 9f; 3:; lis 3,-32705; mr 4,30; addi 3,3,-3356; bl _s801ADE54_8; cmpwi 3,0; bne 4f; lis 4,-32705; addi 3,1,8; addi 4,4,-1620; bl _s801ADE54_9; b 9f; 4:; lis 3,-32705; mr 4,30; addi 3,3,-3340; bl _s801ADE54_10; cmpwi 3,0; bne 5f; lis 4,-32705; addi 3,1,8; addi 4,4,-1588; bl _s801ADE54_11; b 9f; 5:; lis 3,-32705; mr 4,30; addi 3,3,-3324; bl _s801ADE54_12; cmpwi 3,0; bne 6f; lis 4,-32705; addi 3,1,8; addi 4,4,-1560; bl _s801ADE54_13; b 9f; 6:; lis 3,-32705; mr 4,30; addi 3,3,-3308; bl _s801ADE54_14; cmpwi 3,0; bne 7f; lis 4,-32705; addi 3,1,8; addi 4,4,-1516; bl _s801ADE54_15; b 9f; 7:; lis 3,-32705; mr 4,30; addi 3,3,-3292; bl _s801ADE54_16; cmpwi 3,0; bne 8f; lis 4,-32705; addi 3,1,8; addi 4,4,-1476; bl _s801ADE54_17; b 9f; 8:; lis 3,-32705; mr 4,30; addi 3,3,-3276; bl _s801ADE54_18; cmpwi 3,0; bne 9f; lis 4,-32705; addi 3,1,8; addi 4,4,-1440; bl _s801ADE54_19; 9:; addi 3,1,8; bl _s801ADE54_20; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801ADE54_21; mr 30,3; addi 4,1,8; bl _s801ADE54_22; mr 3,30; lwz 0,0x214(1); mtspr 8,0; lmw 30,0x208(1); addi 1,1,528"

extern "C" void _s801ADE54_0();
extern "C" void _s801ADE54_1();
extern "C" void _s801ADE54_2();
extern "C" void _s801ADE54_3();
extern "C" void _s801ADE54_4();
extern "C" void _s801ADE54_5();
extern "C" void _s801ADE54_6();
extern "C" void _s801ADE54_7();
extern "C" void _s801ADE54_8();
extern "C" void _s801ADE54_9();
extern "C" void _s801ADE54_10();
extern "C" void _s801ADE54_11();
extern "C" void _s801ADE54_12();
extern "C" void _s801ADE54_13();
extern "C" void _s801ADE54_14();
extern "C" void _s801ADE54_15();
extern "C" void _s801ADE54_16();
extern "C" void _s801ADE54_17();
extern "C" void _s801ADE54_18();
extern "C" void _s801ADE54_19();
extern "C" void _s801ADE54_20();
extern "C" void _s801ADE54_21();
extern "C" void _s801ADE54_22();

struct E2ETarget {
    void GetText();
};

void E2ETarget::GetText() {
}
