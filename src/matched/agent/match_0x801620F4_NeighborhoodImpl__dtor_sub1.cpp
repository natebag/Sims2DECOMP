struct NghResFile;

int NghReadHostSectionSub1(NghResFile *);

struct NeighborhoodImpl {
    char pad_00[0x14];
    NghResFile* m_resFile;

    int DestroyHelper1();
};

int NeighborhoodImpl::DestroyHelper1() {
    NghResFile* res = m_resFile;
    if (res != 0) {
        return NghReadHostSectionSub1(res);
    }
    return 0;
}
