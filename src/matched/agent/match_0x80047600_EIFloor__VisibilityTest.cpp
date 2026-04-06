extern "C" int visTest(void* window, void* floor);
int EIFloor_VisibilityTest(void* self, void* window) {
    return visTest(window, (char*)self + 0x110);
}
