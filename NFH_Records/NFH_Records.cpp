// NFH_Records.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*    --------------------------------Always use in full screen for the best experience----------------------------------------------------------
            THE MEDICAL RECORDS OF NFH
    1 - SEARCH FOR A PATIENT --- (The Doctor Enters his name here so that any modification done in this session has his name attached to it)

    IF THE PATIENT IS NOT THERE
        --- ADD A NEW PATIENT
        --- GO BACK
    ELSE
            THEN THE ID OF THE PATIENT IS SOUGHT FOR AND IF IT POPS UP
                THE DETAILS LIKE
                    NAME:
                    SEX:
                    GENOTYPE:
                    BLOOD GROUP:
                    ALLERGIES:
                    
                    POP UP...
                THEN... RECORD OF PREVIOUS TREATMENTS POP UP IN A TABLE

                --S/N --- SYMPTOMS --- DIAGNOSIS --- TREATMENTS --- MEMBER OF HOSPITAL STAFF

                        1. FOLLOW UP CASE?
                                SELECT THE NUMBER OF THE CASE TO FOLLOW UP...(THEN CHOOSE WHAT YOU WOULD LIKE TO EDIT/ADD INFO... EITHER
                                    SYMPTOMS
                                    DIAGNOSIS
                                    TREATMENT 
                                    
                        2. NEW CASE...
                            SIMPLE ENTER THE 
                --S/N --- SYMPTOMS --- DIAGNOSIS --- TREATMENTS -------->

                        3. GO BACK
    2 - ADD A NEW PATIENT
            WHEN YOU WANT TO ADD A NEW PATIENT, JUST ASK FOR THE DETAILS ABOVE AND INPUT THEM INTO THE APPROPRIATE FILES

    3 - VIEW ALL PATIENTS.............VIEW ALL THE PATIENTS IN A WELL FORMATTED FORMAT WITH ALL THE BASIC INFORMATION ABOUT THEM

    4 - QUIT
****************************************************************************************************************************************************
*                                                   APROACH TO THE PROGRAMMING // PSEUDO CODE
*   1. Work on the display menu, which is like the engine house of the program
*   2. Then Implement the adding of a new patient first
*           1 .txt file will have the reg number and the basic details of all the patients (masterlist)
*                   NAME:
                    SEX:
                    GENOTYPE:
                    BLOOD GROUP:
                    ALLERGIES:
            Then there is a Patients folder---
                Here in this folder, once a patient is added to the hospital record, a file is opened automatically for him
                The name of the .txt file will be the reg number of the patient...
                This is where all the relevant information about the cases are stored...

                Implement --> List all patients...
    3. Then Implement "SEARCH FOR A PATIENT"
            --- Follow up case..(The Case availble )
                    Then Select the Case...The Case Appears on the screen
                        The Select if you want to
                            a. Edit the sympthon, diagnosis or treatment (If it is edited, the name of the two doctors will be present in the table)
                            b. Add... (Same as the above)
            --- New Case
                    Then add all the info required...
            --- Or Go Back
           There is always feedback like: Entry successful... ETC.....................

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <direct.h>
#include <vector>
#include <iomanip>


//Function Prototypes
void home();
int data_validation(int, int);
void quit();
void add_patient();
bool search_name(std::string,std::string);
bool search_id(std::string);
std::string capitalise(std::string);
std::string assign_num();
void view_all();


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

char quitter{ '1' };

int main()
{
    int succesful{}, patients{};
    succesful= _mkdir("NFH");
    patients = _mkdir("NFH/PATIENTS");

    home();
    

    return 0;
}

void home() {
    if (quitter != '0')
    {
        cout << "\t\t\t=======================================================================================================\n";
        cout << "\t\t\t|                                  N. F. H. MEDICAL RECORDS                                           | \n";
        cout << "\t\t\t=======================================================================================================\n";
        cout << "\t\t\t| 1 - SEARCH FOR A PATIENT                                                                            |\n";
        cout << "\t\t\t| 2 - ADD A NEW PATIENT                                                                               |\n";
        cout << "\t\t\t| 3 - VIEW ALL PATIENTS                                                                               |\n";
        cout << "\t\t\t| 4 - QUIT                                                                                            |\n";
        cout << "\t\t\t=======================================================================================================\n";
        int entry;
        entry = data_validation(1, 4);
        switch (entry)
        {
            case 1:
            {

            }break;

            case 2:
            {
                add_patient();
                home();
            }break;

            case 3:
            {

            }break;

            case 4:
            {
                quit();
                home();
            }break;
            default:
                break;
            }
    }

       
}

int data_validation(int min, int max) {
    string entry{};
    int number{};
    bool done{};

    do {
        cout << "ENTRY: ";
        cin >> entry;
        stringstream validator{ entry };
        if (validator >> number && (number>=min ||number<=max)) {
            done = true;
        }
        else {
            std::cout << "PLEASE ENTER A VALID OPTION\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (!done);
    return number;
}

void quit() {
    system("CLS");
    cout << "\t\t\t=======================================================================================================\n";
    cout << "\t\t\t|                                 GOOD - BYE FROM N. F. H.                                            | \n";
    cout << "\t\t\t=======================================================================================================\n";
    cout << endl << endl;
    quitter = '0';
}

void add_patient() {
    /*
         THE DETAILS LIKE
                    NAME:
                    SEX:
                    GENOTYPE:
                    BLOOD GROUP:
                    ALLERGIES:
    */
    system("CLS");

    string s_num{}, f_name{}, l_name{}, gender{}, genotype{}, bloodgroup{}, allergies{};
    int sex{}, geno{}, blood_gp{};
    std::ofstream out_file("NFH/MASTERLIST.txt", std::ios::app);

    cout << "HOW MANY PATIENTS WOULD YOU LIKE TO ADD?: ";
    bool done{ false };
    std::string entry;
    int number;
    do {
        cin >> entry;
        std::istringstream validator{ entry };
        if (validator >> number) {
            done = true;
        }
        else {
            cout << "KINDLY ENTER A VALID INPUT\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!done);
    cin.ignore(1, '\n');

    for (int i{ 0 }; i < number; i++) {
                                                                       
        cout << "\t\t\t==================================================\n";
        cout << "\t\t\t|                  PATIENT " << i +1<< "                     |\n";
        cout << "\t\t\t==================================================\n";
       

        s_num = assign_num(); //The serial number is automatically generated...
        out_file << s_num << "#";

       
       
        cout << "FIRST NAME: ";
        std::getline(cin, f_name);
        f_name = capitalise(f_name);
        out_file << f_name << "#"; //Writing Information to the Master list in the NFH Folder...
        cout << endl;

        cout << "LAST NAME: ";
        std::getline(cin, l_name);
        l_name = capitalise(l_name);
        out_file << l_name << "#";
        cout << endl;

        cout << "SEX \n1 - MALE\n2 - FEMALE\n";
        sex = data_validation(1, 2);
        if (sex == 1) {
            gender = "MALE";
            out_file << "MALE" << "#";
        }
        else {
            gender = "FEMALE";
            out_file << "FEMALE" << "#";
        }
        cout << endl;



        cout << "GENOTYPE: \n1 - AA\n2 - AS \n3 - SS\n";
        geno = data_validation(1, 3);
        if (geno == 1) {
            genotype = "AA";
        }
        else if (geno == 2) {
            genotype = "AS";
        }
        else {
            genotype = "SS";
        }
        cout << endl;
        out_file << genotype << "#";



        cout << "BLOOD GROUP\n1 - A+\n2 - O+\n3 - B+\n4 - AB+\n5 - A-\n6 - O-\n7 - B-\n8 - AB-\n";
        blood_gp = data_validation(1, 8);
        switch (blood_gp)
        {
        case 1:
        {
            bloodgroup = "A+";

        }break;

        case 2:
        {
            bloodgroup = "O+";

        }break;

        case 3:
        {
            bloodgroup = "B+";
        }break;

        case 4:
        {
            bloodgroup = "AB+";
        }break;

        case 5:
        {
            bloodgroup = "A-";
        }break;

        case 6:
        {
            bloodgroup = "O-";
        }
        break;

        case 7:
        {
            bloodgroup = "B-";
        }
        break;

        case 8:
        {
            bloodgroup = "AB-";
        }
        break;
        default:
            break;
        }
        cout << endl;
        out_file << bloodgroup << "#";

        cin.ignore(1, '\n');
        cout << "ENTER ALLERGIES\nPLEASE WRITE THE ALLERGIES SEPARATED BY A COMMA (IF MORE THAN 1)\nALLERGIES: ";
        std::getline(std::cin, allergies);
        allergies = capitalise(allergies);
        out_file << allergies << endl;

        //OPEN A FILE FOR THE PATIENT...
        std::string file_no = "NFH/PATIENTS/"+s_num + ".txt";
        std::ofstream out_file2(file_no, std::ios::app);
        out_file2 << s_num << "#" << f_name << "#" << l_name << "#" << gender << "#" << genotype << "#" << bloodgroup << "#" << allergies << endl;
        out_file2.close();
    }

  

    cout <<number << " PATIENTS HAVE BEEN SUCCESSFULLY ADDED\n\n";
    
    out_file.close();
}

std::string assign_num() {
    std::ifstream in_file;
    in_file.open("NFH/MASTERLIST.txt");
    
    int num{}, count{0};
    string line{}, c_line{}, c_num{}, r_num{}; //to represent the last line at every point in time
    while (getline(in_file, line)) {
        c_line = line;
        count++;
    }

    if (count == 0) { //If the document is empty, It means the person is the first on the list...
        return "0001";
    }

    //c_line upon exit of the while loop will then be the last line... which is what you want...
    std::istringstream sstream{ c_line };
    getline(sstream, c_num, '#');
    num = stoi(c_num);
    num++;

    r_num = std::to_string(num);
    
    if (num < 10) {
        r_num = "000" + r_num;
    }
    
    else if (num > 9 && num < 100) {
        r_num = "00" + r_num;
    }

    else if (num>99 && num < 999) {
        r_num = "0" + r_num;
    }

    else {}

    in_file.close();
    return r_num;
}

std::string capitalise(std::string word) {

    std::transform(word.begin(), word.end(), word.begin(), toupper);
    return word;
}

void view_all() {
    /*
                    NAME:
                    SEX:
                    GENOTYPE:
                    BLOOD GROUP:
                    ALLERGIES:
    
    */
    std::string line{}, f_name{}, l_name{}, sex{}, genotype{}, blood_group{}, allergies{};

    std::ifstream in_file;
    in_file.open("NFH/MASTERLIST.txt");

    cout << "\t\t\t=========================================================================================\n";
    cout << "|" << std::setw(7) << std::left << "S/N" << std::setw(15) << std::left << "FIRST NAME"
        << std::setw(15) << std::left << "LAST NAME" << std::setw(8) << std::left << "SEX"
        << std::setw(10) << std::left << "GENOTYPE" << std::setw(13) << std::left << "BLOOD GRP" <<
        std::setw(30) << std::left << "ALLERGIES" << "|\n";
    cout << "\t\t\t=========================================================================================\n";

    while (std::getline(in_file, line)) {
        std::vector<std::string> lists;
        std::string substr;
        std::istringstream s_stream{ line };
        while (s_stream.good()) {
            std::getline(s_stream, substr, '#');
            lists.push_back(substr);

            //Modify the content of the vectors here so that you can output the list ...
        }
    }

    in_file.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
