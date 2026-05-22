// 0x801F50F4 INVTarget::PrepareObjectInfo(ObjSelector (576 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-576(1); mfspr 0,8; stmw 26,0x228(1); stw 0,0x244(1); mr 31,3; mr 27,5; mr 29,6; mr 26,7; mr. 28,4; li 3,0; beq 16f; addi 30,1,8; mr 3,31; bl _s801F50F4_0; li 4,0; li 5,512; mr 3,30; crxor 6,6,6; bl _s801F50F4_1; mr 3,28; bl _s801F50F4_2; cmpwi 29,0; bne 0f; mr 4,27; bl _s801F50F4_3; 0:; mr 4,3; mr 5,29; mr 6,30; mr 3,31; bl _s801F50F4_4; lwz 0,0x84(31); cmpwi 0,0; bne 1f; lis 9,-32704; addi 3,9,-23620; b 2f; 1:; lis 9,-32704; addi 3,9,-23604; 2:; addi 4,1,8; bl _s801F50F4_5; lwz 0,0x84(31); cmpwi 0,0; bne 3f; lis 9,-32704; addi 30,9,-23588; b 4f; 3:; lis 9,-32704; addi 30,9,-23576; 4:; lwz 0,0x84(31); cmpwi 0,0; bne 5f; lis 9,-32704; addi 29,9,-23560; b 6f; 5:; lis 9,-32704; addi 29,9,-23544; 6:; mr 3,31; mr 4,28; addi 5,1,536; addi 6,1,540; bl _s801F50F4_6; mr. 3,3; beq 11f; lwz 0,0x218(1); lis 9,-32705; addi 9,9,16952; lis 4,-32697; rlwinm 0,0,2,0,29; addi 4,4,24012; lwzx 5,9,0; addi 3,1,544; crxor 6,6,6; bl _s801F50F4_7; lwz 9,0x220(1); li 0,1; cmpwi 7,9,0; bne cr7,7f; li 0,0; 7:; cmpwi 0,0; beq 9f; li 4,0; beq cr7,8f; lwz 4,0x0(9); 8:; mr 3,30; bl _s801F50F4_8; lwz 3,0x21c(1); addi 4,1,8; bl _s801F50F4_9; b 10f; 9:; addi 4,1,8; sth 0,0x8(1); mr 3,30; bl _s801F50F4_10; 10:; mr 3,29; addi 4,1,8; bl _s801F50F4_11; b 12f; 11:; sth 3,0x8(1); addi 4,1,8; mr 3,30; bl _s801F50F4_12; mr 3,29; addi 4,1,8; bl _s801F50F4_13; 12:; mr 3,28; bl _s801F50F4_14; mr. 28,3; li 3,0; beq 16f; mr 3,28; addi 4,1,520; bl _s801F50F4_15; cmpwi 3,0; beq 15f; lwz 0,0x84(31); addi 9,13,-28688; lwz 11,0x0(31); rlwinm 0,0,2,0,29; lwz 5,0x208(1); lwzx 4,9,0; cmpwi 11,0; lwz 6,0x20c(1); lwz 7,0x210(1); beq 13f; lwz 3,0x20(31); cmpwi 3,0; beq 13f; lwz 8,0x7c(31); mr 9,26; bl _s801F50F4_16; b 14f; 13:; li 3,0; 14:; cmpwi 3,0; beq 15f; li 0,1; li 3,1; stw 0,0x3258(31); b 16f; 15:; li 3,0; 16:; lwz 0,0x244(1); mtspr 8,0; lmw 26,0x228(1); addi 1,1,576"
extern "C" void _s801F50F4_0();
extern "C" void _s801F50F4_1();
extern "C" void _s801F50F4_2();
extern "C" void _s801F50F4_3();
extern "C" void _s801F50F4_4();
extern "C" void _s801F50F4_5();
extern "C" void _s801F50F4_6();
extern "C" void _s801F50F4_7();
extern "C" void _s801F50F4_8();
extern "C" void _s801F50F4_9();
extern "C" void _s801F50F4_10();
extern "C" void _s801F50F4_11();
extern "C" void _s801F50F4_12();
extern "C" void _s801F50F4_13();
extern "C" void _s801F50F4_14();
extern "C" void _s801F50F4_15();
extern "C" void _s801F50F4_16();
extern "C" void f_801F50F4() {}
