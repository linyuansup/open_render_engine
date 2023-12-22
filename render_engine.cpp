#include "render_engine.h"

int dbNum = 0;
struct database *dbs = NULL;

EXAPI int init_engine(char *vocaloid_path)
{
    std::wstring wstr = std::wstring(vocaloid_path, vocaloid_path + strlen(vocaloid_path));
    std::string err;
    bool result = vocaloid::Init(wstr, err);
    if (!result)
    {
        printf(err.c_str());
        return -1;
    }
    vocaloid::vdm::DatabaseManager &dbManager = vocaloid::GetDatabaseManager();
    dbNum = dbManager.NumVoiceBanks();
    dbs = (struct database *)malloc(sizeof(struct database) * dbNum);
    for (int i = 0; i < dbNum; i++)
    {
        vocaloid::vdm::VoiceBank vb = dbManager.GetVoiceBankByIndex(i);
        dbs[i].id = i;
        dbs[i].lang_id = vb.LangID();
        dbs[i].name = (char *)malloc(sizeof(char) * 256);
        wcstombs(dbs[i].name, vb.Name(), 256);
    }
    return 0;
}

EXAPI struct database *get_databases()
{
    return dbs;
}

EXAPI int get_database_count()
{
    return dbNum;
}

EXAPI int render(char *input, char *des)
{
    std::wstring wstr = std::wstring(input, input + strlen(input));
    vocaloid::vsm::VSMSequenceData sqd = vocaloid::vsm::VSMSequenceData();
    sqd.SamplingRate = vocaloid::vsm::VSMSamplingRate::_44100;
    sqd.MaxNumTracks = 128;
    sqd.MaxUndoCount = 0;
    vocaloid::vsm::WIVSMSequence seq = vocaloid::GetSequenceManager().OpenSequence(wstr, sqd);
    if (!seq) {
        return -1;
    }
    return seq.GetTrack(0).GetPart(0).Render(std::wstring(des, des + strlen(des)));
}

EXAPI void stop()
{
    vocaloid::Destroy();
    free(dbs);
    dbs = NULL;
    dbNum = 0;
}
