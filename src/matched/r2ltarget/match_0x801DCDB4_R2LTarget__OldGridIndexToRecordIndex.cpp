// 0x801DCDB4 R2LTarget::OldGridIndexToRecordIndex (52B)

struct R2LTarget {
    char pad[0x9C];
    int m_recordCount;
    char pad2[0x8];
    int m_oldGridIndex;
};

int R2LTarget_OldGridIndexToRecordIndex(R2LTarget *self, int index) {
    int grid = self->m_oldGridIndex;
    int offset = grid * 6;
    int result = index + offset;
    if (grid < 0) goto fail;
    if (result < 0) goto fail;
    if (result < self->m_recordCount) goto success;
fail:
    return -1;
success:
    return result;
}
