// 0x803053A8 EController::MoveFilterToTop(unsigned (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; bl _s803053A8_0; mr. 3,3; blt 2f; mulli 9,3,12; lwz 0,0x8(31); addi 11,1,8; cmpw 3,0; mr 5,11; add 9,9,31; lwz 10,0xc(9); addi 9,9,12; lwz 8,0x8(9); lwz 0,0x4(9); stw 10,0x8(1); stw 0,0x4(11); stw 8,0x8(11); bge 1f; addi 11,3,1; addi 8,31,16; mulli 10,11,12; lwz 9,0xc(1); lwzx 0,8,10; cmplw 9,0; blt 1f; add 6,10,8; 0:; mulli 9,3,12; mr 3,11; add 9,9,31; lwz 7,0x18(9); addi 11,9,24; lwz 0,0x8(11); addi 10,9,12; lwz 8,0x4(11); stw 7,0xc(9); stw 0,0x8(10); stw 8,0x4(10); lwz 0,0x8(31); cmpw 3,0; bge 1f; lwz 9,0xc(1); addi 11,3,1; lwzu 0,0xc(6); cmplw 9,0; bge 0b; 1:; mulli 9,3,12; lwz 0,0x8(1); lwz 11,0x8(5); lwz 10,0x4(5); add 9,9,31; stw 0,0xc(9); addi 9,9,12; stw 11,0x8(9); stw 10,0x4(9); 2:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"

extern "C" void _s803053A8_0();

struct EController {
    void MoveFilterToTop();
};

void EController::MoveFilterToTop() {
}
