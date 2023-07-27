#include<iostream>
#include<fstream>
using namespace std;

class shopping{
    private:
        int product_code;
        float price;
        float discount;
        string product_name;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu(){
    int choice;
    string email;
    string password;
    while(true){
        cout<<"________SUPERMARKET MAIN MENU________";
        cout<<endl;
        cout<<"___1) Administrator ___";
        cout<<endl;
        cout<<"___2) Buyer___";
        cout<<endl;
        cout<<"___3) Exit___";
        cout<<endl;
        cout<<"=== Please Select ===";

        cin>>choice;

        switch(choice){
            case 1 :
            {
                cout<<"___ Please Login ___";
                cout<<"___ Enter E-mail ___";
                cin>>email;
                cout<<"___ Password ___";
                cin>>password;

                if(email =="sehajkakroo13@gmail.com" && password == "sehaj@2002"){
                    administrator();
                }
                else{
                    cout<<"Invalid E-mail/Password";
                }
                break;
            }
            case 2:
            {
                buyer();
            }
            case 3:
            {
                exit(0);
            }
            default :
            {
                cout<<"___ Please Select From The Given Option ___";
            }   
        }
    }
}

void shopping :: administrator(){
    int choice;
    while(true){
        cout<<"________ Administrator Menu ________";
        cout<<"________ 1) Add the product";
        cout<<endl;
        cout<<"________ 2) Modify the product";
        cout<<endl;
        cout<<"________ 3) Delete product";
        cout<<endl;
        cout<<"________ 4) Back to Main Menu";
        cout<<endl;
        cout<<endl;

        cout<<"=== Please Enter Your Choice ===";
        cin>>choice;

        switch (choice){
            case 1:{
                add();
                break;
            }

            case 2:{
                edit();
                break;
            }

            case 3:{
                rem();
                break;
            }

            case 4:{
                menu();
                break;
            }
            default:{
                cout<<"Invalid Choice";
            }
        }
    }
}

void shopping :: buyer(){
    int choice;
    while(true){
        cout<<"___ Buyer ___";
        cout<<endl;
        cout<<" 1) buy product ";
        cout<<endl;
        cout<<" 2) go back ";
        cout<<endl;
        cout<<"=== Enter your choice ===";
        cin>>choice;

        switch(choice){
            case 1: {
                receipt();
                break;
            }
            case 2:{
                menu();
                break;
            }
            default:{
                cout<<"Invalid choice";
            }
        }
    }

}

void shopping :: add(){
    n:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string m;

    cout<<"\n\n__ Add new product __";
    cout<<endl;
    cout<<"___ product code of the product ___ ";
    cout<<endl;
    cin>>product_code;
    cout<<endl;
    cout<<"___ Name of the product ___";
    cout<<endl;
    cin>>product_name;
    cout<<endl;
    cout<<"___ price of the product ___";
    cout<<endl;
    cin>>price;
    cout<<endl;
    cout<<"___ Discount of the product ___";
    cout<<endl;
    cin>>discount;
    cout<<endl;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<endl;
        data.close();
    }
    else{
        data>>c>>m>>p>>d;

        while(!data.eof()){ // loop make sure to check every content of file
            if(c == product_code){
                token++;  // if duplicacy token is incremented
            }
            data>>c>>m>>p>>d;

        }
        data.close();
    }
    if(token == 1){
        goto n;
    }
    else{
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<endl;
        data.close();
    }
    cout<<"\n\n  record inserted !"<<endl;
}

void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string m;
    
    cout<<"\n\n\n Modify the record"<<endl;
    cout<<"\n\n\n Product code: "<<endl;
    cin>>pkey;

    data.open("database.txt", ios:: in);
    if(!data){
        cout<<"\n\n File doesn't exist! "<<endl;
    }
    else{
        data1.open("database1.txt", ios::app| ios:: out);
        data>>product_code>>product_name>>price>>discount;

        while (!data.eof())
        {
            if(pkey == product_code){
                cout<<"\n\n\n Product New code: "<<endl;
                cin>>c;
                cout<<"\n\n\n Name of the product: "<<endl;
                cin>>m;
                cout<<"\n\n\n Price: "<<endl;
                cin>>p;
                cout<<"\n\n\n Discount: "<<endl;
                cin>>d;
                data1<<" "<<c<<" "<<m<<" "<<p<<" "<<d<<endl;
                cout<<"\n\n\n Record edited! "<<endl;
                token++;
            }
            else{
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<endl;

            }
            data>>product_code>>product_name>>price>>discount;
        }
        data.close();
        data1.close();
        
        
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0){
            cout<<"\n\n Record not found! ";
        }
    }

}

void shopping:: rem(){
    fstream data, data1;
    int pkey;
    int token = 0;
    cout<<"\n\n Delete Product";
    cout<<"\n\n Product code";
    cin>>pkey;
    data.open("database.txt", ios:: in);
    if(!data){
        cout<<"file doesn't exist! ";

    }
    else{
        data1.open("database1.txt", ios::app |ios::out );
        data>>product_code>>product_name>>price>>discount;
        while (!data.eof())
        {
            if(product_code == pkey){
                cout<<"\n\n product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<endl;

            }
            data>>product_code>>product_name>>price>>discount;
        }
        data.close();
        data1.close();
        
        
        remove("database.txt");
        rename("database1.txt", "database.txt");
        
        if(token == 0){
            cout<<"\n\n\n Record not found";
        }
    }
}


void shopping :: list(){
    fstream data;
    data.open("database.txt", ios:: in);
    cout<<"\n\n\n _____ ProNo\t\tName\t\tPrice _____";
    cout<<endl;
    data>>product_code>>product_name>>price>>discount;
    while (!data.eof()){
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<price<<"\t\t"<<endl;
        data>>product_code>>product_name>>price>>discount;

    }
    data.close();
}

void shopping :: receipt(){
    
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\n\t\t\t\t RECEIPT  "<<endl;
    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n\n\n ______ Please Place the Order _____ ";
        cout<<endl;
        cout<<endl;
        do{
            n:
            cout<<"\n\n Enter product code: ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity: ";
            cin>>arrq[c];
            for(int i = 0; i<c; i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\n\n Duplicate product code. Please try again";
                    goto n;
                }
                
                
            } 
            c++;
            cout<<"\n\n Do you want to buy more, press y for yes else no";
            cin>>choice;
        }
        while(choice == 'y');
        cout<<"\n\n\t\t ____ Receipt ___";
        cout<<"\n Product No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";
        for(int i = 0; i<c; i++){
            data.open("database.txt", ios::in);
            data>>product_code>>product_name>>price>>dis;
            while (!data.eof()){
                if(product_code == arrc[i]){
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;
                    cout<<"\n"<<product_code<<"\t\t" <<product_name<<"\t\t" <<arrq[i]<<"\t\t "<<price<<"\t\t"<< amount<<"\t\t "<<dis<<endl;;
                }
                data>>product_code>>product_name>>price>>dis;
            }
        
        }
        data.close();

    }
    cout<<"\n\n _____ Total Amount: "<<total;

}

int main(){
    shopping s;
    s.menu();
}