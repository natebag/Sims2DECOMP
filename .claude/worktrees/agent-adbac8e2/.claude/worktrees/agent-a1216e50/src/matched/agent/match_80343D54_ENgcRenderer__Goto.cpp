/* 0x80343D54 (12 bytes) - ENgcRenderer::Goto(EDLEntry *) */
struct EDLEntry { int pad; int data; };
class ENgcRenderer { char pad[1244]; int m_dlOffset; public: static void Goto(EDLEntry *e); };
void ENgcRenderer::Goto(EDLEntry *e) { *(int*)((char*)e + 1244) = e->data; }
