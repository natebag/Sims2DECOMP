// 0x80323884 EControllerManager::GetBtnResultAllCtrl(unsigned (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 17,0xc(1); stw 0,0x4c(1); lwz 29,0x0(4); lwz 30,0x4(4); mr 18,5; mr 17,6; mr 19,7; srawi 20,30,16; srawi 21,29,16; mr 22,8; mr 23,9; li 24,0; 0:; lwz 3,-26524(13); mr 4,24; bl _s80323884_0; mr 31,3; cmpwi 17,0; beq 5f; extsh 11,29; cmpwi 11,0; blt 1f; lwzx 0,31,20; rlwinm 9,11,3,0,28; add 9,9,0; lwz 27,-8(9); lwz 28,-4(9); mr 10,28; b 2f; 1:; mr 10,30; 2:; cmpwi 11,0; extsh 9,21; blt 3f; srawi 0,27,16; add 0,0,9; b 4f; 3:; mr 0,9; 4:; mr 4,23; add 3,31,0; mtspr 8,10; blrl; mr 4,3; mr 5,18; mr 3,31; mr 6,19; bl _s80323884_1; b 10f; 5:; extsh 11,29; cmpwi 11,0; blt 6f; lwzx 0,31,20; rlwinm 9,11,3,0,28; add 9,9,0; lwz 25,-8(9); lwz 26,-4(9); mr 10,26; b 7f; 6:; mr 10,30; 7:; cmpwi 11,0; extsh 9,21; blt 8f; srawi 0,25,16; add 0,0,9; b 9f; 8:; mr 0,9; 9:; mr 4,23; add 3,31,0; mtspr 8,10; blrl; mr 4,3; mr 5,18; mr 3,31; mr 6,19; bl _s80323884_2; 10:; cmpwi 7,3,0; beq cr7,11f; cmpwi 22,0; beq 11f; stw 24,0x0(22); 11:; addi 24,24,1; cmpwi 24,3; bgt 12f; beq cr7,0b; 12:; lwz 0,0x4c(1); mtspr 8,0; lmw 17,0xc(1); addi 1,1,72"

extern "C" void _s80323884_0();
extern "C" void _s80323884_1();
extern "C" void _s80323884_2();

struct EControllerManager {
    void GetBtnResultAllCtrl();
};

void EControllerManager::GetBtnResultAllCtrl() {
}
