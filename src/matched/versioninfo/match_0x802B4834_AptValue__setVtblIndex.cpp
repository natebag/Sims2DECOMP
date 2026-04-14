/* AptValue::setVtblIndex(AptVirtualFunctionTable_Indices) at 0x802B4834 (16B) */

typedef int AptVirtualFunctionTable_Indices;

struct AptValue {
    unsigned int m_high : 25;
    unsigned int m_vtblIndex : 7;

    void setVtblIndex(AptVirtualFunctionTable_Indices idx);
};

void AptValue::setVtblIndex(AptVirtualFunctionTable_Indices idx) {
    m_vtblIndex = idx;
}
