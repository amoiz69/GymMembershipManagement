#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

// Member class to store member info
class Member
{
public:
    string name;
    double height;
    double weight;
    string membershiptype;
    string billingdate;
    double amountPaid;

    // Default constructor
    Member() : name(""), height(0.0), weight(0.0), membershiptype(""), billingdate(""), amountPaid(0.0) {}

    // Parameterized constructor
    Member(const string &n, double h, double w, const string &mtype, const string &bDate, double amount) : name(n), height(h), weight(w), membershiptype(mtype), billingdate(bDate), amountPaid(amount) {}

    // Display Member information
    void DisplayMemberInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Membership Type: " << membershiptype << endl;
        cout << "Billing Date: " << billingdate << endl;
        cout << "Amount Paid: $" << amountPaid << endl;
    }
};

// Gym Class to manage members
class Gym
{
private:
    vector<Member> members;

public:
    // Add a new member to the gym
    void AddMember(const Member &member)
    {
        members.push_back(member);
        cout << "Member added successfully!" << endl;
    }

    // Record Member Attendance
    void RecordAttendance(const string &memberName)
    {
        for (auto &member : members)
        {
            if (member.name == memberName)
            {
                time_t now = time(0);
                cout << "Attendance Recorded for " << memberName << " on " << ctime(&now);
                return;
            }
        }
        cout << "Member not found" << endl;
    }

    // Display Information for all members
    void DisplayallMembers() const
    {
        if (members.empty())
        {
            cout << "There are no members in the gym: " << endl;
        }
        cout << "List of members: " << endl;
        for (const auto &member : members)
        {
            cout << "-------------------------------------" << endl;
            member.DisplayMemberInfo();
            cout << "-------------------------------------" << endl;
        }
    }
};

int main()
{
    // Create a gym object
    Gym gym;

    // Add some sample members
    Member member1("Abdul Moiz", 180.0, 75.0, "Gold", "2023-01-01", 200.0);
    Member member2("Fakhir", 179.0, 70.0, "Silver", "2023-05-01", 150.0);

    // Add those members to the gym
    gym.AddMember(member1);
    gym.AddMember(member2);

    int entrance_val, admin_choice;
    int adminPass = 123456;
    int adminpass_attempt;
    cout << "Welcome to The Gym Management System: " << endl;
    cout << "Type 1 to login as Admin and 2 to login as a member " << endl;
    cin >> entrance_val;

    // Variables for the new member the admin will add
    string newmember_name, newmember_membershiptype, newmember_billingdate;
    double newmember_weight, newmember_height, newmember_billingamount;
    Member new_member;

    // Case for choice between admin and User End
    switch (entrance_val)
    {
    case 1:
        cout << "Enter the Admin Password" << endl;
        cin >> adminpass_attempt;
        if (adminpass_attempt == adminPass)
        {
            cout << "Enter 1 to display members \nEnter 2 to add a new member \nEnter 3 to check Complaints " << endl;
            cin >> admin_choice;
            // Case for the choice the admin makes
            switch (admin_choice)
            {
            case 1:
                gym.DisplayallMembers();
                break;
            case 2:
                cout << "Enter the name of the new member: " << endl;
                cin >> newmember_name;
                cout << "Enter the member's height in cm: " << endl;
                cin >> newmember_height;
                cout << "Enter the new member's weight in kg: " << endl;
                cin >> newmember_weight;
                cout << "Choose a membership type:\nSilver\nGold\nPlatinum" << endl;
                cin >> newmember_membershiptype;
                if (newmember_membershiptype == "Silver")
                {
                    newmember_billingamount = 50.0;
                    cout << "Your bill is $" << newmember_billingamount << endl;
                }
                else if (newmember_membershiptype == "Gold")
                {
                    newmember_billingamount = 100.0;
                    cout << "Your bill is $" << newmember_billingamount << endl;
                }
                else
                {
                    newmember_billingamount = 150.0;
                    cout << "Your bill is $" << newmember_billingamount << endl;
                }
                cout << "Enter today's date: " << endl;
                cin >> newmember_billingdate;
                new_member = Member(newmember_name, newmember_height, newmember_weight, newmember_membershiptype, newmember_billingdate, newmember_billingamount);
                gym.AddMember(new_member);
                cout << "Here is the updated member list" << endl;
                gym.DisplayallMembers();
                break;

            default:
                cout << "Wrong Input.Try Again!";
                break;
            }
        }
        else
        {
            cout << "Wrong Password.Try Again!" << endl;
            cin >> adminpass_attempt;
        }

        break;
    case 2:

        break;

    default:
        cout << "Wrong Input.Try Again!";
        break;
    }
}
