/* operator>>(EFile &, EBoundTreeNode *&) - 0x802C5A38 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EBoundTreeNode;

EFile &operator_shr_EFile_EBoundTreeNode(EFile &s, EBoundTreeNode *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EBoundTreeNode *)tmp;
    return s;
}
