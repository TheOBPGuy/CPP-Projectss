#include <iostream>
#include <vector>

using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    vector<int> res;
    for (int i = 0; i < grades.size(); i++) {
        int firstG = grades[i];
        if ((firstG < 40) || (firstG % 5 == 0)) {
            if (firstG < 38) {
                res.push_back(firstG);
            } else {
                if (firstG < 40) {
                    res.push_back(40);
                } else {
                    res.push_back(firstG);
                }
            }
        } else {
            bool condition = true;
            int originalfirst = firstG;
            int count = 0;
            while (condition) {
                firstG++;
                count++;
                if (firstG % 5 == 0) {
                    condition = !condition;
                    if (count < 3) {
                        res.push_back(firstG);
                    } else {
                        res.push_back(originalfirst);
                    }  
                }
                
            }
        }
    }
    return res;
}

int main() {

    vector<int> grades;
    //vector<int> res = gradingStudents(grades);
    int count;
    cin >> count;
    for(int i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        grades.push_back(temp);
    }
    vector<int> res = gradingStudents(grades);
    cout << "+======================\n"; 
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
    return 0;
}