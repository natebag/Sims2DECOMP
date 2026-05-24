// 0x800F966C ELiveMode::InitPlayerXWindow(ERC (900 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; bl _s800F966C_0; mr 31,3; mr 3,30; bl _s800F966C_1; cmpwi 31,63; bgt 0f; cmpwi 3,63; bgt 0f; cmpwi 31,0; blt 0f; cmpwi 3,0; bge 1f; 0:; li 3,0; b 2f; 1:; rlwinm 9,3,7,0,24; add 0,31,31; add 0,0,9; addi 11,29,52; lhax 3,11,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 28,5; mr 3,30; bl _s800F966C_2; mr 31,3; mr 3,30; bl _s800F966C_3; cmplwi 31,63; bgt 3f; cmplwi 3,63; bgt 3f; add 0,31,31; rlwinm 9,3,7,0,24; add 0,0,9; addi 11,29,52; sthx 28,11,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 4,0xc(4); lwz 9,0x0(30); li 5,0; lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 4,3; lha 3,0x90(9); lwz 0,0x94(9); add 3,30,3; mtspr 8,0; blrl; mr. 3,3; beq 4f; lwz 3,0x0(3); li 4,2; bl _s800F966C_4; b 5f; 4:; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; addi 0,4,-16384; cmplwi 0,15; bgt 7f; rlwinm 0,0,2,0,29; addi 9,3,8352; lwzx 3,9,0; li 0,0; cmpwi 3,0; beq 6f; lwz 0,0x4(3); 6:; mr 3,0; blr; 7:; lwz 11,0x2090(3); rlwinm 9,4,2,0,29; li 0,0; lwzx 3,11,9; cmpwi 3,0; beq 8f; lwz 0,0x4(3); 8:; mr 3,0; blr; li 0,16; li 11,0; mtspr 9,0; addi 9,3,8352; 9:; lwz 0,0x0(9); addi 9,9,4; cmpwi 0,0; beq 10f; addi 11,11,1; 10:; bdnz 9b; lwz 0,0x2090(3); lwz 3,0x2094(3); subf 3,0,3; srawi 3,3,2; add 3,3,11; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0x2058(3); mr 29,4; addi 3,3,8280; lwz 11,0x4(3); subf 0,9,11; rlwinm. 10,0,30,2,31; beq 15f; cmpwi 29,0; bne 12f; lwz 9,0x0(9); 11:; li 3,0; cmpwi 9,0; beq 16f; lwz 3,0x4(9); b 16f; 12:; mr 31,9; cmpw 31,11; beq 15f; mr 30,3; 13:; lwz 9,0x0(31); lwz 11,0x0(9); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x328(9); lwz 0,0x32c(9); add 3,10,3; mtspr 8,0; blrl; cmpw 3,29; bne 14f; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; beq 15f; lwz 9,0x0(31); b 11b; 14:; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 13b; 15:; li 3,0; 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; lwz 3,-21508(13); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); li 6,0; lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 9,0x2c(3); li 3,0; cmpwi 9,0; beqlr; lwz 3,0x4(9); blr; lwz 3,-21496(13); blr; lwz 9,0x2058(3); rlwinm 4,4,2,0,29; li 3,0; lwzx 9,9,4; cmpwi 9,0; beqlr; lwz 3,0x4(9); blr; lwz 0,0x2058(3); lwz 3,0x205c(3); subf 3,0,3; srawi 3,3,2; blr; lwz 9,0x2068(3); rlwinm 4,4,2,0,29; lwzx 3,9,4; blr; lwz 0,0x2068(3); lwz 3,0x206c(3); subf 3,0,3; srawi 3,3,2; blr; mulli 4,4,60; lwz 3,0x2078(3); add 3,3,4"

extern "C" void _s800F966C_0();
extern "C" void _s800F966C_1();
extern "C" void _s800F966C_2();
extern "C" void _s800F966C_3();
extern "C" void _s800F966C_4();

struct ELiveMode {
    void InitPlayerXWindow();
};

void ELiveMode::InitPlayerXWindow() {
}
