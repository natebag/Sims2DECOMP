// 0x8019EB2C CASPersonalTarget::ParsePersonalityText(char (684 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 30,0x30(1); stw 0,0x3c(1); mr 31,4; lis 3,-32705; mr 30,5; addi 3,3,-12916; bl _s8019EB2C_0; cmpwi 3,0; bne 0f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12000; addi 3,1,8; crxor 6,6,6; bl _s8019EB2C_1; lwz 9,0x8(1); b 8f; 0:; lis 3,-32705; mr 4,31; addi 3,3,-12896; bl _s8019EB2C_2; cmpwi 3,0; bne 1f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11980; addi 3,1,12; crxor 6,6,6; bl _s8019EB2C_3; lwz 9,0xc(1); b 8f; 1:; lis 3,-32705; mr 4,31; addi 3,3,-12876; bl _s8019EB2C_4; cmpwi 3,0; bne 2f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11960; addi 3,1,16; crxor 6,6,6; bl _s8019EB2C_5; lwz 9,0x10(1); b 8f; 2:; lis 3,-32705; mr 4,31; addi 3,3,-12860; bl _s8019EB2C_6; cmpwi 3,0; bne 3f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11940; addi 3,1,20; crxor 6,6,6; bl _s8019EB2C_7; lwz 9,0x14(1); b 8f; 3:; lis 3,-32705; mr 4,31; addi 3,3,-12836; bl _s8019EB2C_8; cmpwi 3,0; bne 4f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11916; addi 3,1,24; crxor 6,6,6; bl _s8019EB2C_9; lwz 9,0x18(1); b 8f; 4:; lis 3,-32705; mr 4,31; addi 3,3,-12816; bl _s8019EB2C_10; cmpwi 3,0; bne 5f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11896; addi 3,1,28; crxor 6,6,6; bl _s8019EB2C_11; lwz 9,0x1c(1); b 8f; 5:; lis 3,-32705; mr 4,31; addi 3,3,-12796; bl _s8019EB2C_12; cmpwi 3,0; bne 6f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11876; addi 3,1,32; crxor 6,6,6; bl _s8019EB2C_13; lwz 9,0x20(1); b 8f; 6:; lis 3,-32705; mr 4,31; addi 3,3,-12776; bl _s8019EB2C_14; cmpwi 3,0; bne 7f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11852; addi 3,1,36; crxor 6,6,6; bl _s8019EB2C_15; lwz 9,0x24(1); b 8f; 7:; lis 3,-32705; mr 4,31; addi 3,3,-12756; bl _s8019EB2C_16; cmpwi 3,0; bne 10f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11828; addi 3,1,40; crxor 6,6,6; bl _s8019EB2C_17; lwz 9,0x28(1); 8:; li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,30; bl _s8019EB2C_18; b 12f; 10:; lis 3,-32705; mr 4,31; addi 3,3,-12736; bl _s8019EB2C_19; cmpwi 3,0; bne 12f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-11804; addi 3,1,44; crxor 6,6,6; bl _s8019EB2C_20; lwz 9,0x2c(1); li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; mr 3,30; bl _s8019EB2C_21; 12:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x30(1); addi 1,1,56"
extern "C" void _s8019EB2C_0();
extern "C" void _s8019EB2C_1();
extern "C" void _s8019EB2C_2();
extern "C" void _s8019EB2C_3();
extern "C" void _s8019EB2C_4();
extern "C" void _s8019EB2C_5();
extern "C" void _s8019EB2C_6();
extern "C" void _s8019EB2C_7();
extern "C" void _s8019EB2C_8();
extern "C" void _s8019EB2C_9();
extern "C" void _s8019EB2C_10();
extern "C" void _s8019EB2C_11();
extern "C" void _s8019EB2C_12();
extern "C" void _s8019EB2C_13();
extern "C" void _s8019EB2C_14();
extern "C" void _s8019EB2C_15();
extern "C" void _s8019EB2C_16();
extern "C" void _s8019EB2C_17();
extern "C" void _s8019EB2C_18();
extern "C" void _s8019EB2C_19();
extern "C" void _s8019EB2C_20();
extern "C" void _s8019EB2C_21();
extern "C" void f_8019EB2C() {}
