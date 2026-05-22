// 0x80142D64 ObjectSlot::SetHeight(StdHeight) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,2; stw 4,0x8(3); beq 4f; bgt 0f; cmpwi 4,0; beq 1f; cmpwi 4,1; beq 3f; blr; 0:; cmpwi 4,4; beq 5f; blt 5f; cmpwi 4,8; beq 5f; blr; 1:; lis 9,-32706; lfs f13,0x1c(3); lfs f0,-10512(9); fcmpu 0,f13,f0; bne 2f; li 0,1; stw 0,0x8(3); blr; 2:; li 0,5; stw 0,0x8(3); blr; 3:; lis 9,-32706; lfs f0,-10512(9); stfs f0,0x1c(3); blr; 4:; lis 9,-32706; lfs f0,-10508(9); stfs f0,0x1c(3); blr; 5:; lis 9,-32706; lfs f0,-10504(9); stfs f0,0x1c(3)"
extern "C" void f_80142D64() {}
