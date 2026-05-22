// 0x8016A6CC CasSimDescriptionS2C::GetCompositeTextureName(char (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 28,3; mr 31,6; addi 3,1,8; mr 30,4; mr 27,3; mr 29,5; bl _s8016A6CC_0; cmpwi 31,1; beq 0f; ble 10f; cmpwi 31,2; beq 3f; cmpwi 31,3; beq 6f; b 10f; 0:; lwz 0,0x84(30); cmpwi 0,0; beq 1f; lis 9,-32706; addi 5,9,1320; b 2f; 1:; lis 9,-32706; addi 5,9,1324; 2:; lis 4,-32706; mr 6,29; addi 4,4,1308; b 9f; 3:; lwz 0,0x84(30); cmpwi 0,0; beq 4f; lis 9,-32706; addi 5,9,1320; b 5f; 4:; lis 9,-32706; addi 5,9,1324; 5:; lis 4,-32706; mr 6,29; addi 4,4,1328; b 9f; 6:; lwz 0,0x84(30); cmpwi 0,0; beq 7f; lis 9,-32706; addi 5,9,1320; b 8f; 7:; lis 9,-32706; addi 5,9,1324; 8:; lis 4,-32706; mr 6,29; addi 4,4,1340; 9:; addi 3,1,8; crxor 6,6,6; bl _s8016A6CC_1; b 13f; 10:; lwz 0,0x84(30); cmpwi 0,0; beq 11f; lis 9,-32706; addi 5,9,1320; b 12f; 11:; lis 9,-32706; addi 5,9,1324; 12:; lis 4,-32706; mr 6,29; addi 4,4,1352; addi 3,1,8; crxor 6,6,6; bl _s8016A6CC_2; 13:; mr 3,27; bl _s8016A6CC_3; mr 4,3; mr 3,28; bl _s8016A6CC_4; lwz 4,0x8(1); mr 3,27; bl _s8016A6CC_5; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8016A6CC_0();
extern "C" void _s8016A6CC_1();
extern "C" void _s8016A6CC_2();
extern "C" void _s8016A6CC_3();
extern "C" void _s8016A6CC_4();
extern "C" void _s8016A6CC_5();
extern "C" void f_8016A6CC() {}
