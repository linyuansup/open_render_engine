#ifndef OPEN_RENDER_ENGINE_RENDER_ENGINE_H
#define OPEN_RENDER_ENGINE_RENDER_ENGINE_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "v5sdk/include/VDM/DatabaseManager.h"
#include "v5sdk/include/VDM/VoiceBank.h"
#include "v5sdk/include/VSM/WIVSMSequenceManager.h"
#include "v5sdk/include/VocaloidCore.h"
#include "api.h"

struct database
{
    char *name;
    int id;
    int lang_id;
};

EXAPI int init_engine(char *vocaloid_path);
EXAPI struct database *get_databases();
EXAPI int get_database_count();
EXAPI int render(char *input, char *des);

#endif