#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;     // (시간, 분)
typedef tuple<string, int, int, bool> tsiib;    // (차량 번호, 누적 시간, 요금, 출차 여부)

// 차량번호 오름차순으로 sort 하기 위한 함수
bool Compare(tsiib a, tsiib b)
{
    return stoi(get<0>(a)) < stoi(get<0>(b));
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<string> carNumbers;      // 입차한 차량 번호 목록
    vector<pii> inTime;             // 차량들의 가장 최근 입차 시간 목록
    vector<tsiib> totalData;        // 모든 차량의 (차량 번호, 누적시간, 요금, 출차 여부)
    vector<int> result;             // 모든 차량 요금 목록

    int recordsLen = records.size();
    for (int i = 0; i < recordsLen; i++)
    {
        string numSubStr = records[i].substr(6, 4);        // 차량 번호 부분 추출
        int hourSubStr = stoi(records[i].substr(0, 2));    // 시간 부분 추출
        int minSubStr = stoi(records[i].substr(3, 2));     // 분 부분 추출
        string passType = records[i].substr(11, 3);        // 통과 타입 부분 추출

        // carNumbers에 현재 차례 차량 번호 없으면
        if (find(carNumbers.begin(), carNumbers.end(), numSubStr) == carNumbers.end())
        {
            // 따로 마련된 vector에 차량 번호 및 입차 시간 저장
            carNumbers.push_back(numSubStr);
            inTime.push_back(pii(hourSubStr, minSubStr));
            totalData.push_back(tsiib(numSubStr, 0, 0, false));
        }
        // 이미 들어왔던 번호의 차량이면
        else
        {
            // iterator끼리 빼면 두 iterator 사이의 거리(distance)가 반환 == 찾는 원소의 인덱스
            int index = find(carNumbers.begin(), carNumbers.end(), numSubStr) - carNumbers.begin();
            
            // IN이면 입차 시간 갱신
            if (passType == "IN")
            {
                inTime[index] = pii(hourSubStr, minSubStr);
                get<3>(totalData[index]) = false;   // 출차 안 했음 표시
            }
                
            // OUT이면 출차 시간 - 입차 시간 해서 시간 누적
            else
            {
                int totalTime = get<1>(totalData[index]); // 이전에 저장되어있던 총 누적 시간
                // 이전 누적 시간에 현재 (출차시간 - 입차시간) 누적 및 출차 표시
                totalData[index] = tsiib(numSubStr, totalTime + ((hourSubStr - get<0>(inTime[index])) * 60) + minSubStr - get<1>(inTime[index]), 0, true);  
            }
        }
    }

    // 마지막으로 출차 안 한 차 없는지 확인해서 있으면 최종 출차 23:59로 처리 및 요금 계산
    int totalDataLen = totalData.size();
    for (int i = 0; i < totalDataLen; i++)
    {
        if(!get<3>(totalData[i]))
            get<1>(totalData[i]) += ((23 - get<0>(inTime[i])) * 60 + 59 - get<1>(inTime[i]));
        
        // 기본 시간보다 적게 있었으면 기본 요금만 부과, 아니면 기본 요금 + 단위 요금 부과
        if (get<1>(totalData[i]) < fees[0])
            get<2>(totalData[i]) = fees[1];
        else
            get<2>(totalData[i]) = fees[1] + ceil((get<1>(totalData[i]) - fees[0]) / (float)fees[2]) * fees[3];
    
    }

    // 차량 번호 오름차순으로 totalData 벡터 정렬
    sort(totalData.begin(), totalData.end(), Compare); 

    // result에 차례대로 차량 별 요금 삽입
    for (int i = 0; i < totalDataLen; i++)
    {
        result.push_back(get<2>(totalData[i]));
        cout << result[i] << endl;
    }

    return result;
}