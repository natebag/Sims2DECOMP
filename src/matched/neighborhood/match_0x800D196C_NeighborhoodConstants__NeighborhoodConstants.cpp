/* NeighborhoodConstants::NeighborhoodConstants(void) - 0x800D196C (64 bytes) */

struct GlobalConstantsClient {
    GlobalConstantsClient(short);
};

extern void *__vt__23NeighborhoodConstants[];

struct NeighborhoodConstants : public GlobalConstantsClient {
    NeighborhoodConstants(void);
};

NeighborhoodConstants::NeighborhoodConstants(void) : GlobalConstantsClient(4)
{
    *(void ***)this = __vt__23NeighborhoodConstants;
}
