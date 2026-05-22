// 0x80225594 InteractorModule::WallPainter::OnCommandReleased(InteractorModule::InteractorInputManager::InteractorCommand) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,8; beq 2f; bgt 0f; cmpwi 4,2; beq 5f; cmpwi 4,7; beq 1f; b 7f; 0:; cmpwi 4,11; beq 3f; cmpwi 4,12; beq 4f; b 7f; 1:; lis 9,-32704; lfs f0,-7176(9); stfs f0,0x34(3); b 7f; 2:; lis 9,-32704; lfs f0,-7176(9); stfs f0,0x38(3); b 7f; 3:; lis 9,-32704; lfs f0,-7176(9); stfs f0,0x3c(3); b 7f; 4:; lis 9,-32704; lfs f0,-7176(9); stfs f0,0x40(3); b 7f; 5:; lwz 9,0x88(3); andi. 0,9,16; beq 7f; rlwinm 0,9,0,28,26; andi. 11,9,4096; stw 0,0x88(3); beq 6f; ori 0,0,2048; stw 0,0x88(3); 6:; lis 3,-32704; addi 3,3,-7196; crxor 6,6,6; bl _s80225594_0; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80225594_0();
extern "C" void f_80225594() {}
