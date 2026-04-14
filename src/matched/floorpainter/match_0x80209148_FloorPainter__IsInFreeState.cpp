/* InteractorModule::FloorPainter::IsInFreeState(void) at 0x80209148 (16B) */

namespace InteractorModule {

struct FloorPainter {
    char pad[0x60];
    unsigned char m_field60;

    int IsInFreeState(void);
};

int FloorPainter::IsInFreeState(void) {
    return m_field60 == 0;
}

}
