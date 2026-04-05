// EIFenceWall::VisibilityTest(E3DWindow &)
// Address: 0x80029580 | Size: 44 bytes

struct E3DWindow;
struct EBound3;

// External function: E3DWindow::Test(EBound3 &)
extern "C" bool _ZN8E3DWindow4TestER7EBound3(E3DWindow* self, void* bound);

struct EIFenceWall {
    char pad[0x3C];
    // m_bound at offset 0x3C
};

bool EIFenceWall__VisibilityTest(EIFenceWall* self, E3DWindow* window) {
    return _ZN8E3DWindow4TestER7EBound3(window, (char*)self + 0x3C);
}
