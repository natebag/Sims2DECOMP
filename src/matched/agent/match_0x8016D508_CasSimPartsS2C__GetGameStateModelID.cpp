struct CasSimPartsS2C { char pad[0x0C]; int m_flags; };
extern "C" int getModelID(void* model, int inverted);
int CasSimPartsS2C_GetGameStateModelID(CasSimPartsS2C* self, unsigned int modelIdx) {
    int f = self->m_flags;
    return getModelID((void*)modelIdx, f ^ 1);
}
