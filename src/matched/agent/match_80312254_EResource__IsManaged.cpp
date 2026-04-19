/* EResource_IM::IsManaged() at 0x80312254 (24B) */

struct EResource_IM {
    char m_pad[4];
    int m_field;
    int IsManaged();
};

int EResource_IM::IsManaged() {
    if (m_field) return 1;
    return 0;
}
