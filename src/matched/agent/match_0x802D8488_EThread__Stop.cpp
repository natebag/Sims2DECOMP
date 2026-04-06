struct EThread { char pad[0x318]; void* m_thread; };
extern "C" void stopThread(void*);
void EThread_Stop(EThread* self) {
    if (self->m_thread) { stopThread(self->m_thread); }
}
