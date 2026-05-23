// 0x800FF1DC cXObjectImpl::TryTutorial(StackElem*, XPrimParam*) (284B)
//
// objectsim TU (loadingscreenstate.obj TU-local copy per build-archaeology).
// Three-way dispatcher on XPrimParam byte 0:
//   case 0: impl->vfunc[0x1F0](m_inner) — returns {0, 1} if non-zero, else {0, 0}
//   case 1: chain of impl vfunc checks (compare to m_inner, then conditional 2nd call)
//   default: set SDA flag + write 54 to m_field00 + call m_inner->vfunc[0x110](54),
//            return {-1, -1}
//
// All three branches return a packed pair (long long) — Template C variant family.

extern int g_tutorialFlag;  // SDA[-24512]

struct TutorialInner {
    char pad[0x04];
    char* m_vt;
};

struct TutorialImpl {
    char* m_vt;
};

struct TutorialField00 {
    char pad[52];
    short m_field52;
};

struct cXObjImplTUT {
    TutorialField00* m_field00;     // +0x00
    TutorialInner*   m_inner;        // +0x04
    char pad1[0x58 - 0x08];
    TutorialImpl*    m_impl;         // +0x58

    long long TryTutorial(void* se, void* param);
};

struct XPrimParam_byte0 {
    unsigned char op;
};

long long cXObjImplTUT::TryTutorial(void* /*se*/, void* param) {
    unsigned char op = *(unsigned char*)param;

    switch (op) {
        case 0: {
            TutorialImpl* impl = m_impl;
            char* vt = impl->m_vt;
            short adj = *(short*)(vt + 0x1F0);
            int (*fn)(void*, void*) = *(int(**)(void*, void*))(vt + 0x1F4);
            int r = fn((char*)impl + adj, m_inner);
            if (r == 0) return 0LL;
            return 1LL;
        }
        case 1: {
            TutorialImpl* impl = m_impl;
            char* vt = impl->m_vt;
            short adj = *(short*)(vt + 0x1E8);
            void* (*fn)(void*) = *(void*(**)(void*))(vt + 0x1EC);
            TutorialInner* ret = (TutorialInner*)fn((char*)impl + adj);
            if (m_inner != ret) return 0LL;
            TutorialImpl* impl2 = m_impl;
            char* vt2 = impl2->m_vt;
            short adj2 = *(short*)(vt2 + 0x1F0);
            int (*fn2)(void*, void*) = *(int(**)(void*, void*))(vt2 + 0x1F4);
            int r2 = fn2((char*)impl2 + adj2, (void*)0);
            if (r2 != 0) return 1LL;
            return 0LL;
        }
        default: {
            g_tutorialFlag = 1;
            m_field00->m_field52 = 54;
            TutorialInner* inner = m_inner;
            char* ivt = inner->m_vt;
            short iadj = *(short*)(ivt + 0x110);
            void (*ifn)(void*, int) = *(void(**)(void*, int))(ivt + 0x114);
            ifn((char*)inner + iadj, 54);
            return -1LL;
        }
    }
}
