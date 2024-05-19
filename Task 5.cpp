#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Library{
	private:
	    char title[50];
	    char author[50];
	    int isbn;
	    bool checkedOut;
	public:
	    Library(){
	        title[0] = '\0';
	        author[0] = '\0';
	        isbn = 0;
	        checkedOut = false;
	    }
	
	    void getbookdat(){
	        cin.ignore();
	        cout << "Enter the book author: ";
	        cin.getline(author, 50);
	        cout << "Enter the book title: ";
	        cin.getline(title, 50);
	        cout << "Enter the ISBN number: ";
	        cin >> isbn;
	        checkedOut = false;
	    }
	    void showdata(){
	        cout << "Author: " << author << endl;
	        cout << "Title: " << title << endl;
	        cout << "ISBN: " << isbn << endl;
	        cout << "Checked Out: " << (checkedOut ? "Yes" : "No") << endl;
	    }
	    void Addbook();
	    void displaybook();
	    void searchbook();
	    void deletedata();
	    void checkoutBook();
	    void returnBook();
};
void Library::Addbook(){
    ofstream fout;
    Library L;
    L.getbookdat();
    fout.open("Library.dat", ios::app | ios::binary);
    if (fout.is_open()) {
        fout.write(reinterpret_cast<char*>(&L), sizeof(L));
        fout.close();
        cout << "Book added successfully." << endl;
    } else {
        cout << "Error opening file for writing." << endl;
    }
}
void Library::displaybook(){
    ifstream fin;
    fin.open("Library.dat", ios::in | ios::binary);
    if (!fin) {
        cout << "File not found." << endl;
    } else {
        while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
            showdata();
            cout << "---------------------" << endl;
        }
        fin.close();
    }
}
void Library::searchbook(){
    int ch;
    while (true){
        cout << "Search the book through Author, Title, or ISBN number." << endl;
        cout << "1 for Author\n2 for Title\n3 for ISBN number\n4 for Exit\n";
        cin >> ch;
        ifstream fin;
        char search[50];
        int isb;
        bool found = false;
        switch (ch){
            case 1:
                fin.open("Library.dat", ios::in | ios::binary);
                if (!fin){
                    cout << "File not found." << endl;
                } 
				else{
                    cout << "Enter the author to search: ";
                    cin.ignore();
                    cin.getline(search, 50);
                    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
                        if (strcmp(author, search) == 0){
                            showdata();
                            cout << "---------------------" << endl;
                            found = true;
                        }
                    }
                    if (!found){
                        cout << "No book found by author: " << search << endl;
                    }
                    fin.close();
                }
                break;
            case 2:
                fin.open("Library.dat", ios::in | ios::binary);
                if (!fin){
                    cout << "File not found." << endl;
                } 
				else{
                    cout << "Enter the title to search: ";
                    cin.ignore();
                    cin.getline(search, 50);
                    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
                        if (strcmp(title, search) == 0){
                            showdata();
                            cout << "---------------------" << endl;
                            found = true;
                        }
                    }
                    if (!found){
                        cout<<"No book found with title: "<<search<< endl;
                    }
                    fin.close();
                }
                break;
            case 3:
                fin.open("Library.dat", ios::in | ios::binary);
                if (!fin) {
                    cout << "File not found." << endl;
                } else {
                    cout << "Enter the ISBN number to search: ";
                    cin >> isb;
                    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
                        if (isbn == isb){
                            showdata();
                            cout << "---------------------" << endl;
                            found = true;
                        }
                    }
                    if (!found){
                        cout << "No book found with ISBN: " << isb << endl;
                    }
                    fin.close();
                }
                break;

            case 4:
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
void Library::deletedata(){
    int ch;
    while (true) {
        cout << "Delete the book through Author, Title, or ISBN number." << endl;
        cout << "1 for Author\n2 for Title\n3 for ISBN number\n4 for Exit\n";
        cin >> ch;
        ifstream fin;
        ofstream fout;
        char searchString[50];
        int searchISBN;
        bool found = false;

        switch (ch){
            case 1:
                fin.open("Library.dat", ios::in | ios::binary);
                if (!fin){
                    cout << "File not found." << endl;
                } 
				else{
                    fout.open("temp.dat", ios::out | ios::binary);
                    cout << "Enter the author to delete: ";
                    cin.ignore();
                    cin.getline(searchString, 50);
                    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
                        if (strcmp(author, searchString) != 0){
                            fout.write(reinterpret_cast<char*>(this), sizeof(*this));
                        } 
						else{
                            found = true;
                        }
                    }
                    fin.close();
                    fout.close();
                    remove("Library.dat");
                    rename("temp.dat", "Library.dat");
                    if (found) {
                        cout << "Book deleted successfully." << endl;
                    } 
					else{
                        cout << "No book found by author: " << searchString << endl;
                    }
                }
                break;

            case 2:
                fin.open("Library.dat", ios::in | ios::binary);
                if (!fin){
                    cout << "File not found." << endl;
                } 
				else{
                    fout.open("temp.dat", ios::out | ios::binary);
                    cout << "Enter the title to delete: ";
                    cin.ignore();
                    cin.getline(searchString, 50);
                    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
                        if (strcmp(title, searchString) != 0) {
                            fout.write(reinterpret_cast<char*>(this), sizeof(*this));
                        } 
						else{
                            found = true;
                        }
                    }
                    fin.close();
                    fout.close();
                    remove("Library.dat");
                    rename("temp.dat", "Library.dat");
                    if (found){
                        cout << "Book deleted successfully." << endl;
                    } 
					else{
                        cout << "No book found with title: " << searchString << endl;
                    }
                }
                break;

            case 3:
                fin.open("Library.dat", ios::in | ios::binary);
                if (!fin){
                    cout << "File not found." << endl;
                } 
				else{
                    fout.open("temp.dat", ios::out | ios::binary);
                    cout << "Enter the ISBN number to delete: ";
                    cin >> searchISBN;
                    while (fin.read(reinterpret_cast<char*>(this), sizeof(*this))){
                        if (isbn != searchISBN) {
                            fout.write(reinterpret_cast<char*>(this), sizeof(*this));
                        } 
						else{
                            found = true;
                        }
                    }
                    fin.close();
                    fout.close();
                    remove("Library.dat");
                    rename("temp.dat", "Library.dat");
                    if (found) {
                        cout << "Book deleted successfully." << endl;
                    }
					else{
                        cout << "No book found with ISBN: " << searchISBN << endl;
                    }
                }
                break;

            case 4:
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
void Library::checkoutBook(){
    int searchISBN;
    cout << "Enter the ISBN number of the book to check out: ";
    cin >> searchISBN;
    fstream file("Library.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File not found." << endl;
        return;
    }
    bool found = false;
    while (file.read(reinterpret_cast<char*>(this), sizeof(*this))){
        if (isbn == searchISBN){
            if (!checkedOut){
                checkedOut = true;
                int pos = -static_cast<int>(sizeof(*this));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char*>(this), sizeof(*this));
                cout << "Book checked out successfully." << endl;
            } 
			else{
                cout << "Book is already checked out." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found){
        cout << "No book found with ISBN: "<< searchISBN << endl;
    }
    file.close();
}
void Library::returnBook(){
    int searchISBN;
    cout << "Enter the ISBN number of the book to return: ";
    cin >> searchISBN;
    fstream file("Library.dat", ios::in | ios::out | ios::binary);
    if (!file){
        cout << "File not found." << endl;
        return;
    }
    bool found = false;
    while (file.read(reinterpret_cast<char*>(this), sizeof(*this))){
        if (isbn == searchISBN){
            if (checkedOut){
                checkedOut = false;
                int pos = -static_cast<int>(sizeof(*this));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char*>(this), sizeof(*this));
                cout << "Book returned successfully." << endl;
            } else {
                cout << "Book was not checked out." << endl;
            }
            found = true;
            break;
        }
    }
    if (!found){
        cout << "No book found with ISBN: " << searchISBN << endl;
    }
    file.close();
}
int main(){
    Library b1;
    int ch;
    while (true){
        cout << "\n1. Insert data \n2. Show data \n3. Search data \n4. Delete data\n5. Check out book\n6. Return book\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch){
            case 1:
                b1.Addbook();
                break;
            case 2:
                b1.displaybook();
                break;
            case 3:
                cout << "Search: " << endl;
                b1.searchbook();
                break;
            case 4:
                b1.deletedata();
                break;
            case 5:
                b1.checkoutBook();
                break;
            case 6:
                b1.returnBook();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
