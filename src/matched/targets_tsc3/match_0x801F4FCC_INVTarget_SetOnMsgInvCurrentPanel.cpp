/* INVTarget::SetOnMsgInvCurrentPanel - 0x801F4FCC - 64 bytes */

extern int atoi(const char *);

struct INVTarget {
    char pad[0x3198];
    int m_currentPanel;
    void SetOnMsgInvCurrentPanel(char *val);
};

void INVTarget::SetOnMsgInvCurrentPanel(char *val)
{
    m_currentPanel = (atoi(val) == 1);
}
