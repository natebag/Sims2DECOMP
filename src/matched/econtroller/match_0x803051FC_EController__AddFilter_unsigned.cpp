// 0x803051FC EController::AddFilter(unsigned (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 4,0x4(31); mr 30,6; rlwinm 4,4,31,31,31; bl _s803051FC_0; lwz 0,0x8(31); cmpwi 0,30; bgt 2f; mr 7,0; lwz 9,-26700(13); mulli 11,7,12; addi 6,31,16; addi 5,9,1; mr 29,6; stw 5,-26700(13); addi 4,31,12; addi 12,31,20; lwzx 0,6,11; cmplw 30,0; bge 1f; cmpwi 7,0; blt 1f; mr 8,11; addi 0,8,12; add 10,0,31; 0:; lwz 0,0x8(10); addi 8,8,-12; lwz 11,0x0(10); addi 7,7,-1; lwz 9,0x4(10); stw 11,0xc(10); stw 9,0x10(10); stw 0,0x14(10); addi 10,10,-12; lwzx 0,8,6; cmplw 30,0; bge 1f; cmpwi 7,0; bge 0b; 1:; addi 0,7,1; mr 3,5; mulli 0,0,12; stwx 5,4,0; stwx 28,12,0; stwx 30,29,0; lwz 9,0x8(31); addi 9,9,1; stw 9,0x8(31); b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s803051FC_0();

struct EController {
    void AddFilter();
};

void EController::AddFilter() {
}
