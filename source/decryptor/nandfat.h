#pragma once

#include "decryptor/nand.h"
#include "common.h"

#define MAX_ENTRIES 1024

#define F_TICKET     (1<<0)
#define F_TITLE      (1<<1)
#define F_IMPORT     (1<<2)
#define F_SECUREINFO (1<<3)
#define F_MOVABLE    (1<<4)
#define F_SEEDSAVE   (1<<5)

typedef struct {
    char name[32];
    u32 tid_high;
    u32 tid_low[6];
} TitleListInfo;

typedef struct {
    char name_sys[32];
    char name_emu[32];
    char path[64];
    u32 partition_id;
} NandFileInfo;

u32 SeekFileInNand(u32* offset, u32* size, const char* path, PartitionInfo* partition);
u32 ListFilesInNand(char* list, u32 lsize, const char* dir, const char* fmask, PartitionInfo* partition);
u32 DebugSeekFileInNand(u32* offset, u32* size, const char* filename, const char* path, PartitionInfo* partition);
u32 DebugSeekTitleInNand(u32* offset_tmd, u32* size_tmd, u32* offset_app, u32* size_app, TitleListInfo* title_info, u32 max_cnt);

// --> FEATURE FUNCTIONS <--
u32 DumpFile(u32 param);
u32 InjectFile(u32 param);
u32 DumpHealthAndSafety(u32 param);
u32 InjectHealthAndSafety(u32 param);