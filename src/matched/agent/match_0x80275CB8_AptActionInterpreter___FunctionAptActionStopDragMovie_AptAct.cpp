// 0x80275CB8 AptActionInterpreter::_FunctionAptActionStopDragMovie(AptActionInterpreter (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-23008(13); lwz 11,0x3c(9); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lis 4,-32704; lis 5,-32704; addi 4,4,7408; lha 3,0x10(9); addi 5,5,6212; lwz 0,0x14(9); li 6,4686; add 3,11,3; mtspr 8,0; blrl; 0:; lwz 9,-23008(13); lwz 0,-22936(13); stw 0,0x3c(9); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80275CB8() {}
