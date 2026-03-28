struct Emitter_D {
    char pad[0x7C];
    int m_obj;
};

extern void Emitter_DestroyObj(void* obj);

void Emitter_Destroy(Emitter_D* self) {
    if (self->m_obj != 0) {
        Emitter_DestroyObj(&self->m_obj);
    }
}
