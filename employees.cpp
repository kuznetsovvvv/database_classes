#include "employees.h"

employees::employees() {
        name = "";
        age = 0;
        pol = "";
        experience = 0;
        salary = 0;
        hoursweek = 0;
    }
employees::employees(std::string name, int age, string pol, double experience, int salary, int hoursweek) {
        this->name = name;
        this->age = age;
        this->pol = pol;
        this->experience = experience;
        this->salary = salary;
        this->hoursweek = hoursweek;
    }

    bool employees::operator<(const employees& other) const {
        return name < other.name;
    }

    void employees::edit_data() {
        std::string tmp = "";
        cout << "��� ������ ��������? (Name, Age, Pol, Experience, Salary, Hoursweek)" << endl;
        cin >> tmp;

        if (tmp == "Name" || tmp == "name") {
            cout << "������� ����� ���: ";
            cin >> name;
            cout << "������ ���������� ���������!\n";
        }
        else if (tmp == "Age" || tmp == "age") {
            cout << "������� ����� �������: ";
            cin >> age;
            cout << "������ ���������� ���������!\n";
        }
        else if (tmp == "Pol" || tmp == "pol") {
            cout << "������� ����� ���: ";
            cin >> pol;
            cout << "������ ���������� ���������!\n";
        }
        else if (tmp == "Experience" || tmp == "experience") {
            cout << "������� ����� ����: ";
            cin >> experience;
            cout << "������ ���������� ���������!\n";
        }
        else if (tmp == "Salary" || tmp == "salary") {
            cout << "������� ����� ��������: ";
            cin >> salary;
            cout << "������ ���������� ���������!\n";
        }
        else if (tmp == "Hoursweek" || tmp == "hoursweek") {
            cout << "������� ����� ���������� ����� � ������: ";
            cin >> hoursweek;
            cout << "������ ���������� ���������!\n";
        }
        else {
            cout << "�� ����� �������� ������, ������� �� ��������� � ����������!\n";
        }
    }

    void employees::addemployee(std::set<employees>& employees_list) {
        string tmp5="";
        int employee_count = 0;
        cout << "�������, ������� ����������� �� ������ ��������? ";
        cin >> tmp5;
        if (all_of(tmp5.begin(), tmp5.end(), ::isdigit)) {
            employee_count = stoi(tmp5);
            cin.ignore();
            for (int i = 0; i < employee_count; ++i) {
                string name = "", pol = "";
                int age = 0, salary = 0, hoursweek = 0;
                double experience = 0;
                
                string tmp1 = "", tmp2 = "", tmp3 = "", tmp4 = "";

                cout << "������� ��� ����������: " << i + 1 << ": ";
                if (i > 0) {
                    cin.ignore();
                }
                getline(cin, name);
                do {
                    
                    cout << "������� ������� ����������: ";
                    cin >> tmp1;
                    if (all_of(tmp1.begin(), tmp1.end(), ::isdigit)) {
                        age = stoi(tmp1);
                        if (age <= 15 || age >= 120) {
                            cout << "������� ����������! ����������, ������� ������� �� 16 �� 119" << endl;

                        }
                    }
                    else {
                        cout << "������� ����� ���� �� �����, ������� ���������!\n";
                    } 
                } while (age <= 15 || age >= 120);

                cout << "������� ��� ����������(m/j): ";
                cin >> pol;


                do {
                    cout << "������� ����(����) ����������: ";
                    cin >> tmp2;
                    if (all_of(tmp2.begin(), tmp2.end(), ::isdigit)) {
                        experience = stoi(tmp2);
                        if (experience <= 0 || experience >= 80) {
                            cout << "����(����) ����� ���� �� �����!" << endl;
                        }
                    }
                    else {
                        cout << "���� ����� ���� �� �����, ������� ���������!\n";
                    }
                } while (experience <= 0 || experience >= 80);

                do {

                    cout << "������� �������� ����������: ";
                    cin >> tmp3;
                    if (all_of(tmp3.begin(), tmp3.end(), ::isdigit)) {
                        salary = stoi(tmp3);
                        if (salary <= 0 || salary >= 4000000) {
                            cout << "�������� ����� ���� �� �����!" << endl;
                        }
                    }
                    else {
                        cout << "�������� ����� ���� �� �����, ������� ���������!\n";
                    } 
                } while (salary <= 0 || salary >= 4000000);

                do {
                    cout << "������� ���� ������ � ������ ����������: ";
                    cin >> tmp4;
                    if (all_of(tmp4.begin(), tmp4.end(), ::isdigit)) {
                        hoursweek = stoi(tmp4);
                        if (hoursweek > 40) {
                            cout << "������� �� ����� �������� ����� 40 ����� � ������ �� ������!" << endl;
                        }
                    }
                    else {
                        cout << "������� ���� ������ ���������!\n";
                    } 
                } while (hoursweek <= 0 || hoursweek > 40);
                employees new_employee(name, age, pol, experience, salary, hoursweek);
                employees_list.insert(new_employee);
            }
            cout << "���������� ���������!\n";
        }
        else {
            cout << "������� ���������� �����!\n";
        }
    }



    void employees::delete_employee(std::set<employees>& employees_set) {
        try {
            if (!employees_set.empty()) {

                cout << "������� ����� ���������� ��� ��������: ";
                int index;
                cin >> index;
                if (index >= 1 && index <= employees_set.size()) {
                    auto it = employees_set.begin();
                    std::advance(it, index - 1); // ���������� �������� �� ������ �������
                    employees_set.erase(it); // ������� ���������� �� set
                    std::cout << "��������� �" << index << " ������!\n";
                }
                else {
                    throw std::out_of_range("�������� ����� ����������! ���������� ��������: 1-" + std::to_string(employees_set.size()));
                }
            }
            else {
                throw std::runtime_error("������ ����������� ����!");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "������: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "������: " << e.what() << std::endl;
        }
    }


    void employees::print() const {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Pol: " << this->pol << endl;
        cout << "Experience: " << this->experience << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "Hoursweek: " << this->hoursweek << endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
 
