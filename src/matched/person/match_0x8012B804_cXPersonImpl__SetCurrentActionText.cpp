// 0x8012B804 cXPersonImpl::SetCurrentActionText (40B)

void ActionQueue_SetActionText(void* queue, void* text, unsigned int flags);

struct cXPersonImpl {
    char pad[0x130];
    char m_actionQueue[1];

    void SetCurrentActionText(void* text);
};

void cXPersonImpl::SetCurrentActionText(void* text) {
    ActionQueue_SetActionText(m_actionQueue, text, 0);
}
