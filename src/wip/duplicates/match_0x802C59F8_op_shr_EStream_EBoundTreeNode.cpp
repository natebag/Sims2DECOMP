/* operator>>(EStream &, EBoundTreeNode *&) - 0x802C59F8 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EBoundTreeNode;

EStream &operator_shr_EStream_EBoundTreeNode(EStream &s, EBoundTreeNode *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EBoundTreeNode *)tmp;
    return s;
}
