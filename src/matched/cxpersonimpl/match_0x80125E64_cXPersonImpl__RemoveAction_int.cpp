// 0x80125E64 cXPersonImpl::RemoveAction(int) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stw 31,0x54(1); stw 0,0x5c(1); mr 31,3; li 8,0; addi 9,31,304; li 10,0; lwz 7,0x2a8(9); lwz 0,0x2ac(9); subf 0,7,0; cmplw 8,0; bge 1f; lis 11,-13108; mr 6,7; mr 5,9; mr 7,0; ori 11,11,52429; 0:; add 0,6,10; mulhwu 9,0,11; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 0,9,0; mulli 0,0,68; add 8,5,0; lwz 9,0x38(8); cmpw 9,4; beq 1f; addi 10,10,1; cmplw 10,7; blt 0b; 1:; addi 9,31,304; lwz 11,0x2a8(9); lwz 0,0x2ac(9); subf 0,11,0; cmpw 10,0; bne 2f; li 3,0; b 6f; 2:; cmpwi 10,0; bne 3f; lwz 0,0x534(31); cmpwi 0,0; beq 3f; lwz 0,0x3c(8); ori 0,0,256; rlwinm 9,0,22,31,31; stw 0,0x3c(8); cmpwi 9,0; bne 5f; sth 9,0x4a(31); lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x2e0(9); lwz 9,0x2e4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 5f; lwz 4,0x4(31); li 6,33; li 7,50; addi 3,1,8; lwz 5,0x0(4); bl _s80125E64_0; addi 3,1,8; li 4,0; bl _s80125E64_1; lwz 11,0x4(31); addi 4,1,8; lwz 9,0x4(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s80125E64_2; b 5f; 3:; lwz 0,0x3c(8); andi. 9,0,1024; beq 4f; ori 0,0,256; li 3,1; stw 0,0x3c(8); b 6f; 4:; mr 3,31; mr 4,8; bl _s80125E64_3; 5:; li 3,1; 6:; lwz 0,0x5c(1); mtspr 8,0; lwz 31,0x54(1); addi 1,1,88"

extern "C" void _s80125E64_0();
extern "C" void _s80125E64_1();
extern "C" void _s80125E64_2();
extern "C" void _s80125E64_3();

struct cXPersonImpl {
    void RemoveAction();
};

void cXPersonImpl::RemoveAction() {
}
