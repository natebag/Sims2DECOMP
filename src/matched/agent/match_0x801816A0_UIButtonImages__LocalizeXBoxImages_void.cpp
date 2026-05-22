// 0x801816A0 UIButtonImages::LocalizeXBoxImages(void) (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-31492(13); cmpwi 0,0; bne 0f; bl _s801816A0_0; 0:; lwz 9,-31492(13); lwz 0,0xac(9); cmpwi 0,2; bne 9f; lwz 0,0xa8(9); cmpwi 0,0; beq 1f; lis 30,-32692; lwz 4,0x8(9); addi 3,30,-17444; bl _s801816A0_1; lwz 9,-31492(13); addi 3,30,-17444; lwz 4,0x10(9); bl _s801816A0_2; lwz 9,-31492(13); addi 3,30,-17444; lwz 4,0x2c(9); bl _s801816A0_3; lwz 9,-31492(13); addi 3,30,-17444; lwz 4,0x30(9); bl _s801816A0_4; 1:; lis 9,-32692; lwz 0,-17472(9); cmpwi 0,4; beq 4f; bgt 2f; cmpwi 0,2; beq 3f; b 7f; 2:; cmpwi 0,5; beq 5f; cmpwi 0,8; beq 6f; b 7f; 3:; lwz 8,-31492(13); lis 9,-18590; lis 11,6071; lis 10,648; lis 0,-25727; ori 9,9,59896; ori 11,11,56233; ori 10,10,4795; ori 0,0,17153; b 8f; 4:; lwz 8,-31492(13); lis 9,-21064; lis 11,6071; lis 10,6226; lis 0,-25727; ori 9,9,15749; ori 11,11,56233; ori 10,10,50886; ori 0,0,17153; b 8f; 5:; lwz 8,-31492(13); lis 9,20698; lis 11,6071; lis 10,-6864; lis 0,-25727; ori 9,9,50431; ori 11,11,56233; ori 10,10,16316; ori 0,0,17153; b 8f; 6:; lwz 8,-31492(13); lis 9,-8750; lis 11,7681; lis 10,26680; lis 0,-28105; ori 9,9,51466; ori 11,11,38786; ori 10,10,12873; ori 0,0,3882; b 8f; 7:; lwz 8,-31492(13); lis 9,-20273; lis 11,9; lis 10,12780; lis 0,-13341; ori 9,9,39068; ori 11,11,47152; ori 10,10,60413; ori 0,0,54942; 8:; stw 9,0x8(8); stw 0,0x30(8); stw 11,0x10(8); stw 10,0x2c(8); lwz 9,-31492(13); lwz 0,0xa8(9); cmpwi 0,0; beq 9f; lis 30,-32692; lwz 4,0x8(9); addi 3,30,-17444; bl _s801816A0_5; lwz 9,-31492(13); addi 3,30,-17444; lwz 4,0x10(9); bl _s801816A0_6; lwz 9,-31492(13); addi 3,30,-17444; lwz 4,0x2c(9); bl _s801816A0_7; lwz 9,-31492(13); addi 3,30,-17444; lwz 4,0x30(9); bl _s801816A0_8; 9:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801816A0_0();
extern "C" void _s801816A0_1();
extern "C" void _s801816A0_2();
extern "C" void _s801816A0_3();
extern "C" void _s801816A0_4();
extern "C" void _s801816A0_5();
extern "C" void _s801816A0_6();
extern "C" void _s801816A0_7();
extern "C" void _s801816A0_8();
extern "C" void f_801816A0() {}
