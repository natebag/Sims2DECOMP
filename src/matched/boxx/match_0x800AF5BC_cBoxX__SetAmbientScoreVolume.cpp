struct cBoxX { char pad[0x64]; void* m_sound; };
extern "C" void setVolume(void*, int);
void cBoxX_SetAmbientScoreVolume(cBoxX* self, int vol) {
    if (self->m_sound) { setVolume(self->m_sound, vol); }
}
