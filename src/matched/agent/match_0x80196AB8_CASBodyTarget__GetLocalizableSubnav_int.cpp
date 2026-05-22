// 0x80196AB8 CASBodyTarget::GetLocalizableSubnav(int, (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stw 31,0x34(1); stw 0,0x3c(1); mr 31,5; cmpwi 4,3; beq 4f; bgt 0f; cmpwi 4,1; beq 2f; bgt 3f; cmpwi 4,0; beq 1f; b 13f; 0:; cmpwi 4,5; beq 6f; blt 5f; cmpwi 4,6; beq 8f; cmpwi 4,7; beq 11f; b 13f; 1:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15204; addi 3,1,8; crxor 6,6,6; bl _s80196AB8_0; lwz 9,0x8(1); b 9f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15184; addi 3,1,12; crxor 6,6,6; bl _s80196AB8_1; lwz 9,0xc(1); b 9f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15168; addi 3,1,16; crxor 6,6,6; bl _s80196AB8_2; lwz 9,0x10(1); b 9f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15152; addi 3,1,20; crxor 6,6,6; bl _s80196AB8_3; lwz 9,0x14(1); b 9f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15136; addi 3,1,24; crxor 6,6,6; bl _s80196AB8_4; lwz 9,0x18(1); b 9f; 6:; lis 3,-32705; addi 3,3,-16412; bl _s80196AB8_5; cmpwi 3,1; bne 7f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15120; addi 3,1,28; crxor 6,6,6; bl _s80196AB8_6; lwz 9,0x1c(1); b 9f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15100; addi 3,1,32; crxor 6,6,6; bl _s80196AB8_7; lwz 9,0x20(1); b 9f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15084; addi 3,1,36; crxor 6,6,6; bl _s80196AB8_8; lwz 9,0x24(1); 9:; li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; mr 3,31; bl _s80196AB8_9; b 13f; 11:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15072; addi 3,1,40; crxor 6,6,6; bl _s80196AB8_10; lwz 9,0x28(1); li 4,0; cmpwi 9,0; beq 12f; lwz 4,0x0(9); 12:; mr 3,31; bl _s80196AB8_11; 13:; lwz 0,0x3c(1); mtspr 8,0; lwz 31,0x34(1); addi 1,1,56"
extern "C" void _s80196AB8_0();
extern "C" void _s80196AB8_1();
extern "C" void _s80196AB8_2();
extern "C" void _s80196AB8_3();
extern "C" void _s80196AB8_4();
extern "C" void _s80196AB8_5();
extern "C" void _s80196AB8_6();
extern "C" void _s80196AB8_7();
extern "C" void _s80196AB8_8();
extern "C" void _s80196AB8_9();
extern "C" void _s80196AB8_10();
extern "C" void _s80196AB8_11();
extern "C" void f_80196AB8() {}
