// 0x8002EC60 ERoom::ProcStandardWalls(bool, (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-216(1); mfspr 0,8; mfcr 12; stmw 14,0x90(1); stw 0,0xdc(1); stw 12,0x8c(1); cmpwi 4,0; mr 18,3; mfcr 0; rlwinm 0,0,3,31,31; mr 15,5; stw 0,0x80(1); mcrf cr3,cr0; addi 3,1,24; mr 16,6; mr 20,7; li 4,0; li 5,8; lwz 26,-21488(13); crxor 6,6,6; bl _s8002EC60_0; li 30,8; addi 0,18,40; li 9,1; stw 0,0x18(1); addi 3,1,32; stw 9,0x1c(1); li 4,0; li 5,8; li 31,0; crxor 6,6,6; bl _s8002EC60_1; addi 0,18,16; li 9,4; stw 0,0x20(1); li 4,0; stw 9,0x24(1); li 5,8; addi 3,1,40; crxor 6,6,6; bl _s8002EC60_2; addi 0,18,28; li 9,2; stw 0,0x28(1); addi 3,1,48; stw 9,0x2c(1); li 4,0; li 5,8; crxor 6,6,6; bl _s8002EC60_3; addi 0,18,4; li 9,0; stw 0,0x30(1); stw 30,0x34(1); stw 9,0x38(1); 0:; lwz 9,0x0(26); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,26,3; blrl; lwz 9,0x0(26); mr 24,3; lha 3,0x38(9); lwz 0,0x3c(9); add 3,26,3; mtspr 8,0; blrl; mr 25,3; bne cr3,1f; mr 0,24; mr 24,25; mr 25,0; 1:; li 28,0; addi 17,31,1; cmpw 28,24; bge 9f; lwz 11,0x80(1); rlwinm 9,31,3,0,28; li 14,0; cmpwi 4,20,0; rlwinm 0,11,4,0,27; add 23,9,0; 2:; addi 9,1,28; addi 11,1,24; lwzx 27,9,23; li 29,0; lwzx 21,11,23; addi 19,28,1; mr 3,27; bl _s8002EC60_4; mr 22,3; cmpw 29,25; bge 6f; addi 30,1,64; addi 31,1,72; 3:; mr 3,30; li 4,0; li 5,0; li 6,1; bl _s8002EC60_5; beq cr3,4f; mr 3,30; mr 4,28; mr 5,29; li 6,1; bl _s8002EC60_6; b 5f; 4:; mr 3,30; mr 4,29; mr 5,28; li 6,1; bl _s8002EC60_7; 5:; lwz 9,0x0(26); mr 3,31; mr 5,30; addi 29,29,1; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,26,4; blrl; mr 7,27; li 8,0; mr 9,31; mr 10,22; stw 15,0x8(1); addi 5,1,56; stw 16,0xc(1); mr 6,30; stw 20,0x10(1); mr 3,18; mr 4,21; bl _s8002EC60_8; mr 3,31; li 4,2; bl _s8002EC60_9; mr 3,30; li 4,2; bl _s8002EC60_10; cmpw 29,25; blt 3b; 6:; bne cr4,8f; lwz 11,0x38(1); cmpwi 11,0; beq 7f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 7:; stw 20,0x38(1); 8:; mr 28,19; stw 14,0x38(1); cmpw 28,24; blt 2b; 9:; mr 31,17; cmpwi 31,1; ble 0b; li 0,0; stw 0,0x38(1); lwz 0,0xdc(1); lwz 12,0x8c(1); mtspr 8,0; lmw 14,0x90(1); mtcrf 24,12; addi 1,1,216"

extern "C" void _s8002EC60_0();
extern "C" void _s8002EC60_1();
extern "C" void _s8002EC60_2();
extern "C" void _s8002EC60_3();
extern "C" void _s8002EC60_4();
extern "C" void _s8002EC60_5();
extern "C" void _s8002EC60_6();
extern "C" void _s8002EC60_7();
extern "C" void _s8002EC60_8();
extern "C" void _s8002EC60_9();
extern "C" void _s8002EC60_10();

struct ERoom {
    void ProcStandardWalls();
};

void ERoom::ProcStandardWalls() {
}
