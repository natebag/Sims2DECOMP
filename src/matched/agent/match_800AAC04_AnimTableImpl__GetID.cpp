struct AnimTableData {
    int pad;
    short m_id;
};

class AnimTableImpl {
public:
    void *vtable;
    AnimTableData *m_data;

    int GetID(void);
};

int AnimTableImpl::GetID(void) {
    return m_data->m_id;
}
