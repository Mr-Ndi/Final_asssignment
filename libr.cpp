# include <iostream>
# include<vector>
using namespace std;
class Book;
class patron;

class Book{
    private:
        string ISBN;
        string Title;
        string Author;
        int Copdate;
        bool check_out;
        
    
    public:
        enum Genre { fiction, nonfiction ,periodical, biography,children};
        //creating constructors
        
        //1.parameterized constructor
        Book(string one, string two, string three, int four, string five, bool six)
        : ISBN(one), Title(two), Author(three), Copdate(four), check_out(six){}

        // //2.defaul constructor
        // Book() : ISBN(""), Title(""), Author(""), Copdate(0){}

        // //3.copy constructor
        // //In this context, other is simply a variable name that represents the object you're copying from.
        // Book(const Book&, other){
        //     ISBN = other.ISBN;
        //     Title = other.Title;
        //     Author = other.Author;
        //     Copdate = other.Copdate;
        // }
        
        //getter functions
        const string getISBN()const {return ISBN;}
        const string getTitle()const {return Title;}
        const string getAuthor()const {return Author;}
        const int copyrihtdate()const {return Copdate;}

         // Function to check out a book
        void chechout() {check_out = true;}

        // function to check in a book
        void checkin() {check_out = false;}

        // overload the operator == for ISBN comparison

        //other is not a keyword or a specific C++ construct. 
        //It's just a parameter name chosen to indicate that it's another object you're comparing to the current object

        bool operator==(const Book& other)const {return ISBN == other.ISBN;}

         // overload the operator != for ISBN comparison

        bool operator !=(const Book& other)const {return !(ISBN == other.ISBN);}

        // Overload the << operator to display book information
        friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title: " << book.Title << "\nAuthor: " << book.Author << "\nISBN: " << book.ISBN << endl;
        return os;
        }
};

    class patron{
        private:
            string uname;
            string cnumber;
            int owfees;
           
        public:
            //getter functions
            const string user_name()const {return uname;}
            const string card_number()const {return cnumber;}
            const int owned_fees()const {return owfees;}

            //parameterised constructor
            patron(string un, string cn, int owf)
            : uname(un), cnumber(cn), owfees(owf){}

            // Function to check if the user owes fees
            bool oweesfees()const {return owfees > 0;}

            // Setter function for the fees

            void set_fees(int new_fee){ owfees = new_fee; }
    };
    class transaction{
        private:
        Book *book;
        patron *pat;
        enum Activity {CHECH_OUT, CHECK_IN};

        // Book Book; instances
        // patron Patron; instances

        
        Activity activity;
        string date;
        public:
        // Constructor
        transaction(Book *b, patron* p, Activity act, const string& dt)
         : book(b), pat(p), activity(act), date(dt) {}

        //getter functions to this class
        const Book * getBook()const {return book;}
        const patron * getPatron()const {return pat;}
        const Activity getactivity()const {return activity;}
        const string getdate()const {return date;}
    };
    class Library{
        private:
            vector<Book> books;
            vector<patron>patrona;
            vector<transaction>transactions;
        public:
        // adding book to alibrary
        void adding(const Book& newbook){books.push_back(newbook);}
        
         void checkOutBook(const Book& book, const patron& patron, const string& date) {
             // Check if the book and patron are in the library

            bool bookInLibrary = false;
            bool patronInLibrary = false;

             for (const Book& b : books) {
            if (b == book) {
                bookInLibrary = true;
                break;
            }
        }
        for (const patron& p : patrona) {
            if (p == patron) {
                patronInLibrary = true;
                break;
            }
        }
        if (!bookInLibrary || !patronInLibrary) {
            cout << "Error: Book or patron not found in the library." << endl;
            return;
        }
        }
    };

    
int main()
{
    //create library function and test their functionality
    Book book_1("1234", "Advanced prog in cpp", "Mr Theonest",01052023, "nonfiction", false);
    //Book book_2;
    //copy constructor
    
    Book book_3 = book_1;
    
    return (0);
}