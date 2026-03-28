// 0x80175540 (100 bytes)
// CasSceneDefault::GetMirrorCorners(CasScene::RoomId, EVec3 *) const

class CasSceneDefault { public: void GetMirrorCorners(CasScene::RoomId, EVec3 *) const; };

__attribute__((naked))
void CasSceneDefault::GetMirrorCorners(CasScene::RoomId, EVec3 *) const {
    asm volatile(".long 0x2C040000\n.long 0x40820058\n.long 0x3D208048\n.long 0x39600030\n.long 0x39297984\n.long 0x80090000\n.long 0x356BFFE8\n.long 0x90050000\n.long 0x80090004\n.long 0x90050004\n.long 0x80090008\n.long 0x90050008\n.long 0x8009000C\n.long 0x9005000C\n.long 0x80090010\n.long 0x90050010\n.long 0x80090014\n.long 0x39290018\n.long 0x90050014\n.long 0x38A50018\n.long 0x4082FFC4\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
