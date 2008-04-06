#ifndef _UPDATEDATA_H
#define _UPDATEDATA_H

enum OBJECT_UPDATE_TYPE
{
	UPDATETYPE_VALUES               = 0,
	UPDATETYPE_MOVEMENT             = 1,
	UPDATETYPE_CREATE_OBJECT        = 2,
	UPDATETYPE_CREATE_OBJECT2       = 3,
	UPDATETYPE_OUT_OF_RANGE_OBJECTS = 4,
	UPDATETYPE_NEAR_OBJECTS         = 5
};

enum OBJECT_UPDATE_FLAGS
{
    UPDATEFLAG_NONE         = 0x00,
    UPDATEFLAG_SELF         = 0x01,
    UPDATEFLAG_TRANSPORT    = 0x02,
    UPDATEFLAG_FULLGUID     = 0x04,
    UPDATEFLAG_LOWGUID      = 0x08,
    UPDATEFLAG_HIGHGUID     = 0x10,
    UPDATEFLAG_LIVING       = 0x20,
    UPDATEFLAG_HASPOSITION  = 0x40
};

enum MovementFlags
{
    MOVEMENTFLAG_NONE           = 0x00000000,
    MOVEMENTFLAG_FORWARD        = 0x00000001,
    MOVEMENTFLAG_BACKWARD       = 0x00000002,
    MOVEMENTFLAG_STRAFE_LEFT    = 0x00000004,
    MOVEMENTFLAG_STRAFE_RIGHT   = 0x00000008,
    MOVEMENTFLAG_LEFT           = 0x00000010,
    MOVEMENTFLAG_RIGHT          = 0x00000020,
    MOVEMENTFLAG_PITCH_UP       = 0x00000040,
    MOVEMENTFLAG_PITCH_DOWN     = 0x00000080,
    MOVEMENTFLAG_WALK           = 0x00000100,
    MOVEMENTFLAG_ONTRANSPORT    = 0x00000200,
    MOVEMENTFLAG_UNK1           = 0x00000400,
    MOVEMENTFLAG_FLY_UNK1       = 0x00000800,
    MOVEMENTFLAG_JUMPING        = 0x00001000,
    MOVEMENTFLAG_UNK4           = 0x00002000,
    MOVEMENTFLAG_FALLING        = 0x00004000,
    // 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000
    MOVEMENTFLAG_SWIMMING       = 0x00200000,               // appears with fly flag also
    MOVEMENTFLAG_FLY_UP         = 0x00400000,
    MOVEMENTFLAG_CAN_FLY        = 0x00800000,
    MOVEMENTFLAG_FLYING         = 0x01000000,
    MOVEMENTFLAG_UNK5           = 0x02000000,
    MOVEMENTFLAG_SPLINE         = 0x04000000,               // probably wrong name
    MOVEMENTFLAG_SPLINE2        = 0x08000000,
    MOVEMENTFLAG_WATERWALKING   = 0x10000000,
    MOVEMENTFLAG_SAFE_FALL      = 0x20000000,               // active rogue safe fall spell (passive)
    MOVEMENTFLAG_UNK3           = 0x40000000
};

struct MovementInfo
{
    // common
    uint32  flags;
    uint8   unk1;
    uint32  time;
    float   x, y, z, o;
    // transport
    uint64  t_guid;
    float   t_x, t_y, t_z, t_o;
    uint32  t_time;
    // swimming and unk
    float   s_angle;
    // last fall time
    uint32  fallTime;
    // jumping
    float   j_unk, j_sinAngle, j_cosAngle, j_xyspeed;
    // spline
    float   u_unk1;

    MovementInfo()
    {
        flags = time = t_time = fallTime = 0;
        unk1 = 0;
        x = y = z = o = t_x = t_y = t_z = t_o = s_angle = j_unk = j_sinAngle = j_cosAngle = j_xyspeed = u_unk1 = 0.0f;
        t_guid = 0;
    }

    void SetMovementFlags(uint32 _flags)
    {
        flags = _flags;
    }
};

bool IsFloatField(uint8, uint32);

#endif
