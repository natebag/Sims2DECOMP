/* RoomScoreConstants::RoomScoreConstants(void) - 0x80138900 (64 bytes) */

struct GlobalConstantsClient {
    GlobalConstantsClient(short);
};

extern void *__vt__18RoomScoreConstants[];

struct RoomScoreConstants : public GlobalConstantsClient {
    RoomScoreConstants(void);
};

RoomScoreConstants::RoomScoreConstants(void) : GlobalConstantsClient(3)
{
    *(void ***)this = __vt__18RoomScoreConstants;
}
