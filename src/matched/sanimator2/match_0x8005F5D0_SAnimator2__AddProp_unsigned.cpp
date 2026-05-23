// 0x8005F5D0 SAnimator2::AddProp(unsigned (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 28,3; mr 30,4; mr 29,5; addi 27,1,8; li 3,12; addi 31,28,360; bl _s8005F5D0_0; mr 9,3; mr 4,30; stw 30,0x0(9); lis 3,-32692; stw 9,0x8(1); addi 3,3,-27556; bl _s8005F5D0_1; lwz 9,0x8(1); stw 3,0x8(9); stw 29,0x4(9); lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 0f; stw 9,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 11f; 0:; lwz 0,0x168(28); li 9,1; stw 9,0x10(1); addi 11,1,16; subf 0,0,30; addi 9,1,12; srawi 3,0,2; stw 3,0xc(1); cmplwi 3,1; bge 1f; mr 9,11; 1:; lwz 0,0x0(9); add. 0,3,0; beq 3f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 2f; mr 3,28; bl _s8005F5D0_2; mr 29,3; b 4f; 2:; mr 3,28; bl _s8005F5D0_3; mr 29,3; b 4f; 3:; li 29,0; li 28,0; 4:; lwz 4,0x0(31); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8005F5D0_4; add 0,3,30; b 6f; 5:; mr 0,29; 6:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s8005F5D0_5; b 10f; 9:; bl _s8005F5D0_6; 10:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 11:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s8005F5D0_0();
extern "C" void _s8005F5D0_1();
extern "C" void _s8005F5D0_2();
extern "C" void _s8005F5D0_3();
extern "C" void _s8005F5D0_4();
extern "C" void _s8005F5D0_5();
extern "C" void _s8005F5D0_6();

struct SAnimator2 {
    void AddProp();
};

void SAnimator2::AddProp() {
}
