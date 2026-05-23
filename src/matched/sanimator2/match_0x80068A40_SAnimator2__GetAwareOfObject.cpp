/* 0x80068A40 (8 bytes) - SAnimator2::GetAwareOfObject(void) */
class cXObject;
struct SAnimator2 {
    char pad[0x63C];
    cXObject* m_awareOfObject;
    cXObject* GetAwareOfObject();
};
cXObject* SAnimator2::GetAwareOfObject() { return m_awareOfObject; }
