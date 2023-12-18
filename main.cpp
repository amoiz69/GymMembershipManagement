#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

// Function to generate a unique member ID
int generateMemberID()
{
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    return rand() % 10000 + 1000;              // Generate a random member ID between 1000 and 9999
}

// Member class to store member info
class Member
{
public:
    int memberID;
    string name;
    double height;
    double weight;
    string membershiptype;
    string billingdate;
    double amountPaid;
    string password;

    // Default constructor
    Member() : memberID(0), height(0.0), weight(0.0), membershiptype(""), billingdate(""), amountPaid(0.0), password("") {}

    // Parameterized constructor
    Member(int ID, const string &n, double h, double w, const string &mtype, const string &bDate, double amount, const string &pwd)
        : memberID(ID), name(n), height(h), weight(w), membershiptype(mtype), billingdate(bDate), amountPaid(amount), password(pwd) {}

    // Display Member information
    void DisplayMemberInfo() const
    {
        cout << "Member ID: " << memberID << endl;
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
    vector<string> complaints;

public:
    // Add a new member to the gym
    void AddMember(const Member &member)
    {
        members.push_back(member);
    }

    // Getter function to access the members vector
    const vector<Member> &GetMembers() const
    {
        return members;
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

    // Function to add complaints
    void AddComplaints(const string &complaint)
    {
        complaints.push_back(complaint);
    }

    // Function to display Complaints
    void displayComplaints() const
    {
        if (complaints.empty())
        {
            cout << "No complaints recorded." << endl;
        }

        cout << "List of Complaints: " << endl;
        for (const auto &complaint : complaints)
        {
            cout << "--------------------------\n";
            cout << complaint << "\n";
            cout << "--------------------------\n";
        }
    }
};

int main()
{
    // Create a gym object
    Gym gym;

    // Add some sample members
    Member member1(6969, "Abdul Moiz", 180.0, 75.0, "Gold", "2023-01-01", 200.0, "moiz123");
    Member member2(2222, "Fakhir", 179.0, 70.0, "Silver", "2023-05-01", 150.0, "fakhir123");

    // Add those members to the gym
    gym.AddMember(member1);
    gym.AddMember(member2);

    int entrance_val, admin_choice;
    int adminPass = 123456;
    int adminpass_attempt;
    cout << "Welcome to The Gym Management System: " << endl;
    cout << "Type 1 to login as Admin and 2 to login as a member " << endl;
    cin >> entrance_val;

    // Add some sample complaints
    gym.AddComplaints("Equipment not properly mantained ");
    gym.AddComplaints("Lack of cleanliness in the changing room ");

    // Variables for the new member the admin will add
    string newmember_name, newmember_membershiptype, newmember_billingdate, newmember_password;
    double newmember_weight, newmember_height, newmember_billingamount;
    int newmember_memberID;
    Member new_member;

    // Case for choice between admin and User End
    switch (entrance_val)
    {
        // Case for Login as an admin
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
            // Case for Displaying all the members
            case 1:
                gym.DisplayallMembers();
                break;
            // Case for adding a member
            case 2:
                newmember_memberID = generateMemberID();
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
                cout << "Choose a password which is at least 8 characters long!" << endl;
                cin >> newmember_password;
                new_member = Member(newmember_memberID, newmember_name, newmember_height, newmember_weight, newmember_membershiptype, newmember_billingdate, newmember_billingamount, newmember_password);
                gym.AddMember(new_member);
                cout << "Member added Successfully! " << endl;
                cout << "Your Member ID is " << newmember_memberID << ".Remember it for future reference! " << endl;
                cout << "Here is the updated member list" << endl;
                gym.DisplayallMembers();
                break;

            // Case for displaying the Complaints
            case 3:
                gym.displayComplaints();
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
    // Case for login as a user
    case 2:
        string user_memberid, user_password;
        cout << "Please Enter your Member ID: " << endl;
        cin >> user_memberid;
        cout << "Enter your password";
        cin >> user_password;

        // Flag to check if a member with matching credentials is found
        bool memberFound = false;

        // Iterate through the members to check credentials
        for (const auto &member : gym.GetMembers())
        {
            if (to_string(member.memberID) == user_memberid && member.password == user_password)
            {
                // Matching credentials found
                memberFound = true;
                cout << "Welcome, " << member.name << "!" << endl;

                break;
            }
        }

        // If no matching credentials are found
        if (!memberFound)
        {
            cout << "Incorrect Member ID or password. Please try again." << endl;
        }

        break;

        // default:
        // cout << "Wrong Input.Try Again!";

        // break;
    }
}
