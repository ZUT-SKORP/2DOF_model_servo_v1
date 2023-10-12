// void writeRandomPosToFile() {
    
//     file = SD.open("data.txt", ios::out);
//     if (file.is_open()) {
//         char modes[3] = {'L', 'R', 'B'};

//         srand(time(nullptr));
//         int m = rand() % 2;
//         file << modes[m];

//         int pos1 = rand % 180;
//         if (modes[m] == 'L' || modes[m] == 'R') {
//             file << pos1;
//             goto EXIT;
//         } 
//         else if (modes[m] == 'B') {
//             if (pos1 < 10) file <<0 << 0 << pos1;
//             else if (pos1 < 100) file << 0 << pos1;
//             else if (pos1 >= 100) file << pos2;

//             int pos2 = rand % 180;
//             if (pos2 < 10) file << 0 << 0 << pos2;
//             else if (pos2 < 100) file << 0 << pos2;
//             else if (pos2 >= 100) file << pos2;
//         }

//         EXIT:
//         file.close();
//     }
// }