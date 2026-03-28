struct AptXmlNode_PD {
    char pad[0x24];
    int m_field;
    void PreDestroy();
};
void AptXmlNode_PD::PreDestroy() {
    m_field = 0;
}
