class EDLEntry;
class ERC {
public:
    unsigned char m_type;
    char m_pad[3];
    EDLEntry *m_entry;
    void Connect(EDLEntry *, EDLEntry *);
};
void ERC::Connect(EDLEntry *from, EDLEntry *) {
    m_entry = from;
    m_type = 7;
}
