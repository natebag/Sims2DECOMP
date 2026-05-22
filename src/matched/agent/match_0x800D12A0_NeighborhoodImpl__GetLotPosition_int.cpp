// 0x800D12A0 NeighborhoodImpl::GetLotPosition(int, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,4,-1; cmplwi 0,8; ble 0f; li 0,0; stw 0,0x0(6); stw 0,0x0(5); blr; 0:; lis 9,-32696; rlwinm 10,4,3,0,28; addi 9,9,25308; lwzx 11,9,10; addi 9,9,4; stw 11,0x0(5); lwzx 0,9,10; stw 0,0x0(6)"
extern "C" void f_800D12A0() {}
