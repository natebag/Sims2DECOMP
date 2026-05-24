// 0x80296750 AptDate::sMethod_toString(AptValue (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lwz 30,-26892(13); mr 29,3; cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 31,30,12; mr 3,31; bl _s80296750_0; cmpwi 3,0; bne 2f; mr 3,31; li 4,0; bl _s80296750_1; 2:; mr 31,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s80296750_2; bl _s80296750_3; mr 31,3; 4:; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 3,29; addi 9,9,1; addi 30,31,12; sth 9,-6476(11); bl _s80296750_4; lwz 4,0x8(1); addi 3,1,16; addi 4,4,8; bl _s80296750_5; addi 4,1,16; mr 3,30; bl _s80296750_6; li 4,2; addi 3,1,16; bl _s80296750_7; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80296750_8; 5:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s80296750_0();
extern "C" void _s80296750_1();
extern "C" void _s80296750_2();
extern "C" void _s80296750_3();
extern "C" void _s80296750_4();
extern "C" void _s80296750_5();
extern "C" void _s80296750_6();
extern "C" void _s80296750_7();
extern "C" void _s80296750_8();

struct AptDate {
    void sMethod_toString();
};

void AptDate::sMethod_toString() {
}
