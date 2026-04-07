// 0x8012C72C cXPersonImpl::GetCurrentInteractionNC (44B)

struct cXPersonImpl_GCNC {
    char _pad[0x130 + 0x2a8];
    unsigned int m_curIdx;
    void* GetCurrentInteractionNC();
};

void* cXPersonImpl_GCNC::GetCurrentInteractionNC() {
    char* base = (char*)this + 0x130;
    unsigned int curIdx = *(unsigned int*)(base + 0x2a8);
    return base + (curIdx % 10) * 68;
}
