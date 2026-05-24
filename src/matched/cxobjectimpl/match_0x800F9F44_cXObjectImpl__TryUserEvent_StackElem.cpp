// 0x800F9F44 cXObjectImpl::TryUserEvent(StackElem (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 28,4; mr 31,3; lwz 30,0x8(28); mr 27,5; cmpwi 30,0; bne 0f; lwz 11,-21496(13); li 4,11; li 5,1; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; li 3,0; li 4,2; stw 0,0x8(28); b 12f; 0:; cmpwi 30,1; bne 11f; li 0,2; lha 4,0x4(28); stw 0,0x8(28); lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x488(9); lwz 0,0x48c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x0(31); li 0,23; stw 30,-24512(13); li 4,23; sth 0,0x34(9); lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; b 3f; 1:; lbz 0,0x4(27); li 4,7; andi. 9,0,32; beq 2f; li 4,25; 2:; lha 5,0x0(27); mr 3,31; li 6,0; li 7,0; addi 8,1,8; bl _s800F9F44_0; cmpwi 3,-1; bne 4f; cmpwi 4,-1; bne 4f; 3:; li 3,-1; li 4,-1; b 12f; 4:; addi 3,1,16; mr 26,3; bl _s800F9F44_1; lbz 0,0x4(27); xori 0,0,64; andi. 9,0,64; beq 5f; li 3,264; li 4,0; bl _s800F9F44_2; 5:; lbz 0,0x5(27); cmpwi 0,0; beq 9f; li 30,0; li 3,0; stw 30,0x18(1); bl _s800F9F44_3; stw 30,0x18(1); bl _s800F9F44_4; stw 3,0x18(1); mr 3,28; lwz 29,0x10(28); lwz 30,0x0(29); lha 0,0x30(30); addi 30,30,48; add 29,29,0; bl _s800F9F44_5; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,-1; beq 8f; lwz 11,0x18(1); mr 4,3; li 5,305; lwz 9,0x0(11); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x18(1); addi 3,1,28; lbz 5,0x5(27); lwz 9,0x0(11); lwz 0,0x8c(9); lha 4,0x88(9); mtspr 8,0; add 4,11,4; crxor 6,6,6; blrl; lwz 9,0x1c(1); li 0,0; cmpwi 7,9,0; beq cr7,6f; lwz 0,0x0(9); 6:; cmpwi 0,0; beq 8f; li 4,0; beq cr7,7f; lwz 4,0x0(9); 7:; mr 3,26; bl _s800F9F44_6; 8:; lwz 3,0x18(1); bl _s800F9F44_7; li 0,0; stw 0,0x18(1); 9:; mr 3,26; bl _s800F9F44_8; cmpwi 3,0; beq 10f; lwz 3,0x4(31); mr 5,28; mr 4,26; li 6,0; lwz 9,0x4(3); li 7,0; li 8,0; lha 0,0x108(9); lwz 9,0x10c(9); add 3,3,0; mtspr 8,9; blrl; 10:; lha 0,0x8(1); cmpwi 0,255; mr 3,26; li 4,2; bl _s800F9F44_9; li 3,0; li 4,2; b 12f; 11:; li 3,0; li 4,1; 12:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"

extern "C" void _s800F9F44_0();
extern "C" void _s800F9F44_1();
extern "C" void _s800F9F44_2();
extern "C" void _s800F9F44_3();
extern "C" void _s800F9F44_4();
extern "C" void _s800F9F44_5();
extern "C" void _s800F9F44_6();
extern "C" void _s800F9F44_7();
extern "C" void _s800F9F44_8();
extern "C" void _s800F9F44_9();

struct cXObjectImpl {
    void TryUserEvent_StackElem();
};

void cXObjectImpl::TryUserEvent_StackElem() {
}
