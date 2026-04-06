struct Emitter { char pad[0x7C]; void* m_particles; };
extern "C" void resetParticles(void*);
void Emitter_Reset(Emitter* self) {
    if (self->m_particles) { resetParticles(self->m_particles); }
}
