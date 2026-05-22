// 0x803C22F4 AllocPoolManager<FastAllocPool>::AttemptPoolAlloc(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,64; ble 0f; li 3,0; blr; 0:; addi 0,4,-1; rlwinm 4,0,29,3,31; cmpwi 4,7; bgt 3f; mulli 9,4,24; lis 11,17477; ori 11,11,21333; addi 9,9,8; add 9,9,3; 1:; lwz 0,0x10(9); cmplw 5,0; bgt 2f; lwz 3,0x4(9); cmpwi 3,0; beq 2f; lwz 0,0x4(3); stw 0,0x4(9); stw 11,0x0(3); bnelr; 2:; addi 4,4,1; addi 9,9,24; cmpwi 4,7; ble 1b; 3:; li 3,0"
extern "C" void f_803C22F4() {}
