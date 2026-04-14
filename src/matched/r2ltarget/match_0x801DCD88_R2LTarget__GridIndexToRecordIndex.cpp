// 0x801dcd88 R2LTarget::GridIndexToRecordIndex (44B)

struct R2LTarget { char pad[0x9C]; int m_recordCount; char pad2[0x4]; int m_gridIndex; };

int R2LTarget_GridIndexToRecordIndex(R2LTarget* self, int index) {
    index += self->m_gridIndex * 6;
    if (index < 0) goto fail;
    if (index < self->m_recordCount) goto success;
fail:
    return -1;
success:
    return index;
}
