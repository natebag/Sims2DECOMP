void *CTGF_GetNameImpl(void *);

struct CTGF_GN {
    void *GetName(void);
};

void *CTGF_GN::GetName(void) {
    return CTGF_GetNameImpl((char *)this + 4);
}
