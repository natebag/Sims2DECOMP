struct NghResFile;

int NghReadHostSectionSub2(NghResFile *);

struct NeighborhoodImpl {
    char pad_00[0x14];
    NghResFile* m_resFile;

    int DestroyHelper2();
};

int NeighborhoodImpl::DestroyHelper2() {
    NghResFile* res = m_resFile;
    if (res != 0) {
        return NghReadHostSectionSub2(res);
    }
    return 0;
}
