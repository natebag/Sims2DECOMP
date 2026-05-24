// 0x80085960 WrapperPaneBase::GetVariable(char (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; addi 5,1,8; bl _s80085960_0; mr. 29,3; li 3,0; blt 3f; li 3,32; bl _s80085960_1; mr 31,3; li 0,0; stb 0,0x0(31); lbz 9,0x8(1); extsb 9,9; cmpwi 9,120; bne 0f; rlwinm 29,29,2,0,29; addi 30,30,64; lwzx 11,30,29; lwz 9,0x1c(11); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,11,3; blrl; lis 4,-32707; mr 3,31; addi 4,4,29384; creqv 6,6,6; bl _s80085960_2; lwzx 9,30,29; lwz 0,0x4(9); rlwinm 0,0,0,4,2; stw 0,0x4(9); b 2f; 0:; cmpwi 9,121; bne 1f; rlwinm 29,29,2,0,29; addi 30,30,64; lwzx 11,30,29; lwz 9,0x1c(11); lwz 0,0xe4(9); lha 3,0xe0(9); mtspr 8,0; add 3,11,3; blrl; lis 4,-32707; mr 3,31; addi 4,4,29384; creqv 6,6,6; bl _s80085960_3; lwzx 9,30,29; lwz 0,0x4(9); rlwinm 0,0,0,3,1; stw 0,0x4(9); b 2f; 1:; rlwinm 0,29,2,0,29; addi 9,30,64; lwzx 10,9,0; lwz 11,0x1c(10); lha 3,0x70(11); lwz 0,0x74(11); add 3,10,3; mtspr 8,0; blrl; lfs f1,0x0(3); lis 4,-32707; addi 4,4,29384; mr 3,31; creqv 6,6,6; bl _s80085960_4; 2:; mr 3,31; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s80085960_0();
extern "C" void _s80085960_1();
extern "C" void _s80085960_2();
extern "C" void _s80085960_3();
extern "C" void _s80085960_4();

struct WrapperPaneBase {
    void GetVariable();
};

void WrapperPaneBase::GetVariable() {
}
