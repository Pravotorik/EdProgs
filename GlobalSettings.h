#pragma once

#include <string>
#include <msclr/marshal_cppstd.h> // ��� �������������� ����� std::string � System::String^

namespace EdProgs {
    System::String^ GetConnectionString();

    System::String^ GetDocumentsFolder();

    
}