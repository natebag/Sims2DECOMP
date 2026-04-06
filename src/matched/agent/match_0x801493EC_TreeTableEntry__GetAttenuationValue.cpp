struct TreeTableEntry { char pad[8]; float m_attenuation; int m_type; };
extern "C" float getAttenuation(void* other, float val, int type);
float TreeTableEntry_GetAttenuationValue(TreeTableEntry* self, void* other) {
    return getAttenuation(other, self->m_attenuation, self->m_type);
}
