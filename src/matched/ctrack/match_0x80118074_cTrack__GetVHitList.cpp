/* cTrack::GetVHitList(int) at 0x80118074 (48B) */

struct cTrackInner_GVH {
    char m_pad[36];
    char* m_array;
    int m_count;
};

struct cTrack_GVH {
    cTrackInner_GVH* m_inner;
    char* GetVHitList(int idx);
};

char* cTrack_GVH::GetVHitList(int idx) {
    if (idx < 0) idx = 0;
    cTrackInner_GVH* inner = m_inner;
    int count = inner->m_count;
    if (idx >= count) idx = count - 1;
    return inner->m_array + idx * 12;
}
