struct Inner { char pad[0x98]; void* renderer; };
struct MUStatesDisplay { char pad[8]; Inner* m_inner; };
extern "C" void resetRenderer(void*);
void MUStatesDisplay_Reset(MUStatesDisplay* self) {
    void* r = self->m_inner->renderer;
    if (r) { resetRenderer(r); }
}
