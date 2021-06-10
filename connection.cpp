#include <windows.h> 
#include <tchar.h>
#include <stdio.h> 
#include <bits/stdc++.h>
#define bufferSize 2048

HANDLE engine_read_out = NULL;
HANDLE engine_read_in = NULL;
HANDLE engine_write_in = NULL;
HANDLE engine_write_out = NULL;
HANDLE process;
BYTE buffer[bufferSize];

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
    CreatePipe(&engine_read_in,&engine_write_in,&sa,0);
    CreatePipe(&engine_read_out,&engine_write_out,&sa,0);
    s.dwFlags = STARTF_USESTDHANDLES;
    s.hStdOutput = engine_read_out;
    s.hStdError = engine_read_out;
    s.hStdInput = engine_read_in;
    connected = CreateProcess(NULL,l,NULL,NULL,TRUE,0x00000010,NULL,NULL,&s,&p);
    if(!connected) {
        std::cout << "Not connected";
        return false;
    }
    process = p.hProcess;
    return true;
}
void demoWrite() {
    std::string demo;
    DWORD write, read, available;
    std::string pos = "position startpos moves e2e4\ngo depth 20\n";
    WriteFile(engine_write_in,pos.c_str(),pos.length(),&write,NULL);
    PeekNamedPipe(engine_read_out,&buffer,bufferSize,&read,&available,NULL);
    do {
        ZeroMemory(buffer,bufferSize);
        if(!ReadFile(engine_write_out,buffer,bufferSize,&read,NULL) || !read)
            break;
        buffer[read] = 0;
        demo += (char *)(buffer);
    }while(read >= bufferSize);
    std::cout << demo << std::endl;
}
std::string bestmove(std::string move) {
    std::string pos = "position startpos moves " + move + "\ngo depth 20\n";
    WriteFile(engine_write_out,pos.c_str(),sizeof(pos),NULL,NULL);
}
bool disconnectEngine() {
    CloseHandle(engine_read_in);
    CloseHandle(engine_read_out);
    CloseHandle(engine_write_in);
    CloseHandle(engine_write_out);
    if(TerminateProcess(process,0) && CloseHandle(process))
        return true;
    return false;
}