// 0x80043590 HoodManager::RemoveAllObjects(int) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); addi 4,3,1; li 28,0; lwz 3,-32056(13); bl _s80043590_0; lis 3,1; ori 3,3,24584; bl _s80043590_1; bl _s80043590_2; mr 31,3; lwz 4,-32056(13); bl _s80043590_3; addis 30,31,1; lwz 0,0x6004(30); cmpw 28,0; bge 4f; li 27,1; li 29,0; 0:; addi 9,30,-32744; lwzx 9,9,29; addis 30,31,1; cmpwi 9,0; beq 3f; lwz 9,0x38(9); cmpwi 9,0; beq 3f; lha 9,0x12(9); cmpwi 9,9; beq 2f; bgt 1f; cmpwi 9,7; bgt 3f; cmpwi 9,1; blt 3f; b 2f; 1:; cmpwi 9,15; beq 2f; cmpwi 9,34; bne 3f; 2:; addis 30,31,1; addi 9,30,-32744; lwzx 11,9,29; lwz 10,0x38(11); lwz 3,0x1c(10); bl _s80043590_4; cmpwi 3,0; beq 3f; addi 9,30,-32740; stwx 27,9,29; 3:; lwz 0,0x6004(30); addi 28,28,1; addi 29,29,28; cmpw 28,0; blt 0b; 4:; lwz 4,-32056(13); mr 3,31; lwz 5,-32040(13); bl _s80043590_5; cmpwi 31,0; beq 5f; mr 3,31; li 4,3; bl _s80043590_6; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80043590_0();
extern "C" void _s80043590_1();
extern "C" void _s80043590_2();
extern "C" void _s80043590_3();
extern "C" void _s80043590_4();
extern "C" void _s80043590_5();
extern "C" void _s80043590_6();
extern "C" void f_80043590() {}
