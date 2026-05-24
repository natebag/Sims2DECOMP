// 0x800AC650 Behavior::Init(Language (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 30,3; lis 25,-32696; stw 5,0x4(30); stw 4,0x8(30); lwz 9,0x0(4); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,4,3; blrl; lis 9,-32696; stw 3,0xc(30); addi 10,9,24016; lwz 11,0x5dd0(9); lwz 0,0x4(10); subf 0,11,0; rlwinm. 9,0,30,2,31; bne 13f; mr 28,10; li 27,0; addi 26,1,8; 0:; li 3,104; bl _s800AC650_0; bl _s800AC650_1; lwz 9,0x0(3); stw 3,0x8(1); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; lwz 30,0x4(28); lwz 0,0xc(28); cmpw 30,0; beq 1f; lwz 0,0x8(1); addi 27,27,1; stw 0,0x0(30); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 12f; 1:; lwz 0,0x5dd0(25); li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 2f; mr 11,10; 2:; lwz 0,0x0(11); add. 0,9,0; beq 4f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 3f; mr 3,29; bl _s800AC650_2; mr 31,3; b 5f; 3:; mr 3,29; bl _s800AC650_3; mr 31,3; b 5f; 4:; li 31,0; li 29,0; 5:; lwz 4,0x0(28); cmpw 30,4; beq 6f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800AC650_4; add 0,3,30; b 7f; 6:; mr 0,31; 7:; lwz 9,0x10(1); mr 30,0; addi 27,27,1; mtspr 9,9; cmpwi 9,0; beq 9f; 8:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 8b; 9:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 11f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 10f; bl _s800AC650_5; b 11f; 10:; bl _s800AC650_6; 11:; add 0,29,31; stw 31,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 12:; cmpwi 27,2; ble 0b; 13:; lwz 9,-32124(13); addi 9,9,1; stw 9,-32124(13); lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s800AC650_0();
extern "C" void _s800AC650_1();
extern "C" void _s800AC650_2();
extern "C" void _s800AC650_3();
extern "C" void _s800AC650_4();
extern "C" void _s800AC650_5();
extern "C" void _s800AC650_6();

struct Behavior {
    void Init_Language();
};

void Behavior::Init_Language() {
}
