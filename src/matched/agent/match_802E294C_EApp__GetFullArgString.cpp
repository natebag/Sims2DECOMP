class EApp {
public:
    char m_pad[848];
    char m_fullArgString;
    char *GetFullArgString() const;
};
char *EApp::GetFullArgString() const { return (char *)&m_fullArgString; }
