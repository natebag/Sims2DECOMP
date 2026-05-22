// 0x8025CBBC stateCheckID (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); addi 31,3,-17248; lwz 0,-23452(13); cmpwi 0,3; beq 0f; b 2f; 0:; lwz 4,-23480(13); addi 3,31,32; lwz 4,0x24(4); bl _s8025CBBC_0; cmpwi 3,0; beq 1f; lwz 3,-23476(13); addi 4,31,32; li 5,32; bl _s8025CBBC_1; lwz 4,-23480(13); li 0,1; addi 3,31,0; stw 0,0xc(4); li 4,32; bl _s8025CBBC_2; lis 4,-32730; lwz 3,-23480(13); addi 0,4,-13104; stw 0,-23392(13); bl _s8025CBBC_3; b 4f; 1:; lis 3,-32730; addi 3,3,-12892; bl _s8025CBBC_4; b 4f; 2:; lwz 4,-23476(13); addi 3,31,32; li 5,32; bl _s8025CBBC_5; cmpwi 3,0; beq 3f; lis 3,-32730; addi 3,3,-12892; bl _s8025CBBC_6; b 4f; 3:; lis 4,-32730; lwz 3,-23480(13); addi 0,4,-13156; stw 0,-23392(13); bl _s8025CBBC_7; 4:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025CBBC_0();
extern "C" void _s8025CBBC_1();
extern "C" void _s8025CBBC_2();
extern "C" void _s8025CBBC_3();
extern "C" void _s8025CBBC_4();
extern "C" void _s8025CBBC_5();
extern "C" void _s8025CBBC_6();
extern "C" void _s8025CBBC_7();
extern "C" void f_8025CBBC() {}
