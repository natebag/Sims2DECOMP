// 0x801ECC58 StaticGetShaderId(InteractorModule::WallPaperData*) (32 B)
// null-check via mr., vtable[2] (offset 8) = shader ID.
namespace InteractorModule {
struct WallPaperData { int* m_vt; };
}
int StaticGetShaderId(InteractorModule::WallPaperData* d) {
    if (!d) return (int)0xD59C7BB5;
    return d->m_vt[2];
}
