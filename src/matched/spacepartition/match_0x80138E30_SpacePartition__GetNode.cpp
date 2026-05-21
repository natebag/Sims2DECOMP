// 0x80138E30 SpacePartition::GetNode(int) (64 B)
// ASMPROC_replace_insn: match="lwz 0,80(3)" replacement="lwz 0,81(3)"
// ASMPROC_replace_insn: match="lwz 11,76(3)" replacement="lwz 0,80(3)"
// ASMPROC_replace_insn: match="lwz 0,81(3)" replacement="lwz 11,76(3)"
struct ASTNode { char data[44]; };
struct SpacePartition {
    char pad[0x4C];
    ASTNode* m_nodesBegin;
    ASTNode* m_nodesEnd;
    ASTNode* GetNode(int index);
};

ASTNode* SpacePartition::GetNode(int index) {
    ASTNode* begin;
    if (index < 0) goto null_return;
    begin = m_nodesBegin;
    if ((unsigned int)index < (unsigned int)(m_nodesEnd - begin)) goto fast_path;
null_return:
    return 0;
fast_path:
    return begin + index;
}
