// 0x80129804 (116 bytes)
/* cXPersonImpl::AttachToHUD(bool) */

struct cXPersonImpl_Attach_Vtable {
    char pad[0xBC];
    void* m_func1;       /* 0xBC */
    void* m_func2;       /* 0xC0 */
};

struct cXPersonImpl_Attach_Inner {
    char pad[4];
    cXPersonImpl_Attach_Vtable* m_vt;
};

struct cXPersonImpl_Attach {
    char _pad[0x04];
    cXPersonImpl_Attach_Inner* m_inner;
    char _pad2[0x130-0x08];
    void* m_field130;    /* 0x130 - passed to subfunction */

    void AttachToHUD(bool attach);
};

// Forward declarations
extern void cXPersonImpl_Sub1(void* field130, int val);  /* 0x8011A770 */
extern void cXPersonImpl_Sub2(void* field130, int val);  /* 0x8011A714 */

void cXPersonImpl_Attach::AttachToHUD(bool attach) {
    cXPersonImpl_Attach_Inner* inner = m_inner;
    cXPersonImpl_Attach_Vtable* vt = inner->m_vt;
    
    int shouldAttach = 0;
    if (vt->m_func1 == 0 && vt->m_func2 != 0) {
        shouldAttach = 1;
    }
    
    if (attach) {
        cXPersonImpl_Sub1(m_field130, shouldAttach);
    } else {
        cXPersonImpl_Sub2(m_field130, shouldAttach);
    }
}
