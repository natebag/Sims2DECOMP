// 0x800CA348 (64B) Neighbor::GetRelationship(Neighbor*, int*)
// If other == NULL: clear *outVal (if not NULL) and return 0.
// Else: delegate to GetRelationshipById(other->m_id, outVal).

class Neighbor {
public:
    char _pad[4];
    short m_id;  // +4
    int GetRelationship(Neighbor* other, int* outVal);
    int GetRelationshipById(int id, int* outVal);
};

int Neighbor::GetRelationship(Neighbor* other, int* outVal)
{
    if (other == 0) {
        if (outVal != 0) *outVal = 0;
        return 0;
    }
    return GetRelationshipById(other->m_id, outVal);
}
