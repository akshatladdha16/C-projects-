#include<bits/stdc++.h>
using namespace std;

class Book{//as basic unit in this whole managemnent systrem is book to having book as our class and operations as its member class
private:
	//member types : kept in private so no one can change these names assigned
    char *author,*title,*publisher;//pointers assigned 
    float *price;
    int *stock;
public:
    Book(){//constructor
        author= new char[20];
        title=new char[20];
        publisher=new char[20];
        price= new float;
        stock=new int;// how many of those book available 
    }
    //member functions
    void feedData();// used to feed data
    void editData();// edit details of any book
    void showData();// used to display
    int  search(char[],char[]); // searcch for any particular entity in system
    void buyBook();//  to buy book and check stock

};

void Book::feedData(){ //member class 1
    cin.ignore();// so that there's no buffer in taking input and input goes at desired place only
    cout<<"\nEnter Author Name: ";    cin.getline(author,20);//using getline so that it won't stop at space
    cout<<"Enter Title Name: ";       cin.getline(title,20);
    cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
    cout<<"Enter Price: ";            cin>>*price;
    cout<<"Enter Stock: ";            cin>>*stock;
}

void Book::editData()	{

    cout<<"\nEnter Author Name: ";    cin.getline(author,20);
    cout<<"Enter Title Name: ";       cin.getline(title,20);
    cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
    cout<<"Enter Price: ";            cin>>*price;
    cout<<"Enter Stock: ";            cin>>*stock;

}

void Book::showData()	{
    cout<<"\nAuthor Name: "<<author;
    cout<<"\nTitle Name: "<<title;
    cout<<"\nPublisher Name: "<<publisher;
    cout<<"\nPrice: "<<*price;
    cout<<"\nStock: "<<*stock;

}

int Book::search(char tbuy[20],char abuy[20] )	{
    if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
        return 1;
    else return 0;

}
void Book::buyBook()	{
    int count;//number of books buyer wants
    cout<<"\nEnter Number Of Books to buy: ";
    cin>>count;
    if(count<=*stock)	{
      *stock=*stock-count;
      cout<<"\nBooks Bought Successfully";
      cout<<"\nAmount: Rs. "<<(*price)*count;
    }
    else
        cout<<"\nRequired Copies not in Stock";
}
int main()	{
    Book *book[20];
    int count=0, choice, it;
    char titleBuy[20], authorBuy[20];
    while(true)	{
        cout<<"\n\n Book Store Management System"
            <<"\n-----------------------------"
            <<"\n1. Entry of New Book"
            <<"\n2. Buy Book"
            <<"\n3. Search For Book"
            <<"\n4. Edit Details Of Book"
            <<"\n5. Exit"
            <<"\n\nEnter your Choice: ";
        cin>>choice;
        // using switch case as we have multiple options to select from
        switch(choice)	{
            case 1:	book[count] = new Book;
                book[count]->feedData();
                count++;
                break;

            case 2:
                cin.ignore();
                cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
                cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);
                for(it=0;it<count;it++)	{
                    if(book[it]->search(titleBuy,authorBuy))	{
                        book[it]->buyBook();
                        break;
                    }
                }
                if(it==count)
                    cout<<"\nThis Book is Not in Stock";

                break;

            case 3: cin.ignore();
                cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
                cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);

                for(it=0;it<count;it++)	{
                    if(book[it]->search(titleBuy,authorBuy)){
                        cout<<"\nBook Found Successfully";
                        book[it]->showData();
                        break;
                    }
                }
                if(it==count)
                    cout<<"\nThis Book is Not in Stock";
                break;

            case 4: cin.ignore();
                cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
                cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);

                for(it=0;it<count;it++)	{
                    if(book[it]->search(titleBuy,authorBuy))	{
                        cout<<"\nBook Found Successfully";
                        book[it]->editData();
                        break;
                    }
                }
                if(it==count)
                    cout<<"\nThis Book is Not in Stock";
                break;

            case 5:
            	cout<<"Thank you for using book store management system";
                exit(0);

            default:
                cout<<"\nInvalid Choice Entered";
                break;

        }
    }
}

