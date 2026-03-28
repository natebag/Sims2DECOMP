/* HoodManager::GetMatrix(Neighbor *, Neighbor *, RelMatrix **, int *) at 0x800448EC (68B) */

struct RelMatrix;

struct Neighbor {
    char pad[4];
    short m_field_04;
    RelMatrix *GetRelations(void) const;
};

int HoodManager__GetMatrix(Neighbor *a, Neighbor *b, RelMatrix **outMatrix, int *outVal) {
    *outMatrix = a->GetRelations();
    *outVal = (int)b->m_field_04;
    return 1;
}
