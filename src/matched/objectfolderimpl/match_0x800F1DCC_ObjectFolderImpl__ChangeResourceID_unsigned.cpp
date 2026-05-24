// 0x800F1DCC ObjectFolderImpl::ChangeResourceID(unsigned (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); lwz 9,0x0(3); mr 29,5; mr 28,6; mr 30,7; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 0f; lwz 9,0xc(31); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0xc(31); mr 5,29; mr 4,30; li 6,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; mr. 29,3; beq 0f; addi 30,1,8; li 5,64; addi 4,30,8; mr 3,30; bl _s800F1DCC_0; lwz 9,0xc(31); mr 4,29; mr 5,30; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc(31); mr 4,29; mr 5,28; mr 6,30; lha 3,0x118(9); li 7,0; lwz 0,0x11c(9); add 3,31,3; mtspr 8,0; blrl; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"

extern "C" void _s800F1DCC_0();

struct ObjectFolderImpl {
    void ChangeResourceID();
};

void ObjectFolderImpl::ChangeResourceID() {
}
