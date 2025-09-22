#pragma once

#include <string>
#include <msclr/marshal_cppstd.h> // Для преобразования между std::string и System::String^

namespace EdProgs {
    System::String^ GetConnectionString();

    System::String^ GetDocumentsFolder();

    
}