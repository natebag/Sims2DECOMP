// 0x801C0EC8 M2MTarget::OnSaveLoadFailed(void) (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 11,0x118(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x11c(31); li 11,0; stw 11,0x118(31); cmpwi 0,9; beq 2f; bgt 1f; cmpwi 0,2; beq 3f; b 11f; 1:; cmpwi 0,15; bne 11f; mr 3,31; bl _s801C0EC8_0; b 13f; 2:; li 9,255; li 0,1; stw 0,0x180(31); stw 9,0x110(31); stw 11,0x11c(31); stw 9,0x10c(31); b 13f; 3:; lwz 9,0x10c(31); cmpwi 9,1; bne 9f; lwz 0,0x158(31); cmpwi 0,5; beq 4f; stw 11,0x10c(31); b 5f; 4:; lwz 0,0x15c(31); cmpwi 0,5; beq 7f; stw 9,0x10c(31); 5:; li 3,360; bl _s801C0EC8_1; mr 30,3; mr 3,31; bl _s801C0EC8_2; mr 5,3; mr 4,31; mr 3,30; li 6,406; bl _s801C0EC8_3; mr. 3,3; li 0,0; beq 6f; addi 0,3,268; 6:; stw 0,0x118(31); b 8f; 7:; li 0,3; mr 3,31; stw 0,0x11c(31); bl _s801C0EC8_4; 8:; lis 3,-32705; lwz 4,0x10c(31); addi 3,3,8636; bl _s801C0EC8_5; b 13f; 9:; li 0,1; li 9,-1; lis 3,-32705; stw 0,0x10c(31); stw 9,0x110(31); addi 3,3,8636; li 4,1; bl _s801C0EC8_6; lwz 0,0x118(31); cmpwi 0,0; bne 13f; li 3,360; bl _s801C0EC8_7; mr 30,3; mr 3,31; bl _s801C0EC8_8; mr 5,3; mr 4,31; mr 3,30; li 6,250; bl _s801C0EC8_9; mr. 3,3; li 0,0; beq 10f; addi 0,3,268; 10:; stw 0,0x118(31); b 13f; 11:; lwz 9,0x11c(31); li 0,255; stw 0,0x110(31); cmpwi 9,10; stw 0,0x10c(31); bne 12f; li 0,9; stw 0,0x11c(31); 12:; li 0,1; stw 0,0x168(31); 13:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801C0EC8_0();
extern "C" void _s801C0EC8_1();
extern "C" void _s801C0EC8_2();
extern "C" void _s801C0EC8_3();
extern "C" void _s801C0EC8_4();
extern "C" void _s801C0EC8_5();
extern "C" void _s801C0EC8_6();
extern "C" void _s801C0EC8_7();
extern "C" void _s801C0EC8_8();
extern "C" void _s801C0EC8_9();

struct M2MTarget {
    void OnSaveLoadFailed();
};

void M2MTarget::OnSaveLoadFailed() {
}
