// 0x801884B4 HUDTarget::Update(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; bl _s801884B4_0; mr 3,31; li 4,0; bl _s801884B4_1; mr. 30,3; bne 2f; lbz 0,0xe8(31); cmpwi 0,2; bne 0f; mr 3,31; bl _s801884B4_2; 0:; lbz 0,0xf7(31); extsb 0,0; cmpwi 0,0; beq 4f; cmpwi 0,-4; bne 1f; mr 3,31; li 4,0; bl _s801884B4_3; 1:; lbz 9,0xf7(31); li 4,0; lbz 0,0xf5(31); stb 30,0xf5(31); stb 9,0xf6(31); stb 0,0xf4(31); stb 30,0xf7(31); lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; b 4f; 2:; lbz 0,0xe8(31); cmpwi 0,2; beq 3f; mr 3,31; bl _s801884B4_4; 3:; mr 3,31; bl _s801884B4_5; lbz 9,0x84(31); addi 9,9,-1; rlwinm 0,9,0,24,31; stb 9,0x84(31); cmpwi 0,0; bne 4f; li 0,30; mr 3,31; stb 0,0x84(31); bl _s801884B4_6; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801884B4_0();
extern "C" void _s801884B4_1();
extern "C" void _s801884B4_2();
extern "C" void _s801884B4_3();
extern "C" void _s801884B4_4();
extern "C" void _s801884B4_5();
extern "C" void _s801884B4_6();

struct HUDTarget {
    void Update();
};

void HUDTarget::Update() {
}
