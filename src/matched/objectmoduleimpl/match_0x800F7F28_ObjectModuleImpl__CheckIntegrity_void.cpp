// 0x800F7F28 ObjectModuleImpl::CheckIntegrity(void) (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 25,0x24(1); stw 0,0x44(1); stw 12,0x20(1); lwz 29,-21488(13); mr 28,3; lwz 9,0x0(29); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x0(29); lha 3,0x38(9); lwz 0,0x3c(9); add 3,29,3; mtspr 8,0; blrl; lwz 9,0x2c(28); li 31,0; cmpwi 9,0; beq 0f; lwz 31,0x4(9); 0:; cmpwi 31,0; beq 11f; lis 25,-32706; lis 26,-32706; lis 27,-32706; 1:; lwz 9,0x4(31); addi 3,1,8; cmpwi 4,31,0; lha 4,0x358(9); lwz 0,0x35c(9); add 4,31,4; mtspr 8,0; blrl; beq cr4,4f; lwz 9,0x4(31); lha 3,0x520(9); lwz 0,0x524(9); add 3,31,3; b 3f; 2:; mr 3,30; bl _s800F7F28_0; mr. 11,3; beq 4f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; 3:; mtspr 8,0; blrl; mr 30,3; b 5f; 4:; li 30,0; 5:; mr 3,30; bl _s800F7F28_1; cmpwi 3,0; bne 2b; cmpwi 30,0; beq 6f; lwz 0,0x4(30); cmpw 0,31; bne 7f; b 9f; 6:; beq cr4,9f; 7:; lwz 4,0x4(30); addi 30,1,24; lwz 9,0x4(4); mr 3,30; lha 0,0x358(9); lwz 9,0x35c(9); add 4,4,0; mtspr 8,9; blrl; mr 3,30; addi 4,1,8; bl _s800F7F28_2; cmpwi 3,0; beq 8f; addi 4,25,-17644; addi 3,13,-24588; bl _s800F7F28_3; addi 4,26,-17556; bl _s800F7F28_4; li 4,2147; bl _s800F7F28_5; addi 4,27,-17552; bl _s800F7F28_6; 8:; mr 3,30; li 4,2; bl _s800F7F28_7; b 10f; 9:; lwz 9,0x0(29); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 10f; lwz 9,0x0(28); addi 4,1,8; lwz 0,0x254(9); lha 3,0x250(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x4(31); mr 30,3; lha 3,0x328(9); lwz 0,0x32c(9); add 3,31,3; mtspr 8,0; blrl; cmpw 30,3; beq 10f; addi 4,25,-17644; addi 3,13,-24588; bl _s800F7F28_8; addi 4,26,-17556; bl _s800F7F28_9; li 4,2167; bl _s800F7F28_10; addi 4,27,-17552; bl _s800F7F28_11; 10:; addi 3,1,8; li 4,2; bl _s800F7F28_12; lwz 9,0x4(31); lha 3,0x490(9); lwz 0,0x494(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,3; bne 1b; 11:; li 3,1; lwz 0,0x44(1); lwz 12,0x20(1); mtspr 8,0; lmw 25,0x24(1); mtcrf 8,12; addi 1,1,64"

extern "C" void _s800F7F28_0();
extern "C" void _s800F7F28_1();
extern "C" void _s800F7F28_2();
extern "C" void _s800F7F28_3();
extern "C" void _s800F7F28_4();
extern "C" void _s800F7F28_5();
extern "C" void _s800F7F28_6();
extern "C" void _s800F7F28_7();
extern "C" void _s800F7F28_8();
extern "C" void _s800F7F28_9();
extern "C" void _s800F7F28_10();
extern "C" void _s800F7F28_11();
extern "C" void _s800F7F28_12();

struct ObjectModuleImpl {
    void CheckIntegrity();
};

void ObjectModuleImpl::CheckIntegrity() {
}
