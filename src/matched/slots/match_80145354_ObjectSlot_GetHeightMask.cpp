// 0x80145354 (16 bytes) - ObjectSlot::GetHeightMask(StdHeight)
// Static: addi r0,r3,-1; li r3,1; slw r3,r3,r0; blr
// Returns 1 << (height - 1)

int ObjectSlot_GetHeightMask(int height) {
    return 1 << (height - 1);
}
