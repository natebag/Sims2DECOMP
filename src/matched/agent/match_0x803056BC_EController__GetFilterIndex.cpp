struct FilterEntry {
    unsigned int m_id;
    unsigned int m_mask;
    unsigned int m_flags;
};

struct EController {
    int m_id;
    int m_status;
    int m_filterCount;
    FilterEntry m_filters[32];
    int GetFilterIndex(unsigned int filterId);
};

int EController::GetFilterIndex(unsigned int filterId) {
    int i;
    if (filterId == 0)
        goto not_found;
    i = m_filterCount;
    if (i < 0)
        goto not_found;
    do {
        if (m_filters[i].m_id == filterId)
            return i;
    } while (--i >= 0);
not_found:
    return -1;
}
