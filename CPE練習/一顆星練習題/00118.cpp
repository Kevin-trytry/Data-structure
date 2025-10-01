#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y; // 地圖右上角座標（左下角預設是 0,0）
    int initial_x, initial_y; // 機器人起始座標
    char direction; // 機器人起始面向方向（N, E, S, W）

    // 讀取地圖大小（最大座標）
    cin >> x >> y;

    // 地圖記憶每個位置是否曾有機器人在此 LOST，記下當時的方向（用來避免未來的機器人在同方向從這裡走出去）
    char map[x + 1][y + 1];
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            map[i][j] = 'O'; // O 代表沒人從這邊走失過
        }
    }

    // 一直讀入機器人資訊直到 EOF
    while (cin >> initial_x >> initial_y >> direction) {
        string walk_ways; // 指令序列
        cin >> walk_ways;
        int flag = 1; // 是否 LOST（1 = 沒有 LOST，0 = LOST）

        // 依序執行指令
        for (int i = 0; i < walk_ways.size(); i++) {
            // 如果這個點已經有相同方向 LOST 過，這次遇到 'F' 就直接略過
            if (map[initial_x][initial_y] == direction && walk_ways[i] == 'F') continue;

            // 根據目前面向的方向與當前指令執行操作
            switch (direction) {
                case 'N':
                    if (walk_ways[i] == 'R') direction = 'E';
                    else if (walk_ways[i] == 'L') direction = 'W';
                    else if (walk_ways[i] == 'F') initial_y += 1;
                    break;
                case 'E':
                    if (walk_ways[i] == 'R') direction = 'S';
                    else if (walk_ways[i] == 'L') direction = 'N';
                    else if (walk_ways[i] == 'F') initial_x += 1;
                    break;
                case 'W':
                    if (walk_ways[i] == 'R') direction = 'N';
                    else if (walk_ways[i] == 'L') direction = 'S';
                    else if (walk_ways[i] == 'F') initial_x -= 1;
                    break;
                case 'S':
                    if (walk_ways[i] == 'R') direction = 'W';
                    else if (walk_ways[i] == 'L') direction = 'E';
                    else if (walk_ways[i] == 'F') initial_y -= 1;
                    break;
            }

            // 判斷是否超出地圖邊界，若有就 LOST（且只會 LOST 一次，然後 break 掉）
            if (initial_x > x || initial_x < 0 || initial_y > y || initial_y < 0) {
                // 調整回邊界內，因為超出去了但要記錄你從哪個點出去的
                if (initial_x > x) initial_x = x;
                else if (initial_x < 0) initial_x = 0;
                if (initial_y > y) initial_y = y;
                else if (initial_y < 0) initial_y = 0;

                // 如果這個位置還沒有人 LOST 過，記下來，並標記 LOST
                if (map[initial_x][initial_y] == 'O') {
                    map[initial_x][initial_y] = direction; // 標記 LOST 的方向
                    cout << initial_x << " " << initial_y << " " << direction << " LOST" << endl;
                    flag = 0; // 標記已經 LOST
                    break; 
                }
                // 否則不處理，表示這裡已經有機器人從這邊 LOST 過，就略過這次前進
            }
        }

        // 如果沒 LOST，就正常輸出目前位置與方向
        if (flag) cout << initial_x << " " << initial_y << " " << direction << endl;
    }

    return 0;
}
