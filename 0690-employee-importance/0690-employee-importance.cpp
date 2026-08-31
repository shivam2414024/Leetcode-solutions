/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void solve(vector<Employee*>& employees, int id, int& value) {
        for (int i = 0; i < employees.size(); i++) {

            if (employees[i]->id == id) {

                value += employees[i]->importance;

                if (employees[i]->subordinates.size() == 0)
                    return;

                for (int j = 0; j < employees[i]->subordinates.size(); j++) {
                    solve(employees, employees[i]->subordinates[j], value);
                }

            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int value = 0;
        solve(employees, id, value);
        return value;
    }
};