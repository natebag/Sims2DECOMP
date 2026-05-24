// 0x801ECC78 StaticGetShaderId(InteractorModule::WallData*) (32 B)
// null-check via mr., vtable[0] (offset 0) = shader ID.
namespace InteractorModule {
struct WallData { int* m_vt; };
}
int StaticGetShaderId(InteractorModule::WallData* d) {
    if (!d) return (int)0xD59C7BB5;
    return d->m_vt[0];
}
