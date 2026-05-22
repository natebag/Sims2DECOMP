// 0x8022544C InteractorModule::WallPainter::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; cmpwi 4,1; beq 4f; bgt 0f; cmpwi 4,0; beq 1f; b 8f; 0:; cmpwi 4,2; beq 5f; cmpwi 4,4; beq 7f; b 8f; 1:; lwz 9,0x88(11); andi. 0,9,17; beq 2f; ori 0,9,32; lis 3,-32704; stw 0,0x88(11); addi 3,3,-7272; crxor 6,6,6; bl _s8022544C_0; b 8f; 2:; xori 0,9,1; andi. 10,0,1; beq 8f; ori 0,9,3; lis 3,-32704; stw 0,0x88(11); addi 3,3,-7252; crxor 6,6,6; bl _s8022544C_1; lwz 0,-31536(13); cmpwi 0,0; bne 3f; li 3,120; bl _s8022544C_2; bl _s8022544C_3; stw 3,-31536(13); 3:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s8022544C_4; b 8f; 4:; lwz 0,0x88(11); andi. 9,0,8; beq 8f; rlwinm 0,0,0,0,30; ori 0,0,8192; stw 0,0x88(11); b 8f; 5:; lwz 9,0x88(11); xori 0,9,1; andi. 10,0,1; beq 8f; andi. 0,9,16; bne 8f; andi. 10,9,1; beq 6f; ori 0,9,1024; stw 0,0x88(11); 6:; lwz 0,0x88(11); lis 3,-32704; addi 3,3,-7232; ori 0,0,16; stw 0,0x88(11); crxor 6,6,6; bl _s8022544C_5; b 8f; 7:; lwz 0,0x88(11); lis 3,-32704; addi 3,3,-7212; ori 0,0,64; stw 0,0x88(11); crxor 6,6,6; bl _s8022544C_6; 8:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8022544C_0();
extern "C" void _s8022544C_1();
extern "C" void _s8022544C_2();
extern "C" void _s8022544C_3();
extern "C" void _s8022544C_4();
extern "C" void _s8022544C_5();
extern "C" void _s8022544C_6();
extern "C" void f_8022544C() {}
