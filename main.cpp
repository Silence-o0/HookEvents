#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <map>

using namespace std;

map<char, char> key_map = { {KEY_0, '0'}, {KEY_1, '1'},
                            {KEY_2, '2'}, {KEY_3, '3'},
                            {KEY_4, '4'}, {KEY_5, '5'},
                            {KEY_6, '6'}, {KEY_7, '7'},
                            {KEY_8, '8'}, {KEY_9, '9'},
                            {KEY_A, 'a'}, {KEY_B, 'b'},
                            {KEY_C, 'c'}, {KEY_D, 'd'},
                            {KEY_E, 'e'}, {KEY_F, 'f'},
                            {KEY_G, 'g'}, {KEY_H, 'h'},
                            {KEY_I, 'i'}, {KEY_J, 'j'},
                            {KEY_K, 'k'}, {KEY_L, 'l'},
                            {KEY_M, 'm'}, {KEY_N, 'n'},
                            {KEY_O, 'o'}, {KEY_P, 'p'},
                            {KEY_Q, 'q'}, {KEY_R, 'r'},
                            {KEY_S, 's'}, {KEY_T, 't'},
                            {KEY_U, 'u'}, {KEY_V, 'v'},
                            {KEY_W, 'w'}, {KEY_X, 'x'},
                            {KEY_Y, 'y'}, {KEY_Z, 'z'} };

int main() {
    input_event event{};
    int ev_num;
    cin >> ev_num;
    string mem_f = "/dev/input/event" + to_string(ev_num);
    int file = open(mem_f.c_str(), O_RDONLY);
    while(1) {
        read(file, &event, sizeof(event));
        if (event.type == EV_KEY and event.value == 1) {
            cout << key_map[event.code] << endl;
        }
    }
}
