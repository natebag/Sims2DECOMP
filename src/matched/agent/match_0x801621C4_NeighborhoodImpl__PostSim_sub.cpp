struct NghResFile;

int NghReadHostSectionSub4(NghResFile *);

struct NeighborhoodImpl {
    char pad_00[0x14];
    NghResFile* m_resFile;

    int PostSimHelper();
};

int NeighborhoodImpl::PostSimHelper() {
    NghResFile* res = m_resFile;
    if (res != 0) {
        return NghReadHostSectionSub4(res);
    }
    return 0;
}
