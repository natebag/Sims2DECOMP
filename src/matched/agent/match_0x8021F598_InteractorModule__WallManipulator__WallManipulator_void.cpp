// 0x8021F598 InteractorModule::WallManipulator::WallManipulator(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 30,3; bl _s8021F598_0; lis 9,-32697; li 0,0; addi 9,9,-30832; stw 0,0x78(30); stw 9,0x5c(30); addi 11,30,128; stw 0,0x7c(30); addi 9,30,136; stw 0,0x4(11); addi 10,30,144; stw 0,0x88(30); addi 8,30,152; stw 0,0x4(9); addi 7,30,160; stw 0,0x4(10); addi 6,30,168; stw 0,0x98(30); addi 5,30,176; stw 0,0x4(8); lis 11,-32698; stw 0,0x4(7); addi 9,30,224; stw 0,0xa8(30); addi 11,11,28984; stw 0,0x4(6); li 10,3; stw 0,0x4(5); mr 3,30; stw 11,0x10(9); stw 10,0xe0(30); stw 0,0x24(9); stw 0,0x14(9); stw 0,0x18(9); lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s8021F598_0();
extern "C" void f_8021F598() {}
