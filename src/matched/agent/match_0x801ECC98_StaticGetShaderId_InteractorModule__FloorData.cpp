// 0x801ECC98 StaticGetShaderId(InteractorModule::FloorData*) (32 B)
// null-check via mr., vtable[3] (offset 12) = shader ID.
namespace InteractorModule {
struct FloorData { int* m_vt; };
}
int StaticGetShaderId(InteractorModule::FloorData* d) {
    if (!d) return (int)0xD59C7BB5;
    return d->m_vt[3];
}
