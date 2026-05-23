/* 0x80068A48 (36 bytes) - SAnimator2::SetAwareOfObject(cXObject *) */
class cXObject;
extern void SA2_AwareFn(void*, cXObject*);

struct SAnimator2 {
    char pad[0x620];
    int m_awarenessData;
    void SetAwareOfObject(cXObject* obj);
};

void SAnimator2::SetAwareOfObject(cXObject* obj) {
    SA2_AwareFn(&m_awarenessData, obj);
}
