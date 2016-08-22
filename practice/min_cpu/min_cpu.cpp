#include <cstdio>
const int N_CPU = 5;
const int LIMIT_TIME = 10;
int abs(int first, int second);
int getUsedCpu(bool *cpuUsed);
bool canAssign(int *cpu, bool *cpuUsed, int diffArrTime, int procTime);
int main() {
    // 입력은 첫 줄에 패킷 개수
    // 이 후 패킷 개수 라인 만큼 (도착시간 처리시간) 으로 입력 받음
    // 입력 예시
    // 5
    // 1 6
    // 2 6
    // 3 6
    // 4 6
    // 5 6
    int nPacket = 0;
    scanf("%d", &nPacket);

    int *cpu = new int[N_CPU];
    bool *cpuUsed = new bool[N_CPU];
    // 1. 입력이 들어오면 이전 패킷 도착 시간과 현재 패킷 도착 시간 차의 절대 값 구함
    // 2. 1에서 구한 값을 cpu 에서 빼줌(음수로 되면 0으로 변경)
    // 3. cpu 의 남은 시간 + 현재 패킷 처리 시간이 가능하면 cpu 남은 시간 없데이트(시간 업데이트와 함께 cpuUsed 는 1로 업데이트)
    // 4. 불가능 하면 다음 cpu 확인
    // 5. 모든 패킷에 대해서 처리한 하 cpuUsed 의 1 을 카운팅하여 결과 출력
    int result = 0;
    int prevPackArrTime = 0;
    for(int i = 0; i < nPacket; i++) {
        int currPackArrTime = 0;
        int currPackProcTime = 0;
        scanf("%d %d", &currPackArrTime, &currPackProcTime);

        if(!canAssign(cpu, cpuUsed, abs(prevPackArrTime, currPackArrTime), currPackProcTime)) {
            result = -1;
            break;
        }

        prevPackArrTime = currPackArrTime;
    }

    if(result == -1) {
        printf("-1\n");
    }
    else {
        printf("%d\n", getUsedCpu(cpuUsed));
    }

    delete []cpu;
    delete []cpuUsed;

    return 0;
}
int abs(int first, int second) {
    int result = first - second;
    if(result < 0) result *= -1;
    return result;
}
int getUsedCpu(bool *cpuUsed) {
    int count = 0;
    for(int i = 0; i < N_CPU; i++) {
        count += cpuUsed[i];
    }
    return count;
}
bool canAssign(int *cpu, bool *cpuUsed, int diffArrTime, int procTime) {
    bool isAssigned = false;
    for(int i = 0; i < N_CPU; i++) {
        cpu[i] -= diffArrTime;
        if(cpu[i] < 0) cpu[i] = 0;
        if(!isAssigned && cpu[i] + procTime <= LIMIT_TIME) {
            isAssigned = true;
            cpu[i] += procTime;
            cpuUsed[i] = true;
        }
    }

    return isAssigned;
}
