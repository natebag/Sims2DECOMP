// 0x8012C6E4 (48B) cXPersonImpl::CountActions(bool)

struct cXPersonImpl {
    char pad[984];
    char* m_actionStart;  // offset 984
    char* m_actionEnd;    // offset 988
    char pad2[340];       // to offset 1332
    int m_field_1332;
    int CountActions(bool flag);
};

int cXPersonImpl::CountActions(bool flag) {
    int diff = m_actionEnd - m_actionStart;
    if (flag) return diff;
    if (m_field_1332 == 0) return diff;
    return diff - 1;
}
