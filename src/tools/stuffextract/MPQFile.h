#ifndef MPQFILE_H
#define MPQFILE_H

#define _COMMON_NO_THREADS
#include "common.h"
#include "StormLib/StormLib.h"
#include "StormLib/SCommon.h"

class MPQFile
{
public:
    MPQFile(const char*);
    inline bool IsOpen(void) { return _isopen; }
    ByteBuffer ReadFile(char*);
    uint32 GetFileSize(char*);
    bool HasFile(char*);

private:
    HANDLE _mpq;
    bool _isopen;

};

#endif