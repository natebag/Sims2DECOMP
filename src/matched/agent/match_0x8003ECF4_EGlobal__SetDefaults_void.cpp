// 0x8003ECF4 EGlobal::SetDefaults(void) (984 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 27,0x13c(1); stw 0,0x154(1); lis 9,-32707; mr 31,3; lfs f0,0x24fc(9); li 30,0; stw 30,0xd0(31); stw 30,0xa0(31); stw 30,0xbc(31); stw 30,0xc0(31); stw 30,0xd4(31); stw 30,0xd8(31); stw 30,0xdc(31); stfs f0,0xa8(31); stw 30,0x8(1); stfs f0,0xa4(31); bl _s8003ECF4_0; lwz 0,0xf0(31); stw 30,0xc8(31); cmpwi 0,0; bne 0f; lis 3,-32692; lis 4,6561; li 5,0; li 6,0; ori 4,4,28461; addi 3,3,-20832; bl _s8003ECF4_1; mr 0,3; lis 4,-32707; addi 4,4,9436; stw 0,0xf0(31); bl _s8003ECF4_2; lwz 0,0x4(3); lis 4,-32707; lwz 3,0xf0(31); addi 4,4,9444; stw 0,0xd8(31); bl _s8003ECF4_3; lwz 0,0x4(3); lis 4,-32707; lwz 3,0xf0(31); addi 4,4,9456; stw 0,0xd4(31); bl _s8003ECF4_4; lwz 0,0x4(3); stw 0,0xdc(31); 0:; lwz 0,0xec(31); cmpwi 0,0; bne 1f; lis 3,-32692; lis 4,3123; addi 3,3,-20832; ori 4,4,56129; li 5,0; li 6,0; bl _s8003ECF4_5; stw 3,0xec(31); 1:; lwz 0,0xf4(31); cmpwi 0,0; bne 2f; lis 3,-32692; lis 4,3123; addi 3,3,-20832; ori 4,4,56129; li 5,0; li 6,0; bl _s8003ECF4_6; stw 3,0xf4(31); 2:; lwz 0,0xf8(31); cmpwi 0,0; bne 3f; lis 3,-32692; lis 4,-14144; addi 3,3,-20832; ori 4,4,40596; li 5,0; li 6,0; bl _s8003ECF4_7; stw 3,0xf8(31); 3:; lwz 0,0x100(31); cmpwi 0,0; bne 4f; lis 3,-32692; lis 4,-5623; addi 3,3,-17444; ori 4,4,388; li 5,0; li 6,0; bl _s8003ECF4_8; stw 3,0x100(31); 4:; lwz 0,0x108(31); cmpwi 0,0; bne 5f; lis 3,-32697; addi 3,3,24012; bl _s8003ECF4_9; mr 4,3; li 5,0; lis 3,-32692; li 6,0; addi 3,3,-30916; bl _s8003ECF4_10; stw 3,0x108(31); 5:; lwz 0,-32424(13); cmpwi 0,0; bne 6f; lis 3,-32692; lis 4,14777; addi 3,3,-17444; ori 4,4,45759; li 5,0; li 6,0; bl _s8003ECF4_11; stw 3,-32424(13); 6:; lwz 0,0x10c(31); cmpwi 0,0; bne 7f; li 3,12; bl _s8003ECF4_12; bl _s8003ECF4_13; stw 3,0x10c(31); 7:; addi 29,31,280; li 30,0; li 28,2; 8:; lwzx 0,30,29; cmpwi 0,0; bne 9f; bl _s8003ECF4_14; li 7,0; li 4,816; li 5,16; li 6,0; bl _s8003ECF4_15; bl _s8003ECF4_16; stwx 3,30,29; 9:; addi 30,30,4; addic. 28,28,-1; bne 8b; lwz 0,0x120(31); cmpwi 0,0; bne 10f; li 3,28; bl _s8003ECF4_17; bl _s8003ECF4_18; stw 3,0x120(31); 10:; li 3,144; bl _s8003ECF4_19; bl _s8003ECF4_20; mr 0,3; stw 0,0x110(31); bl _s8003ECF4_21; lwz 3,0x110(31); li 4,0; bl _s8003ECF4_22; lwz 3,0x110(31); li 4,1; bl _s8003ECF4_23; stw 28,0x160(31); bl _s8003ECF4_24; lwz 3,-32060(13); stw 28,0x454(31); stw 28,0x450(31); bl _s8003ECF4_25; lis 9,-32697; addi 9,9,24012; stw 9,-21432(13); bl _s8003ECF4_26; bl _s8003ECF4_27; mr 3,31; bl _s8003ECF4_28; lis 9,-32697; addi 27,9,23428; lwz 0,0x78(27); cmpwi 0,0; bne 14f; li 3,1620; li 29,3; bl _s8003ECF4_29; mr 28,3; mr 30,28; 11:; mr 3,30; bl _s8003ECF4_30; addi 30,30,392; cmpwi 29,0; addi 29,29,-1; bne 11b; li 7,4; li 0,0; mtspr 9,7; stw 0,0x650(28); addi 8,28,1568; addi 10,28,1584; addi 11,28,1600; li 9,0; 12:; stwx 0,9,8; stwx 0,9,10; stwx 0,9,11; addi 9,9,4; bdnz 12b; stw 28,0x78(27); lis 9,-32697; addi 28,9,23428; li 3,520; lwz 29,0x78(28); bl _s8003ECF4_31; mr 30,3; li 5,256; addi 4,30,8; bl _s8003ECF4_32; stw 30,0x650(29); lwz 0,0x418(31); cmpwi 0,0; beq 14f; addi 30,1,16; lwz 29,0x78(28); mr 3,30; li 4,1; bl _s8003ECF4_33; addi 9,29,20; li 11,288; 13:; lwz 0,0x0(30); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(30); stw 0,0x4(9); lwz 0,0x8(30); stw 0,0x8(9); lwz 0,0xc(30); stw 0,0xc(9); lwz 0,0x10(30); stw 0,0x10(9); lwz 0,0x14(30); addi 30,30,24; stw 0,0x14(9); addi 9,9,24; bne 13b; lwz 0,0x0(30); stw 0,0x0(9); 14:; lwz 0,0x154(1); mtspr 8,0; lmw 27,0x13c(1); addi 1,1,336"
extern "C" void _s8003ECF4_0();
extern "C" void _s8003ECF4_1();
extern "C" void _s8003ECF4_2();
extern "C" void _s8003ECF4_3();
extern "C" void _s8003ECF4_4();
extern "C" void _s8003ECF4_5();
extern "C" void _s8003ECF4_6();
extern "C" void _s8003ECF4_7();
extern "C" void _s8003ECF4_8();
extern "C" void _s8003ECF4_9();
extern "C" void _s8003ECF4_10();
extern "C" void _s8003ECF4_11();
extern "C" void _s8003ECF4_12();
extern "C" void _s8003ECF4_13();
extern "C" void _s8003ECF4_14();
extern "C" void _s8003ECF4_15();
extern "C" void _s8003ECF4_16();
extern "C" void _s8003ECF4_17();
extern "C" void _s8003ECF4_18();
extern "C" void _s8003ECF4_19();
extern "C" void _s8003ECF4_20();
extern "C" void _s8003ECF4_21();
extern "C" void _s8003ECF4_22();
extern "C" void _s8003ECF4_23();
extern "C" void _s8003ECF4_24();
extern "C" void _s8003ECF4_25();
extern "C" void _s8003ECF4_26();
extern "C" void _s8003ECF4_27();
extern "C" void _s8003ECF4_28();
extern "C" void _s8003ECF4_29();
extern "C" void _s8003ECF4_30();
extern "C" void _s8003ECF4_31();
extern "C" void _s8003ECF4_32();
extern "C" void _s8003ECF4_33();
extern "C" void f_8003ECF4() {}
