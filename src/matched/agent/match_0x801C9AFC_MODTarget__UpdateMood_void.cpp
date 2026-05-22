// 0x801C9AFC MODTarget::UpdateMood(void) (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 29,0x214(1); stw 0,0x224(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 4f; lwz 0,0x88(31); cmpwi 0,0; beq 4f; lwz 9,0xa4(31); cmpwi 9,0; ble 0f; addi 0,9,-1; stw 0,0xa4(31); 0:; lwz 0,0xbc(31); cmpwi 0,2; bne 1f; lwz 9,0x9c(31); addi 9,9,1; cmpwi 9,14; stw 9,0x9c(31); ble 1f; mr 3,31; li 4,4; li 5,0; li 6,0; bl _s801C9AFC_0; 1:; lwz 11,-21496(13); li 29,0; cmpwi 11,0; beq 4f; lis 9,-32697; lwz 0,0x5e88(9); cmpwi 0,0; beq 2f; lwz 9,0x0(11); li 4,0; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-30024(13); mr 29,3; cmpw 0,29; beq 2f; addi 30,1,8; li 5,256; addi 4,30,8; mr 3,30; bl _s801C9AFC_1; mr 4,30; mr 3,29; li 5,0; bl _s801C9AFC_2; mr 3,30; bl _s801C9AFC_3; mr 4,3; lis 3,-32705; addi 3,3,-8360; bl _s801C9AFC_4; 2:; lwz 0,-30024(13); cmpw 29,0; beq 3f; lis 4,-32705; lwz 6,0x94(31); stw 29,-30024(13); addi 4,4,12620; addi 3,31,200; li 5,11; bl _s801C9AFC_5; 3:; lwz 11,0xa0(31); lis 0,26214; ori 0,0,26215; mulhw 0,11,0; srawi 10,11,31; srawi 0,0,1; subf 0,10,0; rlwinm 9,0,2,0,29; add 9,9,0; subf 9,9,11; addi 11,11,1; cmpwi 9,0; stw 11,0xa0(31); bne 4f; lis 4,-32705; lwz 6,0x94(31); addi 4,4,12688; addi 3,31,200; li 5,11; bl _s801C9AFC_6; 4:; lwz 0,0x224(1); mtspr 8,0; lmw 29,0x214(1); addi 1,1,544"
extern "C" void _s801C9AFC_0();
extern "C" void _s801C9AFC_1();
extern "C" void _s801C9AFC_2();
extern "C" void _s801C9AFC_3();
extern "C" void _s801C9AFC_4();
extern "C" void _s801C9AFC_5();
extern "C" void _s801C9AFC_6();
extern "C" void f_801C9AFC() {}
