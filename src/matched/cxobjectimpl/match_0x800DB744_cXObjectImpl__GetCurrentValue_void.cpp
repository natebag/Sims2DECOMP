// 0x800DB744 cXObjectImpl::GetCurrentValue(void) (528 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,0; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 11f; cmpwi 30,0; beq 0f; lwz 9,0x4(30); li 4,3; lwz 3,0x0(9); bl _s800DB744_0; mr 29,3; b 1f; 0:; li 29,0; 1:; cmpwi 29,0; bne 2f; li 3,0; b 15f; 2:; lwz 9,0x4(29); lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; mr. 11,3; bne 6f; b 7f; 3:; cmpwi 28,0; li 31,0; bne 4f; lwz 11,0x0(30); li 4,15; lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x260(9); lwz 0,0x264(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; 4:; li 31,1; 5:; lwz 3,0x4(30); mr 28,31; lwz 9,0x4(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 7f; 6:; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 8f; 7:; li 30,0; 8:; cmpwi 30,0; bne 3b; lwz 9,0x4(29); lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; mr. 11,3; beq 9f; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; b 10f; 9:; li 3,0; 10:; lwz 3,0x0(3); li 4,41; addi 3,3,40; bl _s800DB744_1; lha 31,0x0(3); b 13f; 11:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s800DB744_2; bl _s800DB744_3; cmpwi 3,0; bne 12f; li 31,0; b 13f; 12:; addi 30,30,40; li 4,41; mr 3,30; li 28,1; bl _s800DB744_4; lha 31,0x0(3); li 4,15; mr 3,30; bl _s800DB744_5; lha 0,0x0(3); cmpwi 0,0; bne 13f; li 28,0; 13:; cmpwi 28,0; beq 14f; rlwinm 0,31,1,31,31; add 0,31,0; srawi 31,0,1; 14:; mr 3,31; 15:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800DB744_0();
extern "C" void _s800DB744_1();
extern "C" void _s800DB744_2();
extern "C" void _s800DB744_3();
extern "C" void _s800DB744_4();
extern "C" void _s800DB744_5();

struct cXObjectImpl {
    void GetCurrentValue();
};

void cXObjectImpl::GetCurrentValue() {
}
