#include <windows.h> 
#include <tchar.h>
#include <stdio.h> 
#include <bits/stdc++.h>

#define bufferSize 4096

HANDLE engine_read_out = NULL;
HANDLE engine_read_in = NULL;
HANDLE engine_write_in = NULL;
HANDLE engine_write_out = NULL;
HANDLE process;

bool connectEngine(std::string PATH) {
    TCHAR l[] = TEXT("Engine/stockfish_13.exe");
    SECURITY_ATTRIBUTES sa;
    STARTUPINFO s;
    PROCESS_INFORMATION p;
    bool connected = false;
    ZeroMemory(&p, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&s, sizeof(STARTUPINFO));
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    CreatePipe(&engine_read_in,&engine_read_out,&sa,0);
    CreatePipe(&engine_write_in,&engine_write_out,&sa,0);
    s.hStdOutput = engine_write_out;
    s.hStdError = engine_write_out;
    s.hStdInput = engine_read_in;
    connected = CreateProcess(NULL,l,NULL,NULL,TRUE,0x00000010,NULL,NULL,&s,&p);
    process = p.hProcess;
    if(!connected) {
        std::cout << "Not connected";
        return false;
    }
    return true;
}
void demoWrite() {
    std::cout << "Inside Demo" << std::endl;
    DWORD read;
    char BUFFER[150];
    std::string pos = "position startpos moves e2e4\n go depth 20\n";
    ReadFile(engine_write_out,BUFFER,150,&read,NULL);
    WriteFile(engine_read_in,pos.c_str(),sizeof(pos),&read,NULL);
}
std::string bestmove(std::string move) {
    std::string pos = "position startpos moves " + move + "\ngo depth 20\n";
    WriteFile(engine_write_out,pos.c_str(),sizeof(pos),NULL,NULL);
}
bool disconnectEngine() {
    if(TerminateProcess(process,0) && CloseHandle(process))
        return true;
    return false;
}