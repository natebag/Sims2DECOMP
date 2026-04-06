struct ObjectDataBehaviorConstants { char pad[0x10]; char* m_names; };
extern "C" char* getName(char* base);
char* ObjectDataBehaviorConstants_GetValueName(ObjectDataBehaviorConstants* self, int idx) {
    return getName(self->m_names + idx * 4);
}
