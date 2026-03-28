// 0x80067758 (88 bytes)
// SAnimator2::GetBonePos(SAnimator::BoneIdx, EVec3 &)

class SAnimator2 { public: void GetBonePos(SAnimator::BoneIdx, EVec3 &); };

__attribute__((naked))
void SAnimator2::GetBonePos(SAnimator::BoneIdx, EVec3 &) {
    asm volatile(".long 0x2C040001\n.long 0x4182003C\n.long 0x41810010\n.long 0x2C040000\n.long 0x4182003C\n.long 0x4E800020\n.long 0x2C040002\n.long 0x4C820020\n.long 0x39230158\n.long 0x81430158\n.long 0x80090008\n.long 0x81690004\n.long 0x90050008\n.long 0x91450000\n.long 0x91650004\n.long 0x4E800020\n.long 0x3923014C\n.long 0x8143014C\n.long 0x4BFFFFE0\n.long 0x39230134\n.long 0x81430134\n.long 0x4BFFFFD4");
}
