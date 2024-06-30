#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;
int likes1_1=2;int likes1_2=2;int likes1_3=2;
int likes2_1=2;int likes2_2=2;int likes2_3=2;
int likes3_1=2;int likes3_2=2;int likes3_3= 2;
int likes4_1=2;int likes4_2=2; int likes4_3=2;
int likes5_1=2;int likes5_2=2;int likes5_3=2;
string likes=" ";
string comments=" ";
static int counts=0;
class User {
public:
    string username;
    string Fname;
    string Lname;
    string password;
    string friend1, friend2, friend3;
    char** friends;
    //Post * post;
    User() {
        username = " ";
        Fname = " ";
        Lname = " ";
        password = " ";
    }
    User(string u, string n, string l, string p) {
        username = u;
        Fname = n;
        Lname = l;
        password = p;
    }
    void viewFriendsList(User* users)
    {
        cout << this->Fname << " " << this->Lname << " - Friends List" << endl;
        for (int i = 0; i < 5; i++)
        {
            if ((this->Fname == users[i].Fname) && (this->Lname == users[i].Lname)) {

                for (int j = 0; j < 5; j++)
                {
                    if (users[i].friend1 == users[j].Fname) {
                        cout << "u" << j + 1 << " - " << users[i].friend1 << endl;
                    }
                    if (users[i].friend2 == users[j].Fname) {
                        cout << "u" << j + 1 << " - " << users[i].friend2 << endl;
                    }
                    if (users[i].friend3 == users[j].Fname) {
                        cout << "u" << j + 1 << " - " << users[i].friend3 << endl;
                    }
                }
            }
        }
    }
    void setActivity()
    {
        cout<<this->Fname<<" "<<this->Lname<<" was celebrating birthday. (05/13/2023)\n";
        cout<<this->Fname<<" "<<this->Lname<<" got first job(09/13/2023)\n";
        cout<<this->Fname<<" "<<this->Lname<<" got his degree (02/12/2003)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was celebrating birthday of his mother.(05/12/2023)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was eating cake that he made for the first time.(12/19/2020)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was traveling to a new place.(05/13/2023)\n";
        cout<<this->Fname<<" "<<this->Lname<<"had contracted covid(03/26/2020)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was spending time with family.(05/13/2021)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was reading a good book.(09/01/2016)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was enjoying a vacation.(08/06/2013)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was attending a concert.(01/03/2023)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was celebrating a milestone.(03/17/2023)\n";
        cout<<this->Fname<<" "<<this->Lname<<"was condoling a loss.(11/25/2022)\n";
    }
};
void ReadDataFromFile(ifstream& inputFile, User* users, int Size)
{

    for (int i = 0; i < Size; i++)
    {
        inputFile >> users[i].username;
        inputFile >> users[i].Fname;
        inputFile >> users[i].Lname;
        inputFile >> users[i].password;

    }

}


class SocialMediaApp 
{
private:
    int noOfUsers;
public:
    User* users;
    SocialMediaApp() {
        noOfUsers = 0;
    }
    SocialMediaApp(int size) {
        noOfUsers = size;
    }

    User SetCurrentUser(User* users)
    {
        
        string userCurrent, passCurrent;
        User** Cuser = new User * [5];
        for (int k = 0; k < 5; k++)
        {
            Cuser[k] = new User;
        }
        cout << "Welcome to Social Media" << endl;
        cout << "Enter username: " << endl;
        cin >> userCurrent;
        for (int i = 0; i < 5; i++) {
            if (userCurrent == users[i].username) {
                while (true) {
                    cout << "Enter password: " << endl;
                    cin >> passCurrent;
                    if (passCurrent == users[i].password) {
                        Cuser[i][0] = users[i];
                        counts = i;
                        break;
                    }
                }
            }

        }
    
        
        // cout << "\n\t\tWelcome to social media !!" << Cuser[count][0].Fname << "\t\t" << endl;
        // printUser(Cuser[count][0]);
        // Cuser[count][0].viewFriendsList(users);
        // return Cuser[count][0];
        cout << "\n\t\tWelcome to social media !! " << users[counts].Fname << "\t\t" << endl;
        //printU`ser(users[counts]);
        users[counts].viewFriendsList(users);
        return users[counts];
    }
    void viewHome(User *user)
    {
            cout << "\n\n\t\tUser details \t\t\t\n";
            cout << "\nName: " << user->Fname << " " << user->Lname;
            cout << "\nUsername: " << user->username;
            cout << "\nQuote of the day: \n" << "\nReflecting on life's twists and " << "turns, finding beauty in its complexities;";
            cout << ", and embracing every moment with gratitude and resilience" << endl;
    }

};


void SetFriends(ifstream& inFile, User* users, int Size)
{

    for (int i = 0; i < Size; i++)
    {
        inFile >> users[i].friend1;
        inFile >> users[i].friend2;
        inFile >> users[i].friend3;


    }


}
void viewFriendsList(User* users)
{
    for (int i = 0; i < 5; i++) {
        cout << users[i].username << " " << users[i].Fname << " " << users[i].Lname << " " << users[i].password << "\n";
        cout << "Friends: " << users[i].friend1 << " " << users[i].friend2 << " " << users[i].friend3 << endl;

    }

}
class Page:public User{
public:
 
    int ID;
    string name;
    string owner;
    int likes1;
    int likes2;
    string post1;
    string post2;
    string comments1[3];
    string comments2[3];
    int *date1=new int[6];
    int *date2=new int[6];
    Page():User()
    {
        ID=0;
        name=" ";
        owner=" ";
        likes1=120;
        likes2=70;
        post1=" ";
        post2=" ";
        for (int i=0; i<3;i++)
        {
            comments1[i]=" ";
            comments2[i]=" ";
        }
        for (int i=0; i<6;i++)
        {
            int *date1=new int[6]{0};
            int *date2=new int[6]{0};
        }



    }
    void setPage1()
    {
        this->ID=1;
        this->name="Food Fusion ";
        this->owner="Asad Memon";
        this->ID=1;
        ifstream food;
        food.open("page1.txt");
        if (!(food.is_open()))
        {
            cout<<"error!\n";
        }
        else
        {
            getline(food,this->post1);
            food>>this->likes1;
            getline(food,this->comments1[0]);
            getline(food,this->comments1[1]);
            



        }
        ifstream food1;
        food1.open("page1_2.txt");
        if (!(food1.is_open()))
        {
            cout<<"error!\n";
        }
        else
        {
            getline(food1,this->post2);
            
            food1>>this->likes2;
            
            getline(food1,this->comments2[0]);
            getline(food1,this->comments2[1]);
            
            
            



        }
        

    }
    void setPage2()
    {
        this->ID=2;
        this->name="ESPN CRICINFO";
        this->owner="Simon King";
        ifstream cricket;
        cricket.open("page2.txt");
        if (!(cricket.is_open()))
        {
            cout<<"error!\n";
        }
        else
        {
            getline(cricket,this->post1);
            cricket>>this->likes1;
            getline(cricket,this->comments1[0]);
            getline(cricket,this->comments1[1]);



        }
        ifstream cricket1;
        cricket1.open("page2_2.txt");
        if (!(cricket.is_open()))
        {
            cout<<"error!\n";
        }
        else
        {
            

            getline(cricket1,this->post2);
            cricket1>>this->likes2;
            getline(cricket1,this->comments2[0]);
            getline(cricket1,this->comments2[1]);



        }


        
    }
    void setPage3()
    {
        this->ID=3;
        this->name="BBC NEWS";
        this->owner="John Reith";
        ifstream news;
        news.open("page3.txt");
        if (!(news.is_open()))
        {
            cout<<"error!\n";
        }
        else
        {

            getline(news,this->post1);
            news>>this->likes1;
            getline(news,this->comments1[0]);
            getline(news,this->comments1[1]);
            
        }
        ifstream news1;
        news1.open("page3.txt");
        if (!(news1.is_open()))
        {
            cout<<"error!\n";
        }
        else
        {
            getline(news1,this->post2);
            news1>>this->likes2;
            getline(news1,this->comments2[0]);
            getline(news1,this->comments2[1]);
        
        }
    }
    void viewPage()
    {
        cout<<"\nID: "<<this->ID;
        cout<<"\nName: "<<this->name;
        cout<<"\n Owner: "<<this->owner;
        cout<<this->post1<<endl;
        cout<<"\nLikes on this post: "<<this->likes1;
        cout<<"\nComments: "<<endl;
        cout<<"\t"<<this->comments1[0];
        cout<<"\n\t"<<this->comments1[1];
        cout<<"\n\t"<<this->comments1[2]<<endl;
        cout<<comments<<endl;
        cout<<this->post2<<endl;
        cout<<"Likes on this post: "<<this->likes2;
        cout<<"\nComments: "<<endl;
        cout<<"\t"<<this->comments2[0];
        cout<<"\n\t"<<this->comments2[1];
        cout<<"\n\t"<<this->comments2[2];  
        cout<<comments<<endl;    

    }
    ~Page() {
        delete[] date1;
        delete[] date2;
    }





};

class Post :public User,public Page {
public:
    string description1_1;
    string likesbyUser1_1_1;
    string likesbyUser1_1_2;
    string comments1_1;
    string description1_2;
    string likesbyUser1_2_1;
    string likesbyUser1_2_2;
    string comments1_2;
    string description1_3;
    string likesbyUser1_3_1;
    string likesbyUser1_3_2;
    string comments1_3;
    string description2_1;
    string likesbyUser2_1_1;
    string likesbyUser2_1_2;
    string comments2_1;
    string description2_2;
    string likesbyUser2_2_1;
    string likesbyUser2_2_2;
    string comments2_2;
    string description2_3;
    string likesbyUser2_3_1;
    string likesbyUser2_3_2;
    string comments2_3;
    string description3_1;
    string likesbyUser3_1_1;
    string likesbyUser3_1_2;
    string comments3_1;
    string description3_2;
    string likesbyUser3_2_1;
    string likesbyUser3_2_2;
    string comments3_2;
    string description3_3;
    string likesbyUser3_3_1;
    string likesbyUser3_3_2;
    string comments3_3;
    string description4_1;
    string likesbyUser4_1_1;
    string likesbyUser4_1_2;
    string comments4_1;
    string description4_2;
    string likesbyUser4_2_1;
    string likesbyUser4_2_2;
    string comments4_2;
    string description4_3;
    string likesbyUser4_3_1;
    string likesbyUser4_3_2;
    string comments4_3;
    string description5_1;
    string likesbyUser5_1_1;
    string likesbyUser5_1_2;
    string comments5_1;
    string description5_2;
    string likesbyUser5_2_1;
    string likesbyUser5_2_2;
    string comments5_2;
    string description5_3;
    string likesbyUser5_3_1;
    string likesbyUser5_3_2;
    string comments5_3;
    User* users;

    

    Post() :User() {
        description1_1 = " ";
        likesbyUser1_1_1 = "0 ";
        likesbyUser1_1_1 = " 0";
        comments1_1 = " ";
        description1_2 = "0 ";
        likesbyUser1_2_1 = "0 ";
        likesbyUser1_2_2 = " ";
        comments1_2 = " ";
        description1_3 = " ";
        likesbyUser1_3_1 = " ";
        likesbyUser1_3_2 = " ";
        comments1_3 = " ";
        description2_1 = " ";
        likesbyUser2_1_1 = " ";
        likesbyUser2_1_2 = " ";
        comments2_1 = " ";
        description2_2 = " ";
        likesbyUser2_2_1 = " ";
        likesbyUser2_2_2 = " ";
        comments2_2 = " ";
        description2_3 = " ";
        likesbyUser2_3_1 = " ";
        likesbyUser2_3_2 = " ";
        comments2_3 = " ";
        description3_1 = " ";
        likesbyUser3_1_1 = " ";
        likesbyUser3_1_2 = " ";
        comments3_1 = " ";
        description3_2 = " ";
        likesbyUser3_2_1 = " ";
        likesbyUser3_2_2 = " ";
        comments3_2 = " ";
        description3_3 = " ";
        likesbyUser3_3_1 = " ";
        likesbyUser3_3_2 = " ";
        comments3_3 = " ";
        description4_1 = " ";
        likesbyUser4_1_1 = " ";
        likesbyUser4_1_2 = " ";
        comments4_1 = " ";
        description4_2 = " ";
        likesbyUser4_2_1 = " ";
        likesbyUser4_2_2 = " ";
        comments4_2 = " ";
        description4_3 = " ";
        likesbyUser4_3_1 = " ";
        likesbyUser4_3_2 = " ";
        comments4_3 = " ";
        description5_1 = " ";
        likesbyUser5_1_1 = " ";
        likesbyUser5_1_2 = " ";
        comments5_1 = " ";
        description5_2 = " ";
        likesbyUser5_2_1 = " ";
        likesbyUser5_2_2 = " ";
        comments5_2 = " ";
        description5_3 = " ";
        likesbyUser5_3_1 = " ";
        likesbyUser5_3_1 = " ";
        comments5_3 = " ";
    }
 
    void ReadData(User* user, int index)
    {
        ifstream Ifile;
        Ifile.open("user1_posts.txt");
        if (!Ifile)
        {
            cout << "Error opening file";
        }
        else
        {

            getline(Ifile, description1_1);
            getline(Ifile, likesbyUser1_1_1);
            getline(Ifile, likesbyUser1_1_2);
            getline(Ifile, comments1_1);
            getline(Ifile, description1_2);
            getline(Ifile, likesbyUser1_2_1);
            getline(Ifile, likesbyUser1_2_2);
            getline(Ifile, comments1_2);
            getline(Ifile, description1_3);
            getline(Ifile, likesbyUser1_3_1);
            getline(Ifile, likesbyUser1_3_2);
            getline(Ifile, comments1_3);
            if (index == 0) {
                cout << "Posted by " << user[0].Fname << " " << user[0].Lname << "\n";
                cout << description1_1 << "\n";
                cout<<"Total likes on this post: "<<likes1_1;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser1_1_1;
                cout << "\t" << likesbyUser1_1_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments1_1 << " \n";
                cout<<comments;

                cout << "Posted by " << user[0].Fname << " " << user[0].Lname << "\n";
                cout << description1_2 << "\n";
                cout<<"Total likes on this post: "<<likes1_2;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser1_2_1;
                cout << "\t" << likesbyUser1_2_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments1_2 << " \n";
                cout<<comments;

                cout << "Posted by " << user[0].Fname << " " << user[0].Lname << "\n";
                cout << description1_3 << "\n";
                cout<<"Total likes on this post: "<<likes1_3;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser1_3_1;
                cout << "\t" << likesbyUser1_3_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments1_3 << " \n";
                cout<<comments;
                
            }

        }

        ifstream Iifile;
        Iifile.open("user2_post.txt");
        if (!Iifile)
        {
            cout << "Error opening file";
        }
        else
        {
            getline(Ifile, description2_1);
            //cout << description2_1 << endl;
            getline(Ifile, likesbyUser2_1_1);
            //cout << likesbyUser2_1_1 << endl;
            getline(Ifile, likesbyUser2_1_2);
            //cout << likesbyUser2_1_2 << endl;
            getline(Ifile, comments2_1);
            getline(Ifile, description2_2);
            getline(Ifile, likesbyUser2_2_1);
            getline(Ifile, likesbyUser2_2_2);
            getline(Ifile, comments2_2);
            getline(Ifile, description2_3);
            getline(Ifile, likesbyUser2_3_1);
            getline(Ifile, likesbyUser2_3_2);
            getline(Ifile, comments2_3);
            //cout << comments2_3;
            if (index == 1) {
                cout << "Posted by " << user[1].Fname << " " << user[1].Lname << "\n";
                cout << description2_1 << "\n";
                cout<<"Total likes on this post: "<<likes2_1;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser2_1_1;
                cout << "\t" << likesbyUser2_1_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments2_1 << " \n";
                cout<<comments;

                cout << "Posted by " << user[1].Fname << " " << user[1].Lname << "\n";
                cout << description2_2 << "\n";
                cout<<"Total likes on this post: "<<likes2_2;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser2_2_1;
                cout << "\t" << likesbyUser2_2_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments2_2 << " \n";
                cout<<comments;

                cout << "Posted by " << user[1].Fname << " " << user[1].Lname << "\n";
                cout << description2_3 << "\n";
                cout<<"Total likes on this post: "<<likes2_3;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser2_3_1;
                cout << "\t" << likesbyUser2_3_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments2_3 << "\n ";
                cout<<comments;
            }
        }
        ifstream file;
        file.open("user3_post.txt");
        if (!file)
        {
            cout << "Error opening file";
        }
        else
        {
            getline(Ifile, description3_1);
            //cout << description3_1 << endl;
            getline(Ifile, likesbyUser3_1_1);
            //cout << likesbyUser3_1_1 << endl;
            getline(Ifile, likesbyUser3_1_2);
            //cout << likesbyUser3_1_2 << endl;
            getline(Ifile, comments3_1);
            getline(Ifile, description3_2);
            getline(Ifile, likesbyUser3_2_1);
            getline(Ifile, likesbyUser3_2_2);
            getline(Ifile, comments3_2);
            getline(Ifile, description3_3);
            getline(Ifile, likesbyUser3_3_1);
            getline(Ifile, likesbyUser3_3_2);
            getline(Ifile, comments3_3);
            //cout << comments3_3;
            if (index == 2) {
                cout << "Posted by " << user[2].Fname << " " << user[2].Lname << "\n";
                cout << description3_1 << "\n";
                cout<<"Total likes on this post: "<<likes3_1;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser3_1_1;
                cout << "\t" << likesbyUser3_1_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments3_1 << " \n";
                cout<<comments;

                cout << "Posted by " << user[2].Fname << " " << user[2].Lname << "\n";
                cout << description3_2 << "\n";
                cout<<"Total likes on this post: "<<likes3_2;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser3_2_1;
                cout << "\t" << likesbyUser3_2_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments3_2 << " \n";
                cout<<comments;

                cout << "Posted by " << user[2].Fname << " " << user[2].Lname << "\n";
                cout << description3_3 << "\n";
                cout<<"Total likes on this post: "<<likes3_3;
                cout << "Liked by: \n";
                cout << "\t" << likesbyUser3_3_1;
                cout << "\t" << likesbyUser3_3_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments3_3 << " \n";
                cout<<comments;
            }
        }
        ifstream File;
        File.open("user4_post.txt");
        if (!File)
        {
            cout << "Error opening file";
        }
        else
        {
            getline(Ifile, description4_1);
            //cout << description4_1 << endl;
            getline(Ifile, likesbyUser4_1_1);
            //cout << likesbyUser4_1_1 << endl;
            getline(Ifile, likesbyUser4_1_2);
            //cout << likesbyUser4_1_2 << endl;
            getline(Ifile, comments4_1);
            getline(Ifile, description4_2);
            getline(Ifile, likesbyUser4_2_1);
            getline(Ifile, likesbyUser4_2_2);
            getline(Ifile, comments4_2);
            getline(Ifile, description4_3);
            getline(Ifile, likesbyUser4_3_1);
            getline(Ifile, likesbyUser4_3_2);
            getline(Ifile, comments4_3);
            //cout << comments4_3;
            if (index == 3) {
                cout << "Posted by " << user[3].Fname << " " << user[3].Lname << "\n";
                cout << description4_1 << "\n";
                cout<<"Total likes on this post: "<<likes4_1;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser4_1_1;
                cout << "\t" << likesbyUser4_1_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments4_1 << " \n";
                cout<<comments;

                cout << "Posted by " << user[3].Fname << " " << user[3].Lname << "\n";
                cout << description4_2 << "\n";
                cout<<"Total likes on this post: "<<likes4_2;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser4_2_1;
                cout << "\t" << likesbyUser4_2_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments4_2 << " \n";
                cout<<comments;

                cout << "Posted by " << user[3].Fname << " " << user[3].Lname << "\n";
                cout << description4_3 << "\n";
                cout<<"Total likes on this post: "<<likes4_3;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser4_3_1;
                cout << "\t" << likesbyUser4_3_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments4_3 << " \n";
                cout<<comments;
            }

        }
        ifstream Inpfile;
        Inpfile.open("user5_post.txt");
        if (!Inpfile)
        {
            cout << "Error opening file";
        }
        else
        {
            getline(Ifile, description5_1);
            //cout << description5_1 << endl;
            getline(Ifile, likesbyUser5_1_1);
            //cout << likesbyUser5_1_1 << endl;
            getline(Ifile, likesbyUser5_1_2);
            //cout << likesbyUser5_1_2 << endl;
            getline(Ifile, comments5_1);
            getline(Ifile, description5_2);
            getline(Ifile, likesbyUser5_2_1);
            getline(Ifile, likesbyUser5_2_2);
            getline(Ifile, comments5_2);
            getline(Ifile, description5_3);
            getline(Ifile, likesbyUser5_3_1);
            getline(Ifile, likesbyUser5_3_2);
            getline(Ifile, comments5_3);
            //cout << comments5_3;
            if (index == 4)
            {
                cout << "Posted by " << user[4].Fname << " " << user[4].Lname << "\n";
                cout << description5_1 << "\n";
                cout<<"Total likes on this post: "<<likes5_1;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser5_1_1;
                cout << "\t" << likesbyUser5_1_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments5_1 << " \n";
                cout<<comments;

                cout << "Posted by " << user[4].Fname << " " << user[4].Lname << "\n";
                cout << description5_2 << "\n";
                cout<<"Total likes on this post: "<<likes5_2;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser5_2_1;
                cout << "\t" << likesbyUser5_2_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments5_2 << " \n";
                cout<<comments;

                cout << "Posted by " << user[4].Fname << " " << user[4].Lname << "\n";
                cout << description5_3 << "\n";
                cout<<"Total likes on this post: "<<likes5_3;
                cout << "\nLiked by: \n";
                cout << "\t" << likesbyUser5_3_1;
                cout << "\t" << likesbyUser5_3_2;
                cout<<"\t"<<likes;
                cout << "\nComments: " << endl;
                cout << comments5_3 << " \n";
                cout<<comments;
            }


        
        }
    }
    ~Post() {}
};
void  viewLikesPost()
{
    int choice, postNo;
    
    cout<<"Enter which post you want to like.. \n";
    cout<< "user 1,2,3,4 or 5??";
    cin>>choice;
    cout<<"which post?? (1,2,3)\n";
    cin>>postNo;
    if (choice ==1)
    {
        if(postNo==1)
        {
            cout<<"Likes are: "<<likes1_1;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes1_1++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
                
            }

        }
        else if (postNo==2)
        {
            cout<<"Likes are: "<<likes1_2;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes1_2++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else
        {
            cout<<"Likes are: "<<likes1_3;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes1_3++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
    }
    else if (choice ==2)
    {
        if(postNo==1)
        {
            cout<<"Likes are: "<<likes2_1;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes2_1++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else if (postNo==2)
        {
            cout<<"Likes are: "<<likes2_2;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes2_2++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else
        {
            cout<<"Likes are: "<<likes2_3;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes2_3++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
    }
    else if (choice ==3)
    {
        if(postNo==1)
        {
            cout<<"Likes are: "<<likes3_1;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes3_1++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else if (postNo==2)
        {
            cout<<"Likes are: "<<likes3_2;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes3_2++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else
        {
            cout<<"Likes are: "<<likes3_3;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes3_3++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
    }
    else if (choice ==4)
    {
        if(postNo==1)
        {
            cout<<"Likes are: "<<likes4_1;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes4_1++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else if (postNo==2)
        {
            cout<<"Likes are: "<<likes4_2;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes4_2++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else
        {
            cout<<"Likes are: "<<likes4_3;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes4_3++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
    }
    else if (choice ==5)
    {
        if(postNo==1)
        {
            cout<<"Likes are: "<<likes5_1;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes5_1++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else if (postNo==2)
        {
            cout<<"Likes are: "<<likes5_2;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes5_2++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
        else
        {
            cout<<"Likes are: "<<likes5_3;
            cout<<"Wanna add a like..\n";
            char c;
            cin>>c;
            if (c=='Y'||c=='y')
            {
                likes5_3++;
                cout<<"Enter your name: "<<endl;
                cin>>likes;
            }

        }
    }

    

}
void addComment()
{
    int ch,p;
    cout<<"You want to add comment: "<<endl;
    cout<<"on which post you want to comment: "<<endl;
    cout<<"You want to comment on page(enter 1) or post(enter2)";
    cin>>ch;
    if (ch==1)
    {
        cout<<"Enter post (1,2,3):"<<endl;
        cin>>p;
        cout<<"okay! Enter comment: \n";
        cin>>comments;
    }



}

int main()
{
    ifstream inputFile("UserDetails.txt");
    if (!inputFile) {
        cout << "Error opening UserDetails.txt" << endl;
        return 1;
    }

    int Size = 5;
    User* users = new User[Size];
    ReadDataFromFile(inputFile, users, Size);
    inputFile.close();

    ifstream inFile("friends.txt");
    if (!inFile) {
        cout << "Error opening friends.txt" << endl;
        return 1;
    }
    SetFriends(inFile, users, Size);
    inFile.close();
    Post* post = new Post;
    SocialMediaApp social;
    User currentUser = social.SetCurrentUser(users);
    User* CUser = new User[Size];
    CUser = &currentUser;
    Page * pages=new Page[3];
    pages[0].setPage1();
    pages[1].setPage2();
    pages[2].setPage3();
    
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. View Home\n";
        cout << "2. Like a Post\n";
        cout << "3. View Likes of a Post\n";
        cout << "4. Comment on a Post\n";
        cout << "5. View a Post\n";
        cout << "6. See user's activity\n";
        cout << "7. View Friend List \n";
        cout << "8. View Page\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                social.viewHome(CUser);
                post->ReadData(CUser, counts);
                break;
            case 2:
                viewLikesPost();
                break;
            case 3:
                
                viewLikesPost();

                break;
            case 4:
                addComment();
                break;
            case 5:
                post->ReadData(CUser,counts);
                break;
            case 6:
                CUser->setActivity();
                break;
            case 7:
                viewFriendsList(CUser);
                break;
            case 8:
                int x;
                cout<<"Which page you want to view? ";
                cout<<"Enter 1, if you want to see food fusion..\n";
                cout<<"Enter 2, if you want to see espn cricinfo..\n";
                cout<<"Enter 3, if you want to see bbc news..\n";
                cin>>x;
                //int i=0;
                
                while (true)
                {
                    if (x==1)
                    {
                        pages[0].viewPage();
                        break;
                    }
                    else if(x==2)
                    {
                        pages[1].viewPage(); 
                        break;  
                    }
                    else if (x==3)
                    {
                        pages[2].viewPage();
                        break;
                    }
                    
                }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
    
    delete[] users;
    delete[] CUser;
    delete post;
    delete[] pages;

    return 0;
}
