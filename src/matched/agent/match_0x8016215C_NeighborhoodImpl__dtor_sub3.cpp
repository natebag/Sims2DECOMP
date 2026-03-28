struct NghResFile;

int NghReadHostSectionSub3(NghResFile *);

struct NeighborhoodImpl {
    char pad_00[0x14];
    NghResFile* m_resFile;

    int DestroyHelper3();
};

int NeighborhoodImpl::DestroyHelper3() {
    NghResFile* res = m_resFile;
    if (res != 0) {
        return NghReadHostSectionSub3(res);
    }
    return 0;
}
