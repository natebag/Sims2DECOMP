struct FilterEntry {
    unsigned int m_id;
    unsigned int m_mask;
    unsigned int m_value;
};

struct EController {
    int m_id;
    int m_status;
    int m_filterCount;
    FilterEntry m_filters[32];
    int GetFilterIndex(unsigned int filterId);
    void SetFilter(unsigned int filterId, unsigned int value);
};

void EController::SetFilter(unsigned int filterId, unsigned int value) {
    int index = GetFilterIndex(filterId);
    if (index >= 0) {
        m_filters[index].m_value = value;
    }
}
