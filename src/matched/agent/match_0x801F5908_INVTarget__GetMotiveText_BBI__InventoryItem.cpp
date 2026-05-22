// 0x801F5908 INVTarget::GetMotiveText(BBI::InventoryItem (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,3; mr 31,4; mr. 30,5; beq 11f; cmpwi 31,0; li 3,0; beq 13f; mr 3,31; bl _s801F5908_0; cmpwi 3,2; beq 1f; bgt 0f; cmpwi 3,1; beq 6f; b 11f; 0:; cmpwi 3,3; beq 7f; b 11f; 1:; mr 3,31; bl _s801F5908_1; cmpwi 3,3; beq 4f; bgt 2f; cmpwi 3,1; beq 6f; cmpwi 3,2; beq 3f; b 11f; 2:; cmpwi 3,4; beq 12f; cmpwi 3,5; beq 5f; b 11f; 3:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-23520; addi 3,1,8; crxor 6,6,6; bl _s801F5908_2; lwz 9,0x8(1); b 8f; 4:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-23508; addi 3,1,12; crxor 6,6,6; bl _s801F5908_3; lwz 9,0xc(1); b 8f; 5:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-23492; addi 3,1,16; crxor 6,6,6; bl _s801F5908_4; lwz 9,0x10(1); b 8f; 6:; mr 3,31; bl _s801F5908_5; mr 4,3; mr 5,30; mr 3,29; bl _s801F5908_6; b 12f; 7:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-23476; addi 3,1,20; crxor 6,6,6; bl _s801F5908_7; lwz 9,0x14(1); 8:; li 0,1; cmpwi 7,9,0; bne cr7,9f; li 0,0; 9:; cmpwi 0,0; beq 11f; li 4,0; beq cr7,10f; lwz 4,0x0(9); 10:; mr 3,30; bl _s801F5908_8; b 12f; 11:; li 3,0; b 13f; 12:; li 3,1; 13:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801F5908_0();
extern "C" void _s801F5908_1();
extern "C" void _s801F5908_2();
extern "C" void _s801F5908_3();
extern "C" void _s801F5908_4();
extern "C" void _s801F5908_5();
extern "C" void _s801F5908_6();
extern "C" void _s801F5908_7();
extern "C" void _s801F5908_8();
extern "C" void f_801F5908() {}
