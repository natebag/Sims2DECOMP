// 0x801F5A94 INVTarget::GetMotiveText(int, (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr. 31,6; beq 4f; cmpwi 5,0; beq 4f; cmpwi 4,9; beq 8f; blt 7f; cmpwi 4,10; beq 0f; cmpwi 4,11; beq 2f; b 7f; 0:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-23492; addi 3,1,8; crxor 6,6,6; bl _s801F5A94_0; lwz 9,0x8(1); li 0,1; cmpwi 7,9,0; bne cr7,1f; li 0,0; 1:; cmpwi 0,0; beq 4f; b 5f; 2:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-23508; addi 3,1,12; crxor 6,6,6; bl _s801F5A94_1; lwz 9,0xc(1); li 0,1; cmpwi 7,9,0; bne cr7,3f; li 0,0; 3:; cmpwi 0,0; bne 5f; 4:; li 3,0; b 9f; 5:; li 4,0; beq cr7,6f; lwz 4,0x0(9); 6:; mr 3,31; bl _s801F5A94_2; b 8f; 7:; cmplwi 4,13; bgt 8f; lwz 4,0x0(5); mr 5,31; bl _s801F5A94_3; 8:; li 3,1; 9:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s801F5A94_0();
extern "C" void _s801F5A94_1();
extern "C" void _s801F5A94_2();
extern "C" void _s801F5A94_3();
extern "C" void f_801F5A94() {}
