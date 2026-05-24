// 0x802E79F4 EAnimController::DeallocateNodes(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; lwz 0,0x18(30); cmpwi 0,0; beq 0f; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; bl _s802E79F4_0; lwz 4,0x18(30); bl _s802E79F4_1; li 0,0; stw 0,0x18(30); 0:; lwz 0,0x1c(30); cmpwi 0,0; bne 1f; lwz 0,0x20(30); cmpwi 0,0; beq 3f; 1:; lwz 3,-26392(13); addi 29,30,28; li 27,0; li 31,0; lwz 9,0x0(3); li 28,2; lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 2:; bl _s802E79F4_2; lwzx 4,31,29; bl _s802E79F4_3; stwx 27,31,29; addic. 28,28,-1; addi 31,31,4; bne 2b; 3:; li 9,-1; li 0,0; stw 0,0x10(30); stw 9,0x2c(30); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s802E79F4_0();
extern "C" void _s802E79F4_1();
extern "C" void _s802E79F4_2();
extern "C" void _s802E79F4_3();

struct EAnimController {
    void DeallocateNodes();
};

void EAnimController::DeallocateNodes() {
}
