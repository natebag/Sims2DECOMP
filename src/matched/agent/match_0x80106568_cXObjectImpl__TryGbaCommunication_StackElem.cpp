// 0x80106568 cXObjectImpl::TryGbaCommunication(StackElem (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; bne 0f; bl _s80106568_0; cmpwi 3,0; li 3,0; li 4,1; bne 1f; 0:; li 3,0; li 4,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80106568_0();
extern "C" void f_80106568() {}
