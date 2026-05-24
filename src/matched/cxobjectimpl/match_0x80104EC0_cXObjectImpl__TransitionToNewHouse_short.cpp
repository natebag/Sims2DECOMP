// 0x80104EC0 cXObjectImpl::TransitionToNewHouse(short, (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,5; cmpwi 31,2; bne 0f; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; lwz 9,-21432(13); li 0,1; stw 0,0x454(9); lis 9,-32697; lwz 3,0x5bc8(9); bl _s80104EC0_0; b 6f; 0:; cmpwi 31,3; bne 1f; lwz 11,-21432(13); li 0,1; lwz 10,-21476(13); li 4,1; stw 0,0x450(11); lwz 9,0x0(10); lha 3,0x78(9); lwz 0,0x7c(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,1; bne 6f; lwz 3,-21476(13); li 4,1; li 5,0; lwz 9,0x0(3); lha 0,0x88(9); lwz 9,0x8c(9); add 3,3,0; mtspr 8,9; blrl; b 6f; 1:; cmpwi 31,4; bne 4f; lis 9,-32697; li 28,0; addi 30,9,24012; li 29,0; lwz 11,0xbc(30); cmpwi 11,0; beq 2f; lwz 9,0x4(11); lha 3,0x1b0(9); lwz 0,0x1b4(9); add 3,11,3; mtspr 8,0; blrl; mr 28,3; 2:; lwz 11,0xc0(30); cmpwi 11,0; beq 3f; lwz 9,0x4(11); lha 3,0x1b0(9); lwz 0,0x1b4(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; 3:; lis 9,-32697; lis 3,-32706; addi 9,9,23428; addi 3,3,-15964; stwu 28,0xd0(9); stwx 29,9,31; bl _s80104EC0_1; b 6f; 4:; lwz 9,-21432(13); li 0,1; cmpwi 31,5; stw 0,0x460(9); bne 5f; stw 0,0x450(9); stw 4,0x464(9); b 6f; 5:; stw 0,0x458(9); stw 0,0x464(9); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80104EC0_0();
extern "C" void _s80104EC0_1();

struct cXObjectImpl {
    void TransitionToNewHouse();
};

void cXObjectImpl::TransitionToNewHouse() {
}
