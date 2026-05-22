// 0x801E5DDC WXFTarget::GetLocalizable(char (952 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 29,0x144(1); stw 0,0x154(1); mr 30,4; mr 29,3; li 5,8; addi 3,1,8; bl _s801E5DDC_0; li 0,0; li 3,8192; stb 0,0x10(1); bl _s801E5DDC_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,26160; mr 4,30; bl _s801E5DDC_2; cmpwi 3,0; bne 0f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26800; addi 3,1,264; crxor 6,6,6; bl _s801E5DDC_3; lwz 9,0x108(1); b 16f; 0:; lis 3,-32705; mr 4,30; addi 3,3,26176; bl _s801E5DDC_4; cmpwi 3,0; bne 1f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26816; addi 3,1,268; crxor 6,6,6; bl _s801E5DDC_5; lwz 9,0x10c(1); b 16f; 1:; lis 4,-32705; addi 3,1,8; addi 4,4,26832; bl _s801E5DDC_6; cmpwi 3,0; bne 2f; mr 4,30; mr 3,29; bl _s801E5DDC_7; mr 30,3; mr 3,31; mr 4,30; bl _s801E5DDC_8; mr 3,30; bl _s801E5DDC_9; b 20f; 2:; lis 4,-32705; mr 3,30; addi 4,4,26328; bl _s801E5DDC_10; cmpwi 3,0; bne 3f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26844; addi 3,1,272; crxor 6,6,6; bl _s801E5DDC_11; lwz 9,0x110(1); b 16f; 3:; lis 4,-32705; mr 3,30; addi 4,4,26348; bl _s801E5DDC_12; cmpwi 3,0; bne 10f; mr 3,29; bl _s801E5DDC_13; cmpwi 3,2; beq 7f; bgt 4f; cmpwi 3,0; beq 5f; cmpwi 3,1; beq 6f; b 9f; 4:; cmpwi 3,3; beq 8f; b 9f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26868; addi 3,1,276; crxor 6,6,6; bl _s801E5DDC_14; lwz 9,0x114(1); b 16f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26884; addi 3,1,280; crxor 6,6,6; bl _s801E5DDC_15; lwz 9,0x118(1); b 16f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26900; addi 3,1,284; crxor 6,6,6; bl _s801E5DDC_16; lwz 9,0x11c(1); b 16f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26920; addi 3,1,288; crxor 6,6,6; bl _s801E5DDC_17; lwz 9,0x120(1); b 16f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26940; addi 3,1,292; crxor 6,6,6; bl _s801E5DDC_18; lwz 9,0x124(1); b 16f; 10:; lis 4,-32705; mr 3,30; addi 4,4,26372; bl _s801E5DDC_19; cmpwi 3,0; bne 20f; mr 3,29; bl _s801E5DDC_20; cmpwi 3,2; beq 14f; bgt 11f; cmpwi 3,0; beq 12f; cmpwi 3,1; beq 13f; b 18f; 11:; cmpwi 3,3; beq 15f; b 18f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26960; addi 3,1,296; crxor 6,6,6; bl _s801E5DDC_21; lwz 9,0x128(1); b 16f; 13:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,26984; addi 3,1,300; crxor 6,6,6; bl _s801E5DDC_22; lwz 9,0x12c(1); b 16f; 14:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,27004; addi 3,1,304; crxor 6,6,6; bl _s801E5DDC_23; lwz 9,0x130(1); b 16f; 15:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,27028; addi 3,1,308; crxor 6,6,6; bl _s801E5DDC_24; lwz 9,0x134(1); 16:; li 4,0; cmpwi 9,0; beq 17f; lwz 4,0x0(9); 17:; mr 3,31; bl _s801E5DDC_25; b 20f; 18:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,27052; addi 3,1,312; crxor 6,6,6; bl _s801E5DDC_26; lwz 9,0x138(1); li 4,0; cmpwi 9,0; beq 19f; lwz 4,0x0(9); 19:; mr 3,31; bl _s801E5DDC_27; 20:; mr 3,31; bl _s801E5DDC_28; mr 3,31; bl _s801E5DDC_29; mr 3,31; bl _s801E5DDC_30; mr 3,31; bl _s801E5DDC_31; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801E5DDC_32; mr 30,3; mr 4,31; bl _s801E5DDC_33; mr 3,31; bl _s801E5DDC_34; mr 3,30; lwz 0,0x154(1); mtspr 8,0; lmw 29,0x144(1); addi 1,1,336"
extern "C" void _s801E5DDC_0();
extern "C" void _s801E5DDC_1();
extern "C" void _s801E5DDC_2();
extern "C" void _s801E5DDC_3();
extern "C" void _s801E5DDC_4();
extern "C" void _s801E5DDC_5();
extern "C" void _s801E5DDC_6();
extern "C" void _s801E5DDC_7();
extern "C" void _s801E5DDC_8();
extern "C" void _s801E5DDC_9();
extern "C" void _s801E5DDC_10();
extern "C" void _s801E5DDC_11();
extern "C" void _s801E5DDC_12();
extern "C" void _s801E5DDC_13();
extern "C" void _s801E5DDC_14();
extern "C" void _s801E5DDC_15();
extern "C" void _s801E5DDC_16();
extern "C" void _s801E5DDC_17();
extern "C" void _s801E5DDC_18();
extern "C" void _s801E5DDC_19();
extern "C" void _s801E5DDC_20();
extern "C" void _s801E5DDC_21();
extern "C" void _s801E5DDC_22();
extern "C" void _s801E5DDC_23();
extern "C" void _s801E5DDC_24();
extern "C" void _s801E5DDC_25();
extern "C" void _s801E5DDC_26();
extern "C" void _s801E5DDC_27();
extern "C" void _s801E5DDC_28();
extern "C" void _s801E5DDC_29();
extern "C" void _s801E5DDC_30();
extern "C" void _s801E5DDC_31();
extern "C" void _s801E5DDC_32();
extern "C" void _s801E5DDC_33();
extern "C" void _s801E5DDC_34();
extern "C" void f_801E5DDC() {}
