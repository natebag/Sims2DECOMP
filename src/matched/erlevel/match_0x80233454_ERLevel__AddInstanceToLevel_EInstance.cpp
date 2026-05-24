// 0x80233454 ERLevel::AddInstanceToLevel(EInstance (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; bl _s80233454_0; stw 30,0x4(31); mr 3,30; mr 4,31; bl _s80233454_1; lwz 0,0x5c(31); andis. 9,0,4; beq 0f; addis 3,30,3; mr 4,31; addi 3,3,-23900; bl _s80233454_2; stw 3,0x78(31); b 2f; 0:; andis. 9,0,1; bne 2f; lwz 0,0x10(31); cmpwi 0,0; beq 1f; mr 3,30; mr 4,31; bl _s80233454_3; b 2f; 1:; addis 11,30,3; lwz 0,-15688(11); addi 10,11,-23880; rlwinm 0,0,2,0,29; stwx 31,10,0; lwz 9,-15688(11); addi 9,9,1; stw 9,-15688(11); 2:; lwz 0,0x5c(31); andi. 9,0,256; beq 3f; lwz 9,0x0(31); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; mr 5,31; addis 3,30,3; li 6,1; addi 3,3,-23948; bl _s80233454_4; stw 3,0x34(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80233454_0();
extern "C" void _s80233454_1();
extern "C" void _s80233454_2();
extern "C" void _s80233454_3();
extern "C" void _s80233454_4();

struct ERLevel {
    void AddInstanceToLevel_EInstance();
};

void ERLevel::AddInstanceToLevel_EInstance() {
}
