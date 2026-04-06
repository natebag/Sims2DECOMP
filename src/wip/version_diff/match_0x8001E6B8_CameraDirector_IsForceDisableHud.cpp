// MATCH: 0x8001E6B8 CameraDirector::IsForceDisableHud (36 bytes)
// Raw: 80 03 01 6C 38 60 00 00 2C 00 00 01 4C 82 00 20 3D 20 80 47 80 09 5C 70 21 20 00 00 7C 69 01 14 4E 80 00 20

struct CameraDirector {
    int flags;  // offset 0x16C = 364
};

extern "C" int CameraDirector_IsForceDisableHud(CameraDirector* this_) {
    return (this_->flags == 1);
}
