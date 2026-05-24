// 0x802C6428 EFile::Fprintf(char (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1176(1); mfspr 0,8; stmw 30,0x490(1); stw 0,0x49c(1); lis 12,512; addi 0,1,1184; addi 11,1,8; stw 0,0x84(1); stw 11,0x88(1); mr 30,3; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 12,0x80(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; addi 11,1,128; addi 9,1,112; lwz 10,0x8(11); addi 31,1,144; lwz 0,0x4(11); mr 5,9; stw 12,0x70(1); mr 3,31; stw 0,0x4(9); stw 10,0x8(9); bl _s802C6428_0; mr. 3,3; ble 1f; lwz 9,0x28(30); mr 5,3; mr 4,31; lha 3,0x20(9); lwz 0,0x24(9); add 3,30,3; mtspr 8,0; blrl; 1:; lwz 0,0x49c(1); mtspr 8,0; lmw 30,0x490(1); addi 1,1,1176"

extern "C" void _s802C6428_0();

struct EFile {
    void Fprintf();
};

void EFile::Fprintf() {
}
