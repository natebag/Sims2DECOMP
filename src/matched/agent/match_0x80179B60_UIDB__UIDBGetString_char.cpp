// 0x80179B60 UIDB::UIDBGetString(char (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-31520(13); mr 9,3; li 3,0; cmpwi 0,0; beq 1f; mr 3,9; li 4,115; bl _s80179B60_0; mr. 3,3; bne 0f; li 3,0; b 1f; 0:; lwz 3,0x8(3); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80179B60_0();
extern "C" void f_80179B60() {}
