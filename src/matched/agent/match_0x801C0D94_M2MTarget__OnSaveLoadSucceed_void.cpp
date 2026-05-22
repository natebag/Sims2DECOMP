// 0x801C0D94 M2MTarget::OnSaveLoadSucceed(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x118(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x11c(31); li 11,0; stw 11,0x118(31); cmpwi 0,9; beq 8f; bgt 1f; cmpwi 0,2; beq 9f; b 10f; 1:; cmpwi 0,15; bne 10f; lis 3,-32705; li 4,1; addi 3,3,8428; bl _s801C0D94_0; lis 3,-32705; addi 3,3,-2032; bl _s801C0D94_1; cmpwi 3,4; beq 4f; bgt 2f; cmpwi 3,2; beq 3f; b 7f; 2:; cmpwi 3,7; beq 6f; b 7f; 3:; lis 3,-32705; li 4,9; b 5f; 4:; lis 3,-32705; li 4,11; 5:; addi 3,3,8412; bl _s801C0D94_2; b 7f; 6:; lwz 3,-32056(13); bl _s801C0D94_3; lis 3,-32705; li 4,0; addi 3,3,8412; bl _s801C0D94_4; 7:; mr 3,31; bl _s801C0D94_5; li 0,3; stw 0,0x168(31); b 10f; 8:; li 0,10; mr 3,31; stw 0,0x11c(31); bl _s801C0D94_6; b 10f; 9:; li 9,255; li 0,1; stw 0,0x180(31); stw 9,0x110(31); stw 11,0x11c(31); stw 9,0x10c(31); 10:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801C0D94_0();
extern "C" void _s801C0D94_1();
extern "C" void _s801C0D94_2();
extern "C" void _s801C0D94_3();
extern "C" void _s801C0D94_4();
extern "C" void _s801C0D94_5();
extern "C" void _s801C0D94_6();
extern "C" void f_801C0D94() {}
