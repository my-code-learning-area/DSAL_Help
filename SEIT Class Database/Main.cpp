#include <iostream>
#include <string.h>
#include <conio.h>
#include <cmath>

using namespace std;

struct student {
    int roll;
    float sgpa;
    string name;
};
class se {
    student s[100], temp;
private:
    int d;
public:
    int n;
    se() {
    	d = 0;
	}
     
	void getdata() {
        // int n;
        cout << "ENTER NO OF STUDENTS" << endl;
        cin >> n;
        cout << "ENTER DETAILS" << endl;
        for (int i = d; i <d+n; i++) {
            cout<<"\nEnter the roll Number : ";
            cin >> s[i].roll;
            cout<<"Enter name of student : ";
            cin>>s[i].name;
            cout<<"Enter sgpa of the student : ";
            cin>>s[i].sgpa;
            int c = getchar();
        }d=d+n;
    }

    void display() {
        cout << "\nROll NO\t\tName\t\tSGPA";
        for (int i = 0; i <d; i++) {
            cout << "\n"
                 << s[i].roll << "\t\t" << s[i].name << "\t\t" << s[i].sgpa;
        }
        cout<<endl;
    }

    void duplicate() {
        for (int i=0;i<d;i++) {
            for (int j=i+1;j<d;j++) {
                if (s[i].roll == s[j].roll) {
                    cout<<"\n\t"<<s[i].roll<<"  This roll number already exists\n\t";
                    break;
                }
            }
            break;
        }
    }

    void sortByName() { //selection sort
        int j = 0;
        for (int i = 0; i <d; i++)
        {
            int tem = s[i].roll;
            string tem_name = s[i].name;
            double temp_sgpa = s[i].sgpa;
            j = i + 1;
            while (j < n){
                if (s[j].name[0] < tem_name[0])
                {
                    tem = s[j].roll;
                    tem_name = s[j].name;
                    temp_sgpa = s[j].sgpa;
                    swap(s[i], s[j]);
                }
                j++;
            }
            s[i].name = tem_name;
            s[i].roll = tem;
            s[i].sgpa = temp_sgpa;
        }
        cout << "DATABASE SORTED ALPHABETICALLY" << endl;
    }


    void sortByRoll() { //bubble sort
        int i;
        for (i = 0; i <d; i++) {
            for (int j = i + 1; j < d; j++) {
                if (s[i].roll >= s[j].roll) {
                    temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                }
            }
        }
        cout << "DATABASE SORTED ON THE BASIS OF ROLL NO" << endl;
    }
    
    void sgpaSearch() { // search
        float k;
        cout << "ENTER THE SGPA YOU WANT TO SEARCH : ";
        cin >> k;
        for (int i = 0; i <d; i++) {
            if (s[i].sgpa == k) {
                cout << "ROll NO\t\tName\t\tSGPA";
                cout << "\n"
                     << s[i].roll << "\t\t" << s[i].name << "\t\t" << s[i].sgpa;
                cout << endl
                     << endl;
            }
        }
    }
};

int main() {
    se p;
    int ch;
    p.getdata();
    p.duplicate();
    p.display();
    do {
        cout << "\n----------------MENU----------------\n";
        cout << " 1.Display\n";
        cout << " 2.Input and Display \n";
		cout << " 3.Sort by ROll no (Bubble sort) \n"; // 1
		cout << " 4.Sort by Name (selection sort) \n"; // 2
		cout << " 5.Sgpa Search\n"; // 3
		cout << " 6.Exit\n";
		cout << "Enter Your Choice: >\t";
        cin >> ch;
        switch (ch) {
    	case 1:
    		p.display();
    		break;
        case 2:
            p.getdata();
            p.duplicate();
            p.display();
            break;

        case 3:
            p.sortByRoll();
            p.display();
            break;

        case 4:
            p.sortByName();
            p.display();
            break;

        case 5:
            p.sgpaSearch();
            break;

        case 6:
            exit(0);
        }
    }
    while(ch!=9);
    return 0;
}
