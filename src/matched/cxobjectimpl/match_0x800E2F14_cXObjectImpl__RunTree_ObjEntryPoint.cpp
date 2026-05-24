// 0x800E2F14 cXObjectImpl::RunTree(ObjEntryPoint, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 30,4; lwz 11,0x4(29); mr 28,5; mr 27,6; lwz 9,0x4(11); lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 4,30; lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 0f; lwz 10,0x4(29); lwz 9,0x0(29); lwz 11,0x4(10); lwz 29,0x0(9); lha 3,0x378(11); lwz 11,0x37c(11); lwz 30,0x18(29); add 3,10,3; mtspr 8,11; lha 0,0xa0(30); addi 30,30,160; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mr 5,28; mr 6,31; mr 7,27; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

struct cXObjectImpl {
    void RunTree_ObjEntryPoint();
};

void cXObjectImpl::RunTree_ObjEntryPoint() {
}
