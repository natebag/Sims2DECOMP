struct ERModel { char pad[0x104]; void* m_subModels; };
extern "C" int getMorphCount(void*);
int ERModel_GetNumMorphLattice(ERModel* self, int idx) {
    return getMorphCount((char*)self->m_subModels + idx * 224);
}
