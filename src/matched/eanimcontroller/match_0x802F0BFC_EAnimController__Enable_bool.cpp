// 0x802F0BFC EAnimController::Enable(bool, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 11,5; lwz 9,0x0(31); rlwinm 0,9,31,31,31; cmpw 0,4; beq 3f; cmpwi 4,0; beq 0f; ori 0,9,2; stw 0,0x0(31); b 3f; 0:; lwz 9,0x24(31); cmpwi 9,0; li 4,0; beq 1f; lwz 4,0x18(9); 1:; rlwinm 30,4,6,0,25; lwz 5,-26812(13); mr 4,11; mr 3,31; bl _s802F0BFC_0; lwz 0,0x18(31); cmpwi 0,0; bne 2f; bl _s802F0BFC_1; mr 4,30; li 5,16; li 6,0; li 7,0; bl _s802F0BFC_2; cmpwi 3,0; stw 3,0x18(31); beq 3f; 2:; lwz 3,0x18(31); mr 5,30; lwz 4,0x10(31); crxor 6,6,6; bl _s802F0BFC_3; lwz 0,0x0(31); lwz 9,0x18(31); rlwinm 0,0,0,31,29; stw 0,0x0(31); stw 9,0x10(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802F0BFC_0();
extern "C" void _s802F0BFC_1();
extern "C" void _s802F0BFC_2();
extern "C" void _s802F0BFC_3();

struct EAnimController {
    void Enable();
};

void EAnimController::Enable() {
}
