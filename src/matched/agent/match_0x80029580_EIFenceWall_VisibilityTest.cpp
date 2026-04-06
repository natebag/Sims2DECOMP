// EIFenceWall::VisibilityTest(E3DWindow &)
// Address: 0x80029580 | Size: 44 bytes

struct E3DWindow;

struct EIFenceWall {
    char pad[0x3C];
    // offset 0x3C is where visibility data starts
    
    void VisibilityTest(E3DWindow& window);
};

extern void TestVisibility(E3DWindow& win, void* data);

void EIFenceWall::VisibilityTest(E3DWindow& window) {
    TestVisibility(window, (char*)this + 0x3C);
}
