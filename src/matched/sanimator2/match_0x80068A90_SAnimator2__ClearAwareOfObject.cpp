/* 0x80068A90 (36 bytes) - SAnimator2::ClearAwareOfObject(cXObject *) */
class cXObject;
extern void SA2_AwareFn(void*, cXObject*);

struct SAnimator2 {
    char pad[0x620];
    int m_awarenessData;
    void ClearAwareOfObject(cXObject* obj);
};

void SAnimator2::ClearAwareOfObject(cXObject* obj) {
    SA2_AwareFn(&m_awarenessData, obj);
}
