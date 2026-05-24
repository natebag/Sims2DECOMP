// 0x800BAEF8 cGZMusic::setVolume(int) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); lwz 7,-26564(13); mr 30,4; xoris 0,30,32768; stw 0,0x14(1); lis 11,17200; lwz 8,0x0(7); mr 31,3; stw 11,0x10(1); lis 10,-32706; lha 3,0x68(8); lwz 0,0x6c(8); lfd f31,0x10(1); add 3,7,3; lfd f0,-25280(10); mtspr 8,0; fsub f31,f31,f0; frsp f31,f31; blrl; fcmpu 0,f31,f1; beq 3f; cmpwi 30,0; bge 0f; li 0,0; stw 0,0x14(31); b 2f; 0:; cmpwi 30,1024; ble 1f; li 0,1024; stw 0,0x14(31); b 2f; 1:; stw 30,0x14(31); 2:; lwz 9,-24468(13); lwz 0,0x40c(9); cmpw 0,31; bne 3f; lwz 0,0x410(9); cmpwi 0,0; bne 3f; lwz 0,0x20(31); cmpwi 0,0; bne 3f; lwz 29,-26564(13); mr 3,31; lwz 30,0x0(29); lha 0,0x60(30); addi 30,30,96; add 29,29,0; bl _s800BAEF8_0; lwz 0,0x4(30); mr 3,29; mtspr 8,0; blrl; lwz 29,-26564(13); mr 3,31; lwz 30,0x0(29); lha 0,0x70(30); addi 30,30,112; add 29,29,0; bl _s800BAEF8_1; lwz 0,0x4(30); mr 3,29; mtspr 8,0; blrl; 3:; li 3,1; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s800BAEF8_0();
extern "C" void _s800BAEF8_1();

struct cGZMusic {
    void setVolume();
};

void cGZMusic::setVolume() {
}
