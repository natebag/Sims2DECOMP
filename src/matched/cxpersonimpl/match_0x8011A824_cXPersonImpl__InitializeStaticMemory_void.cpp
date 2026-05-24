// 0x8011A824 cXPersonImpl::InitializeStaticMemory(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); lwz 0,-31708(13); lis 9,-32706; lwz 4,-13852(9); addi 11,1,8; addi 9,9,-13852; cmpwi 0,0; lwz 5,0x18(9); lwz 6,0x4(9); lwz 10,0x8(9); lwz 0,0xc(9); lwz 8,0x10(9); lwz 7,0x14(9); stw 4,0x8(1); stw 5,0x18(11); stw 6,0x4(11); stw 10,0x8(11); stw 0,0xc(11); stw 8,0x10(11); stw 7,0x14(11); bne 2f; lis 9,-32696; li 29,0; addi 30,9,26300; lwz 0,0x4(30); cmpw 29,0; bge 1f; lis 9,-32702; li 31,0; addi 28,9,17224; 0:; lwz 3,0x0(30); li 4,7; addi 29,29,1; add 3,3,31; bl _s8011A824_0; lwz 9,0x0(30); lwz 0,0x0(28); add 9,9,31; addi 28,28,4; stw 0,0x10(9); addi 31,31,20; lwz 0,0x4(30); cmpw 29,0; blt 0b; 1:; mr 3,30; addi 4,1,8; li 5,7; bl _s8011A824_1; li 0,1; stw 0,-31708(13); 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"

extern "C" void _s8011A824_0();
extern "C" void _s8011A824_1();

struct cXPersonImpl {
    void InitializeStaticMemory();
};

void cXPersonImpl::InitializeStaticMemory() {
}
