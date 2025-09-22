#include "GlobalSettings.h"

std::string ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:/Users/Nastya/Documents/АУпПРБ/4_семестр/ТП/курсовая/EdProgs-20250413_1901/EdProgs-20250412_1901/db/EdProgs.mdb";

System::String^ EdProgs::GetConnectionString() {
    return gcnew System::String(ConnectionString.c_str());
}

System::String^ EdProgs::GetDocumentsFolder() {
    return gcnew System::String("C:\\Users\\Nastya\\Documents\\АУпПРБ\\4_семестр\\ТП\\курсовая\\EdProgs-20250413_1901\\EdProgs-20250412_1901\\docs\\");
}