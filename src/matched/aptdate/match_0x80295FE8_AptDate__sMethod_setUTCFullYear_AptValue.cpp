// 0x80295FE8 AptDate::sMethod_setUTCFullYear(AptValue (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr. 28,4; bgt 0f; lwz 3,-22936(13); b 6f; 0:; lis 30,-32694; lwz 9,-16032(30); addi 29,30,-16032; lwz 0,0x8(29); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s80295FE8_0; stw 3,0x5c(31); cmpwi 28,1; ble 1f; lwz 9,-16032(30); lwz 0,0x8(29); addi 9,9,-1; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s80295FE8_1; stw 3,0x58(31); 1:; cmpwi 28,2; ble 2f; lwz 9,-16032(30); lwz 0,0x8(29); addi 9,9,-2; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s80295FE8_2; stw 3,0x54(31); 2:; lwz 6,0x64(31); mr 3,31; addi 4,3,68; addi 5,3,36; neg 6,6; bl _s80295FE8_3; lwz 31,-26908(13); cmpwi 31,0; beq 5f; lwz 0,0x0(31); lwz 9,0xc(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 4:; li 0,0; mr 3,31; stw 0,0xc(31); b 6f; 5:; lwz 3,-23020(13); li 4,16; bl _s80295FE8_4; mr 30,3; li 4,7; bl _s80295FE8_5; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80295FE8_0();
extern "C" void _s80295FE8_1();
extern "C" void _s80295FE8_2();
extern "C" void _s80295FE8_3();
extern "C" void _s80295FE8_4();
extern "C" void _s80295FE8_5();

struct AptDate {
    void sMethod_setUTCFullYear();
};

void AptDate::sMethod_setUTCFullYear() {
}
