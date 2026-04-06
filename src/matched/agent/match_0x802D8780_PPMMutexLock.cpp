struct Mutex { char pad[0x0C]; void* m_handle; };
extern "C" void acquireLock(void*);
void* PPMMutexLock(Mutex* self) {
    acquireLock(self);
    return self->m_handle;
}
