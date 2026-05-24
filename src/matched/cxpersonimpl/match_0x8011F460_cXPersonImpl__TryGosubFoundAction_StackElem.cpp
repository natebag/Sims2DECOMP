// 0x8011F460 cXPersonImpl::TryGosubFoundAction(StackElem (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 28,0x58(1); stw 0,0x6c(1); mr 31,3; lha 0,0x4(4); cmpwi 0,0; bne 0f; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,21; lwz 11,0x0(9); li 4,21; sth 10,0x34(11); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; b 4f; 0:; lwz 11,0x0(31); lha 4,0x4(4); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x488(9); lwz 0,0x48c(9); add 3,10,3; mtspr 8,0; blrl; mr. 29,3; beq 1f; lwz 9,0x4(29); lha 3,0x360(9); lwz 0,0x364(9); add 3,29,3; mtspr 8,0; blrl; mr. 30,3; bne 2f; 1:; li 3,0; li 4,0; b 6f; 2:; lwz 3,0x0(31); li 4,20; addi 3,3,40; bl _s8011F460_0; lwz 9,0x0(30); lha 28,0x0(3); lha 3,0x88(9); lwz 0,0x8c(9); mr 4,28; add 3,30,3; mtspr 8,0; blrl; mr. 11,3; bne 3f; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,22; lwz 11,0x0(9); li 4,22; sth 10,0x34(11); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; b 4f; 3:; lwz 9,0x0(11); addi 30,1,80; lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,11,3; blrl; li 9,0; lwz 11,0x4(31); li 10,0; mr 6,3; stw 9,0x50(1); stw 10,0x54(1); mr 4,29; mr 5,30; li 7,0; lwz 9,0x4(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 5f; 4:; li 3,-1; li 4,-1; b 6f; 5:; lwz 4,0x4(31); mr 5,29; mr 6,28; li 7,2; addi 3,1,8; bl _s8011F460_1; addi 3,1,8; mr 4,30; bl _s8011F460_2; addi 4,1,8; mr 3,31; bl _s8011F460_3; addi 3,1,8; li 4,2; bl _s8011F460_4; li 3,0; li 4,3; 6:; lwz 0,0x6c(1); mtspr 8,0; lmw 28,0x58(1); addi 1,1,104"

extern "C" void _s8011F460_0();
extern "C" void _s8011F460_1();
extern "C" void _s8011F460_2();
extern "C" void _s8011F460_3();
extern "C" void _s8011F460_4();

struct cXPersonImpl {
    void TryGosubFoundAction_StackElem();
};

void cXPersonImpl::TryGosubFoundAction_StackElem() {
}
