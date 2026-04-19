/* Emitter::GetInstName(EInstance::InstType &) at 0x80238B08 (48B) */

extern char g_emitterNameA[];
extern char g_emitterNameB[];

struct EInstance_GIN { char pad[128]; void* m_ptr; };

struct Emitter_GIN {
    char pad[124];
    EInstance_GIN* m_inst;
    const char* GetInstName(int& instType);
};

const char* Emitter_GIN::GetInstName(int& instType) {
    EInstance_GIN* inst = m_inst;
    void* ptr = inst->m_ptr;
    instType = 5;
    if (ptr) return g_emitterNameB;
    return g_emitterNameA;
}
