// 0x800ED6C0 ObjectFolderImpl::DestroySelector(ObjSelector (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 25,0xc(1); stw 0,0x2c(1); stw 12,0x8(1); mr 30,4; mr 26,3; lwz 0,0x9c(30); cmpwi 0,1; bne 0f; lwz 3,-21432(13); bl _s800ED6C0_0; 0:; lwz 11,0x3c(30); cmpwi 11,0; beq 1f; li 31,0; cmpw 31,11; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; stw 31,0x3c(30); 1:; addi 28,30,64; addi 25,30,28; cmpwi 4,30,0; li 27,0; li 31,0; li 29,4; 2:; lwzx 3,31,28; cmpwi 3,0; beq 3f; bl _s800ED6C0_1; stwx 27,31,28; 3:; addi 31,31,4; addic. 29,29,-1; bne 2b; lwz 31,0x0(30); cmpwi 31,0; beq 6f; lwz 3,0x3c(26); cmpwi 3,0; beq 5f; mr 4,31; bl _s800ED6C0_2; cmpwi 3,0; beq 5f; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 9,0xc(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 9,0xc(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 5:; li 0,0; stw 0,0x0(30); 6:; lwz 11,0xc(30); cmpwi 11,0; beq 7f; lwz 9,0x0(11); li 4,3; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0xc(30); 7:; lwz 11,0x10(30); cmpwi 11,0; beq 8f; lwz 9,0x0(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x10(30); 8:; lwz 3,0x8c(30); cmpwi 3,0; beq 9f; bl _s800ED6C0_3; li 0,0; stw 0,0x8c(30); 9:; lwz 0,0x90(30); cmpwi 0,0; beq 10f; li 0,0; stw 0,0x90(30); 10:; lwz 0,0x1c(25); cmpwi 0,0; beq 11f; mr 3,25; bl _s800ED6C0_4; 11:; lwz 0,0x14(30); cmpwi 0,0; beq 12f; li 0,0; stw 0,0x14(30); 12:; lwz 0,0x18(30); cmpwi 0,0; beq 13f; li 0,0; stw 0,0x18(30); 13:; lwz 3,0x80(30); cmpwi 3,0; beq 14f; bl _s800ED6C0_5; li 0,0; stw 0,0x80(30); 14:; lwz 11,0x64(30); li 31,0; cmpw 31,11; beq 16f; cmpwi 11,0; beq 15f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 15:; stw 31,0x64(30); 16:; lwz 3,0x84(30); cmpwi 3,0; beq 17f; li 4,3; bl _s800ED6C0_6; li 0,0; stw 0,0x84(30); 17:; lwz 3,0x88(30); cmpwi 3,0; beq 18f; li 4,3; bl _s800ED6C0_7; li 0,0; stw 0,0x88(30); 18:; mr 3,30; bl _s800ED6C0_8; beq cr4,19f; mr 3,30; li 4,3; bl _s800ED6C0_9; 19:; lwz 0,0x2c(1); lwz 12,0x8(1); mtspr 8,0; lmw 25,0xc(1); mtcrf 8,12; addi 1,1,40"

extern "C" void _s800ED6C0_0();
extern "C" void _s800ED6C0_1();
extern "C" void _s800ED6C0_2();
extern "C" void _s800ED6C0_3();
extern "C" void _s800ED6C0_4();
extern "C" void _s800ED6C0_5();
extern "C" void _s800ED6C0_6();
extern "C" void _s800ED6C0_7();
extern "C" void _s800ED6C0_8();
extern "C" void _s800ED6C0_9();

struct ObjectFolderImpl {
    void DestroySelector_ObjSelector();
};

void ObjectFolderImpl::DestroySelector_ObjSelector() {
}
