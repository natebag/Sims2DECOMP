// 0x802B5DC4 AptPrototype::RegisterReferences(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s802B5DC4_0; lwz 4,0x20(31); cmpwi 4,0; beq 0f; lwz 9,-27024(13); lis 5,-32703; mr 3,31; addi 5,5,21048; mtspr 8,9; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802B5DC4_0();
extern "C" void f_802B5DC4() {}
