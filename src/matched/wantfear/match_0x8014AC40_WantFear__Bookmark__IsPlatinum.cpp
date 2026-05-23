struct WantFearNode { char pad[4]; void* m_inner; };
struct EventData { char pad[2]; unsigned char m_tier; };
extern "C" EventData* getEvent(void*);
int WantFear_Bookmark_IsPlatinum(WantFearNode* self) {
    EventData* evt = getEvent(self->m_inner);
    return (evt->m_tier ^ 1) == 0;
}
