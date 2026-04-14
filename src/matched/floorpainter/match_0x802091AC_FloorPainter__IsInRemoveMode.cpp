/* InteractorModule::FloorPainter::IsInRemoveMode(void) at 0x802091AC (16B) */

namespace InteractorModule {

struct FloorPainter {
    char pad[0xA4];
    int m_fieldA4;

    int IsInRemoveMode(void);
};

int FloorPainter::IsInRemoveMode(void) {
    return m_fieldA4 == 0;
}

}
