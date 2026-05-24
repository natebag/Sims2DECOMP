// 0x800E1CB8 cXObjectImpl::UserCanDelete(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,-21432(13); mr 30,3; li 3,1; lwz 0,0x3dc(9); cmpwi 0,0; bne 4f; mr 3,30; bl _s800E1CB8_0; cmpwi 3,0; li 3,0; beq 4f; addi 3,30,40; li 4,43; bl _s800E1CB8_1; lhz 0,0x0(3); andi. 9,0,8; bne 1f; 0:; li 3,0; b 4f; 1:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x2b0(9); lwz 9,0x2b4(9); add 3,3,0; mtspr 8,9; blrl; addic. 31,3,-1; blt 3f; 2:; lwz 3,0x4(30); mr 4,31; lwz 9,0x4(3); lha 0,0x2c0(9); lwz 9,0x2c4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0b; addic. 31,31,-1; bge 2b; 3:; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800E1CB8_0();
extern "C" void _s800E1CB8_1();

struct cXObjectImpl {
    void UserCanDelete();
};

void cXObjectImpl::UserCanDelete() {
}
