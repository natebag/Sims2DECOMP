// 0x80272E74 AptActionInterpreter::_FunctionAptActionSubtract(AptActionInterpreter (688 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 27,0x14(1); stw 0,0x34(1); mr 29,3; li 28,0; lwz 9,0x0(29); lwz 0,0x8(29); addi 11,9,-1; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 30,-4(9); lwz 31,-4(11); bl _s80272E74_0; cmpwi 3,7; bne 1f; lwz 0,0x0(30); andis. 9,0,2048; beq 0f; lwz 0,0x0(31); andis. 9,0,2048; bne 1f; 0:; lwz 28,-22936(13); 1:; cmpwi 28,0; bne 12f; lwz 9,0x0(30); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,7; bne 2f; rlwinm 11,9,5,31,31; 2:; cmpwi 11,0; beq 7f; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,7; bne 3f; rlwinm 11,9,5,31,31; 3:; cmpwi 11,0; beq 7f; lwz 9,0xc(30); lwz 0,0xc(31); lwz 30,-26908(13); subf 31,9,0; cmpwi 30,0; beq 6f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 4f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 5f; 4:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 5:; stw 31,0xc(30); mr 28,30; b 12f; 6:; lwz 3,-23020(13); li 4,16; bl _s80272E74_1; mr 30,3; li 4,7; mr 28,30; bl _s80272E74_2; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; b 11f; 7:; mr 3,30; bl _s80272E74_3; fmr f31,f1; mr 3,31; bl _s80272E74_4; lwz 30,-26912(13); fsubs f31,f1,f31; cmpwi 30,0; beq 10f; lwz 0,0x0(30); lwz 9,0xc(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 8f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 9f; 8:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 9:; stfs f31,0xc(30); mr 28,30; b 12f; 10:; lwz 3,-23020(13); li 4,16; bl _s80272E74_5; mr 30,3; li 4,6; mr 28,30; bl _s80272E74_6; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; 11:; stw 9,0x8(30); 12:; lwz 0,0x0(29); lis 31,-32704; cmpwi 0,2; blt 14f; li 30,1; lis 27,-32704; 13:; lwz 11,0x0(29); addi 4,27,6004; lwz 8,0x8(29); addi 5,31,5812; subf 11,30,11; li 6,180; rlwinm 11,11,2,0,29; addi 30,30,1; lwzx 10,11,8; lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 30,2; ble 13b; lwz 9,0x0(29); addi 9,9,-2; stw 9,0x0(29); 14:; lwz 9,0x0(29); lis 4,-32704; lwz 10,0x8(29); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 28,11,10; addi 9,9,1; stw 9,0x0(29); addi 5,5,5812; li 6,138; lwz 9,0x8(28); lha 3,0x8(9); lwz 0,0xc(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x14(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80272E74_0();
extern "C" void _s80272E74_1();
extern "C" void _s80272E74_2();
extern "C" void _s80272E74_3();
extern "C" void _s80272E74_4();
extern "C" void _s80272E74_5();
extern "C" void _s80272E74_6();

struct AptActionInterpreter {
    void _FunctionAptActionSubtract_AptActionIn();
};

void AptActionInterpreter::_FunctionAptActionSubtract_AptActionIn() {
}
