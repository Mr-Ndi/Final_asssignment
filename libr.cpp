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
        os << "\n\nTitle: " << book.Title << "\nAuthor: " << book.Author << "\nISBN: " << book.ISBN << endl;
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
            
            //overloading == operator in patron 
            bool operator==(const patron& other) const {
            return uname == other.uname && cnumber == other.cnumber;
            }

            // Overload the << operator to display patron information
            friend ostream& operator<<(ostream& os, const patron& pt) {
            os << "\n\nUser Name: " << pt.uname << "\nCard Number: " << pt.cnumber << "\nOwed Fees: " << pt.owfees << endl;
            return os;
            }
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
        
        // Book Book; instances
        // patron Patron; instances

        public:
        string date;
        enum Activity {CHECH_OUT, CHECK_IN};
        Activity activity;

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
            vector<patron> patrons;
            vector<transaction> transactions;
        public:
        // adding book to alibrary
        void adding(const Book& newbook){books.push_back(newbook);}
        // Add a patron to the library
        void addPatron(const patron& newPatron) { patrons.push_back(newPatron);}
        
        // Return a vector of patrons who owe fees
        vector<patron> getPatronsWithFees() {
        vector<patron> patronsWithFees;
            for (const patron& pt : patrons) {
                if (pt.oweesfees()) {
                    patronsWithFees.push_back(pt);
                }
        }
        return patronsWithFees;
        }

        // Record a transaction
        void recordTransaction(const transaction& trans) {
        transactions.push_back(trans);
    }
    void checkOutBook(Book& book, patron& patrones, string& date) {
    
        // Check if the book and patron are in the library

    bool bookInLibrary = false;
    bool patronInLibrary = false;

    for (const Book& b : books) {
        if (b == book) {
            bookInLibrary = true;
            break;
        }
    }
    for (const patron& pt : patrons) {
        if (pt == patrones) {
            patronInLibrary = true;
            break;
        }
    }
    if (!bookInLibrary || !patronInLibrary) {
        cout << "Error: Book or patron not found in the library." << endl;
        return;
    }
    if (patrones.oweesfees()) {
        cout << "Error: Patron owes fees and cannot check out a book." << endl;
        return;
    }

    // Create a transaction and add it to the transactions vector
    transaction trans(const_cast<Book*>(&book), const_cast<patron*>(&patrones), transaction::CHECH_OUT, date);
    transactions.push_back(trans);

    book.chechout();

    cout << "Book checked out successfully." << endl;
}

    };

    
int main() {
    // Create a library
    Library library;

    // Create some books
    Book book1("1234", "Advanced programming in cpp", "Mr Theonest", 1052023, "nonfiction", false);
    Book book2("5678", "Introduction to Algorithms", "Mr Iddi Kajeguhakwa", 20211201, "nonfiction", false);

    // Create some patrons
    patron patron1("Joseph Muneza", "222015797", 80);//u can modfy the 3rd parameter to see the change in output
    patron patron2("Kelvin prince", "222006232", 0);//u can modfy the 3rd parameter to see the change in output

    // Add books to the library
    library.adding(book1);
    library.adding(book2);

    // Add patrons to the library
    library.addPatron(patron1);
    library.addPatron(patron2);

    // Check out a book
    string checkoutDate = "2023-08-24";
    library.checkOutBook(book1, patron1, checkoutDate);

    // Print book and patron information
    cout<< book1 << endl;
    cout<< patron1 << endl;

    // Print patrons who owe fees
    vector<patron> patronsWithFees = library.getPatronsWithFees();
    cout << "Patrons who owe fees:" << endl;
    for (const patron& pt : patronsWithFees) {
        cout << pt.user_name() << endl;
    }

    return 0;
}