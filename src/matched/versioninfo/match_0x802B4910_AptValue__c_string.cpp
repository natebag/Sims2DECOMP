// 0x802B4910 AptValue::c_string (24b)

struct AptValue {
    unsigned int m_data;
    char _pad[32];
    void *m_ptr;
};

void *AptValue__c_string(AptValue *self) {
    if ((self->m_data & 0x7F) == 1) return self;
    return self->m_ptr;
}
