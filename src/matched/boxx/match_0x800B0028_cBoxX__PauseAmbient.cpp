// FLAGS: -fno-elide-constructors
struct cBoxX { char pad[0x64]; void* m_ambient; char pad2[0x0C]; int m_pauseCount; };
extern "C" void pauseSound(void*, int);
void cBoxX_PauseAmbient(cBoxX* self) {
    self->m_pauseCount++;
    if (self->m_ambient) {
        pauseSound(self->m_ambient, 1);
    }
}
