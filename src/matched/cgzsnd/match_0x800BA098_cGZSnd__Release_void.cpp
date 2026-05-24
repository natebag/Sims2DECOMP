// 0x800BA098 cGZSnd::Release(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; lwz 30,0x4(31); cmpwi 30,1; bne 2f; lwz 4,0x1c(31); cmpwi 4,0; beq 0f; li 29,0; lwz 11,-26564(13); stw 29,0x8(1); addi 5,1,8; lwz 9,0x0(11); lwz 0,0xac(9); lha 3,0xa8(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x18(1); cmpwi 0,0; beq 0f; lwz 3,0x4(31); stw 30,0x34(31); addi 3,3,-1; stw 29,0x20(31); b 3f; 0:; cmpwi 31,0; beq 1f; lwz 9,0x0(31); li 4,3; lha 3,0x98(9); lwz 0,0x9c(9); add 3,31,3; mtspr 8,0; blrl; 1:; li 3,0; b 4f; 2:; addi 3,30,-1; 3:; stw 3,0x4(31); 4:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"

struct cGZSnd {
    void Release();
};

void cGZSnd::Release() {
}
