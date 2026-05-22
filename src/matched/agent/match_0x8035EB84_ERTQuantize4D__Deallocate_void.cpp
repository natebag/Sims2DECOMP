// 0x8035EB84 ERTQuantize4D::Deallocate(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x1008(31); cmpwi 3,0; beq 0f; lwz 9,0x1000(31); mtspr 8,9; blrl; li 0,0; stw 0,0x1008(31); 0:; li 0,1; sth 0,0x1006(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8035EB84() {}
