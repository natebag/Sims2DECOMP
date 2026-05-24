// 0x80109264 cXObjectImpl::TryChangeWantFearTree(StackElem (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 9,5; mr 31,3; lha 5,0x2(9); lbz 4,0x4(9); li 6,0; lha 30,0x0(9); li 7,0; addi 8,1,8; bl _s80109264_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; beq 2f; 0:; lwz 3,-21476(13); lha 4,0x8(1); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 1f; rlwinm 4,30,0,16,31; bl _s80109264_1; cmpwi 3,0; li 3,0; li 4,1; bne 3f; li 3,0; li 4,0; b 3f; 1:; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,56; sth 9,0x34(11); li 4,56; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; 2:; li 3,-1; li 4,-1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80109264_0();
extern "C" void _s80109264_1();

struct cXObjectImpl {
    void TryChangeWantFearTree_StackElem();
};

void cXObjectImpl::TryChangeWantFearTree_StackElem() {
}
