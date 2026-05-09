// 0x80047600 EIFloor::VisibilityTest(E3DWindow &) (44 B)
// PRAGMA_STUB: EIFloor::VisibilityTest(E3DWindow &)
extern "C" int visTest(void* window, void* floor);
int EIFloor_VisibilityTest(void* self, void* window) {
    return visTest(window, (char*)self + 0x110);
}
