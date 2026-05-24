// 0x801AC38C E2ETarget::GetVariable(char (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801AC38C_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801AC38C_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,-3584; mr 4,31; bl _s801AC38C_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x84(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 16f; 1:; lwz 3,-30508(13); mr 4,31; bl _s801AC38C_3; cmpwi 3,0; bne 2f; lfs f1,-30444(13); b 5f; 2:; lwz 3,-30504(13); mr 4,31; bl _s801AC38C_4; cmpwi 3,0; bne 3f; lfs f1,-30436(13); b 5f; 3:; lwz 3,-30500(13); mr 4,31; bl _s801AC38C_5; cmpwi 3,0; bne 4f; lfs f1,-30440(13); b 5f; 4:; lwz 3,-30496(13); mr 4,31; bl _s801AC38C_6; cmpwi 3,0; bne 6f; lfs f1,-30432(13); 5:; lis 4,-32705; addi 4,4,-2240; mr 3,30; creqv 6,6,6; bl _s801AC38C_7; b 16f; 6:; lwz 3,-30492(13); mr 4,31; bl _s801AC38C_8; cmpwi 3,0; bne 7f; lis 9,-32705; lis 4,-32705; lfd f1,-2232(9); b 9f; 7:; lwz 3,-30488(13); mr 4,31; bl _s801AC38C_9; cmpwi 3,0; beq 8f; lwz 3,-30484(13); mr 4,31; bl _s801AC38C_10; cmpwi 3,0; beq 8f; lwz 3,-30480(13); mr 4,31; bl _s801AC38C_11; cmpwi 3,0; bne 10f; 8:; lis 9,-32705; lis 4,-32705; lfd f1,-2224(9); 9:; addi 4,4,-2240; mr 3,30; creqv 6,6,6; bl _s801AC38C_12; b 16f; 10:; lwz 3,-30476(13); mr 4,31; bl _s801AC38C_13; cmpwi 3,0; bne 11f; lis 4,-32705; lwz 5,0xb0(29); addi 4,4,-2240; b 14f; 11:; lwz 3,-30472(13); mr 4,31; bl _s801AC38C_14; cmpwi 3,0; bne 12f; lis 4,-32705; lwz 5,0xb8(29); addi 4,4,-2240; b 14f; 12:; lwz 3,-30468(13); mr 4,31; bl _s801AC38C_15; cmpwi 3,0; bne 13f; lis 4,-32705; lwz 5,0xb4(29); addi 4,4,-2240; b 14f; 13:; lwz 3,-30464(13); mr 4,31; bl _s801AC38C_16; cmpwi 3,0; bne 15f; lis 4,-32705; lwz 5,0xd8(29); addi 4,4,-8800; 14:; mr 3,30; crxor 6,6,6; bl _s801AC38C_17; b 16f; 15:; lwz 3,-30460(13); mr 4,31; bl _s801AC38C_18; cmpwi 3,0; bne 16f; lis 4,-32705; lwz 5,0xe0(29); addi 4,4,-8800; mr 3,30; crxor 6,6,6; bl _s801AC38C_19; 16:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801AC38C_0();
extern "C" void _s801AC38C_1();
extern "C" void _s801AC38C_2();
extern "C" void _s801AC38C_3();
extern "C" void _s801AC38C_4();
extern "C" void _s801AC38C_5();
extern "C" void _s801AC38C_6();
extern "C" void _s801AC38C_7();
extern "C" void _s801AC38C_8();
extern "C" void _s801AC38C_9();
extern "C" void _s801AC38C_10();
extern "C" void _s801AC38C_11();
extern "C" void _s801AC38C_12();
extern "C" void _s801AC38C_13();
extern "C" void _s801AC38C_14();
extern "C" void _s801AC38C_15();
extern "C" void _s801AC38C_16();
extern "C" void _s801AC38C_17();
extern "C" void _s801AC38C_18();
extern "C" void _s801AC38C_19();

struct E2ETarget {
    void GetVariable();
};

void E2ETarget::GetVariable() {
}
