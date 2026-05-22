// 0x80006800 getExternVariable(char (808 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; lbz 0,0x0(29); cmpwi 0,95; bne 16f; lis 3,-32707; mr 4,29; addi 3,3,-11448; li 31,0; bl _s80006800_0; cmpwi 3,0; bne 0f; lis 9,-32694; li 3,3; lwz 0,-16288(9); mtspr 8,0; blrl; mr 31,3; lis 4,-32707; addi 4,4,-11436; crxor 6,6,6; bl _s80006800_1; b 15f; 0:; lis 3,-32707; mr 4,29; addi 3,3,-11432; bl _s80006800_2; cmpwi 3,0; bne 1f; lis 9,-32694; li 3,8; lwz 0,-16288(9); mtspr 8,0; blrl; mr 31,3; lis 4,-32707; addi 4,4,-11424; crxor 6,6,6; bl _s80006800_3; b 15f; 1:; lis 3,-32707; mr 4,29; addi 3,3,-11416; bl _s80006800_4; cmpwi 3,0; bne 2f; lis 9,-32694; li 3,3; lwz 0,-16288(9); mtspr 8,0; blrl; mr 31,3; lis 4,-32707; addi 4,4,-11408; crxor 6,6,6; bl _s80006800_5; b 15f; 2:; lis 3,-32707; mr 4,29; addi 3,3,-11404; bl _s80006800_6; cmpwi 3,0; bne 14f; lis 11,-32694; li 3,3; lwz 0,-16288(11); lis 9,-32692; lwz 30,-17472(9); mtspr 8,0; blrl; cmpwi 30,6; mr 31,3; beq 8f; bgt 3f; cmpwi 30,4; beq 6f; bgt 7f; cmpwi 30,3; beq 5f; b 13f; 3:; cmpwi 30,15; beq 10f; bgt 4f; cmpwi 30,7; beq 9f; b 13f; 4:; cmpwi 30,18; beq 11f; cmpwi 30,20; beq 12f; b 13f; 5:; lis 4,-32707; mr 3,31; addi 4,4,-11396; crxor 6,6,6; bl _s80006800_7; b 15f; 6:; lis 4,-32707; mr 3,31; addi 4,4,-11392; crxor 6,6,6; bl _s80006800_8; b 15f; 7:; lis 4,-32707; mr 3,31; addi 4,4,-11388; crxor 6,6,6; bl _s80006800_9; b 15f; 8:; lis 4,-32707; mr 3,31; addi 4,4,-11384; crxor 6,6,6; bl _s80006800_10; b 15f; 9:; lis 4,-32707; mr 3,31; addi 4,4,-11380; crxor 6,6,6; bl _s80006800_11; b 15f; 10:; lis 4,-32707; mr 3,31; addi 4,4,-11376; crxor 6,6,6; bl _s80006800_12; b 15f; 11:; lis 4,-32707; mr 3,31; addi 4,4,-11372; crxor 6,6,6; bl _s80006800_13; b 15f; 12:; lis 4,-32707; mr 3,31; addi 4,4,-11368; crxor 6,6,6; bl _s80006800_14; b 15f; 13:; lis 4,-32707; mr 3,31; addi 4,4,-11364; crxor 6,6,6; bl _s80006800_15; b 15f; 14:; lis 3,-32707; mr 4,29; addi 3,3,-11360; bl _s80006800_16; cmpwi 3,0; bne 15f; lis 9,-32694; li 3,2; lwz 0,-16288(9); mtspr 8,0; blrl; mr 31,3; lis 4,-32707; addi 4,4,-11344; crxor 6,6,6; bl _s80006800_17; 15:; cmpwi 31,0; bne 19f; 16:; lis 9,-32697; li 31,0; addi 9,9,-768; mr 28,9; addi 30,9,36; 17:; lwz 11,0x0(30); addi 30,30,-4; cmpwi 11,0; beq 18f; lwz 9,0x80(11); mr 4,29; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; bne 19f; 18:; cmpw 30,28; bge 17b; cmpwi 31,0; bne 19f; mr 3,29; bl _s80006800_18; b 20f; 19:; mr 3,31; bl _s80006800_19; mr 30,3; mr 3,31; bl _s80006800_20; mr 3,30; 20:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80006800_0();
extern "C" void _s80006800_1();
extern "C" void _s80006800_2();
extern "C" void _s80006800_3();
extern "C" void _s80006800_4();
extern "C" void _s80006800_5();
extern "C" void _s80006800_6();
extern "C" void _s80006800_7();
extern "C" void _s80006800_8();
extern "C" void _s80006800_9();
extern "C" void _s80006800_10();
extern "C" void _s80006800_11();
extern "C" void _s80006800_12();
extern "C" void _s80006800_13();
extern "C" void _s80006800_14();
extern "C" void _s80006800_15();
extern "C" void _s80006800_16();
extern "C" void _s80006800_17();
extern "C" void _s80006800_18();
extern "C" void _s80006800_19();
extern "C" void _s80006800_20();
extern "C" void f_80006800() {}
