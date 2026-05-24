// 0x80070E64 SimModel::SetModelPart(eBodyPartS2C, (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,4; rlwinm 0,27,2,0,29; addi 9,30,104; lwzx 9,9,0; mr 28,5; li 29,0; cmpwi 9,0; beq 1f; lwz 9,0x120(9); cmpwi 9,0; beq 0f; lwz 0,0x8(9); cmpw 28,0; bne 0f; li 3,0; b 6f; 0:; li 29,1; 1:; mr 3,30; mr 4,27; bl _s80070E64_0; rlwinm 31,27,2,0,29; lwzx 0,31,30; cmpwi 28,0; ori 0,0,2; rlwinm 0,0,0,30,27; stwx 0,31,30; bne 2f; mr 3,29; b 6f; 2:; ori 0,0,16; addi 29,30,104; stwx 0,31,30; bl _s80070E64_1; li 4,800; li 5,16; li 6,0; li 7,0; bl _s80070E64_2; bl _s80070E64_3; stwx 3,29,31; cmpwi 3,0; beq 5f; mr 4,28; li 5,0; li 6,0; li 7,0; bl _s80070E64_4; lwzx 11,29,31; lwz 9,0x0(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; lwzx 9,29,31; lwz 3,0x120(9); cmpwi 3,0; beq 4f; lwz 0,0x4(3); li 9,1; cmpwi 0,0; bne 3f; li 9,0; 3:; cmpwi 9,0; beq 4f; bl _s80070E64_5; 4:; cmpwi 27,1; bne 5f; lwz 0,0x150(30); cmpwi 0,0; beq 5f; mr 3,30; bl _s80070E64_6; 5:; li 3,1; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80070E64_0();
extern "C" void _s80070E64_1();
extern "C" void _s80070E64_2();
extern "C" void _s80070E64_3();
extern "C" void _s80070E64_4();
extern "C" void _s80070E64_5();
extern "C" void _s80070E64_6();

struct SimModel {
    void SetModelPart_eBodyPartS2C();
};

void SimModel::SetModelPart_eBodyPartS2C() {
}
