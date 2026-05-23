/* 0x80068A6C (36 bytes) - SAnimator2::SetAwareOfObjectKilled(cXObject *) */
class cXObject;
extern void SA2_AwareFn(void*, cXObject*);

struct SAnimator2 {
    char pad[0x620];
    int m_awarenessData;
    void SetAwareOfObjectKilled(cXObject* obj);
};

void SAnimator2::SetAwareOfObjectKilled(cXObject* obj) {
    SA2_AwareFn(&m_awarenessData, obj);
}
